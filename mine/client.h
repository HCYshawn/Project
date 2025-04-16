#pragma once
#include "class.h"

class Client
{
private:
    Chessinitial *chess_mine;
    Chessinitial *chess_show;
    int _row;
    int _col;
    int _mine;
    int _win;
    int _tab;

public:
    Client(int row = ROW1, int col = COL1, int mine = GAMEMINE1, int win = 0, int tab = 0)
        : _row(row), _col(col), _mine(mine), _win(win), _tab(tab)
    {
        Chessinitial_Factory *minefactory = new MineFactory();
        Chessinitial_Factory *showfactory = new ShowFactory();
        chess_mine = minefactory->create(_row + 2, _col + 2, MINE);
        chess_show = showfactory->create(_row, _col, SHOW);

        if (chess_mine == nullptr || chess_show == nullptr)
        {
            throw std::runtime_error("棋盘初始化失败");
        }
    }

    ~Client()
    {
        delete chess_mine;
        delete chess_show;
    }

    void print_game()
    {
        // 打印边框上
        print_upperborder(_col);

        // 打印行号上
        print_col_numbers(_col);

        // 打印棋盘边框上
        print_chessborder(_col);

        // 棋盘主体
        for (int i = 0; i < _row; ++i)
        { // 遍历行数
            // 行号右对齐
            printf("||%2d|", i + 1);

            // 棋盘内容
            chess_show->print_row(i);

            // 行号左对齐
            printf("|%-2d||\n", i + 1);
        }

        // 打印棋盘边框下
        print_chessborder(_col);

        // 打印行号下
        print_col_numbers(_col);

        // 打印雷数及标注说明
        print_mine(_col, (_mine - _tab));

        // 打印边框下
        print_lowerborder(_col);
    }

    void Arrangemine(int x, int y)
    {
        auto &mine_chess = chess_mine->GetChess();
        std::vector<std::pair<int, int>> forbidden;
        std::vector<std::pair<int, int>> available;

        // 生成安全区坐标
        const int min_x = std::max(1, x - 1);
        const int max_x = std::min(_row, x + 1);
        const int min_y = std::max(1, y - 1);
        const int max_y = std::min(_col, y + 1);

        for (int i = min_x; i <= max_x; ++i)
            for (int j = min_y; j <= max_y; ++j)
                forbidden.push_back(std::make_pair(i, j));

        // 构建候选池
        for (int i = 1; i <= _row; ++i)
        {
            for (int j = 1; j <= _col; ++j)
            {
                if (std::find(forbidden.begin(), forbidden.end(),
                              std::make_pair(i, j)) == forbidden.end())
                {
                    available.push_back(std::make_pair(i, j));
                }
            }
        }

        // C++11随机引擎洗牌
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(available.begin(), available.end(), g);

        // 布雷并校验容量
        if (_mine > available.size())
            throw std::runtime_error("雷数超过安全区容量");

        for (int k = 0; k < _mine; ++k)
        {
            const std::pair<int, int> &pos = available[k];
            mine_chess[pos.first][pos.second] = '1';
        }
    }

    int Retmine(int x, int y)
    {
        auto &mine_chess = chess_mine->GetChess();
        int ret = 0;
        const int max_row = _row + 1; // 扩展后的雷棋盘行数
        const int max_col = _col + 1; // 扩展后的雷棋盘列数
        for (int i = std::max(1, x - 1); i <= std::min(max_row, x + 1); ++i)
        {
            for (int j = std::max(1, y - 1); j <= std::min(max_col, y + 1); ++j)
            {
                if (i == x && j == y)
                    continue;
                ret += (mine_chess[i][j] - '0');
            }
        }
        return ret;
    }

    void Install(int x, int y)
    {
        if (x < 1 || x > _row || y < 1 || y > _col)
            return;

        auto &show_chess = chess_show->GetChess();
        if (show_chess[x - 1][y - 1] != '#')
            return;

        int mines = Retmine(x, y);
        if (mines > 0)
        {
            show_chess[x - 1][y - 1] = mines + '0';
            _win++;
        }
        else
        {
            show_chess[x - 1][y - 1] = ' ';
            _win++;
            // 八方向递归展开
            const int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
            for (int i = 0; i < 8; ++i)
            {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                if (nx >= 1 && nx <= _row && ny >= 1 && ny <= _col)
                {
                    if (show_chess[nx - 1][ny - 1] == '#')
                    {
                        // 仅处理未展开格子
                        Install(nx, ny);
                    }
                }
            }
        }
    }

    void Tab()
    {
        int x = 1;
        int y = 1;
        int cin_x = 0;
        int cin_y = 0;
        auto &mine_chess = chess_mine->GetChess();
        auto &show_chess = chess_show->GetChess();
        while (1)
        {
            printf("Tab(x, y): ");
            std::cin >> cin_x >> cin_y;
            cin_x -= 1;
            cin_y -= 1;
            if ((cin_x >= 0 && cin_x < _row) && (cin_y >= 0 && cin_y < _col))
            {
                show_chess[cin_x][cin_y] = '!';
                _tab++;
            }
            else if (cin_x == -1 && cin_y == -1)
            {
                break;
            }
            else if (cin_x == -1 && cin_y == 0)
            {
                show_chess[cin_x][cin_y] = '#';
            }
            else
            {
                printf("error,please re-enter! \n");
                continue;
            }
        }
    }

    void AutoMarkStrict()
    {
        auto &show = chess_show->GetChess();
        auto &mine = chess_mine->GetChess();

        for (int i = 0; i < _row; ++i)
        {
            for (int j = 0; j < _col; ++j)
            {
                if (show[i][j] < '1' || show[i][j] > '8')
                    continue;

                int current = show[i][j] - '0';
                int marked = 0, unopened = 0;
                // 统计有效标记
                for (int dx = -1; dx <= 1; ++dx)
                {
                    for (int dy = -1; dy <= 1; ++dy)
                    {
                        int x = i + 1 + dx, y = j + 1 + dy;
                        if (x < 1 || x > _row || y < 1 || y > _col)
                            continue;

                        if (show[x - 1][y - 1] == '!')
                        {
                            if (mine[x][y] == '1')
                                marked++;
                        }
                        else if (show[x - 1][y - 1] == '#')
                        {
                            unopened++;
                        }
                    }
                }
                // 自动标记条件
                if (current - marked == unopened)
                {
                    for (int dx = -1; dx <= 1; ++dx)
                    {
                        for (int dy = -1; dy <= 1; ++dy)
                        {
                            int x = i + 1 + dx, y = j + 1 + dy;
                            if (x < 1 || x > _row || y < 1 || y > _col)
                                continue;

                            if (show[x - 1][y - 1] == '#' && mine[x][y] == '1')
                            {
                                show[x - 1][y - 1] = '!';
                                _tab++;
                            }
                        }
                    }
                }
            }
        }
    }

    void ExpandAround(int x, int y)
    {
        auto &show = chess_show->GetChess();

        // 有效性检查
        if (show[x - 1][y - 1] < '1' || show[x - 1][y - 1] > '8')
            return;

        // 标记统计
        int marked = 0;
        for (int dx = -1; dx <= 1; ++dx)
        {
            for (int dy = -1; dy <= 1; ++dy)
            {
                int nx = x + dx, ny = y + dy;
                if (nx < 1 || nx > _row || ny < 1 || ny > _col)
                    continue;
                if (show[nx - 1][ny - 1] == '!')
                    marked++;
            }
        }

        // 展开条件判断
        if (marked == (show[x - 1][y - 1] - '0'))
        {
            for (int dx = -1; dx <= 1; ++dx)
            {
                for (int dy = -1; dy <= 1; ++dy)
                {
                    int nx = x + dx, ny = y + dy;
                    if (nx < 1 || nx > _row || ny < 1 || ny > _col)
                        continue;
                    if (show[nx - 1][ny - 1] == '#')
                    {
                        Install(nx, ny);
                    }
                }
            }
        }
    }

    void Play()
    {
        int x = 0;
        int y = 0;
        auto &show_chess = chess_show->GetChess();
        auto &mine_chess = chess_mine->GetChess();
        while (_win < ((_row * _col) - _mine))
        {
            if ((_win == 0))
                print_game();
            std::cout << "(x, y): ";
            std::cin >> x >> y;
            if ((_win == 0))
            {
                Arrangemine(x, y);
            }
            if ((x >= 1 && x <= _row) && (y >= 1 && y <= _col))
            {
                if (mine_chess[x][y] == '1')
                {
                    std::cout << " game over " << std::endl;
                    break;
                }
                else
                {
                    if (show_chess[x - 1][y - 1] >= '1' && show_chess[x - 1][y - 1] <= '9')
                    {
                        ExpandAround(x, y);
                    }
                    else
                    {
                        Install(x, y);
                    }
                    AutoMarkStrict();
                    print_game();
                }
            }
            else if (x == 0 && y == 0)
            {
                Tab();
                print_game();
            }
            else
            {
                std::cout << "(x,y) error ,re-enter. " << std::endl;
            }
        }
        if (_win == _row * _col - _mine)
        {
            std::cout << " Complete the game! " << std::endl;
        }
    }
};