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

public:
    Client(int row = ROW1, int col = COL1, int mine = GAMEMINE1, int win = 0)
        : _row(row), _col(col), _mine(mine), _win(win)
    {
        Chessinitial_Factory *minefactory = new MineFactory();
        Chessinitial_Factory *showfactory = new ShowFactory();
        chess_mine = minefactory->create(_row + 2, _col + 2, MINE);
        chess_show = showfactory->create(_row, _col, SHOW);
    }

    ~Client()
    {
        delete chess_mine;
        delete chess_show;
    }

    void print_game()
    {
        // 打印边框上
        print_upperborder(_row);

        // 打印棋盘
        for (int i = 0; i < _col; i++)
        {
            // 打印上行标
            print_uppercolsign(i, _row);

            if (i + 1 >= 10)
            {
                printf("||");
            }
            else
                printf("|| ");

            // 打印列标
            printf("%d ", i + 1);

            // 调用棋盘类的打印行函数
            chess_show->print_row(i);

            // 打印列标
            printf("%d", i + 1);

            if (i + 1 >= 10)
            {
                printf("||\n");
            }
            else
                printf(" ||\n");

            // 打印下行标
            print_lowercolsign(i, _col, _row);
        }

        // 打印边框下
        print_lowerborder(_row);
    }

    void Arrangemine(int x, int y)
    {
        int mid = _mine;
        auto &mine_chess = chess_mine->GetChess();
        while (mid)
        {
            int i = (rand() % (_row + 1)) + 1;
            int j = (rand() % (_col + 1)) + 1;
            if (abs(i - x) <= 1 && abs(j - y) <= 1)
                continue;

            if (mine_chess[i][j] == '0')
            {
                mine_chess[i][j] = '1';
                mid--;
            }
        }
    }
    int Retmine(int x, int y)
    {
        auto &mine_chess = chess_mine->GetChess();
        int ret = (mine_chess[x - 1][y - 1] + mine_chess[x - 1][y] + mine_chess[x - 1][y + 1] + mine_chess[x][y - 1] + mine_chess[x][y + 1] + mine_chess[x + 1][y - 1] + mine_chess[x + 1][y] + mine_chess[x + 1][y + 1] - 8 * '0');
        return ret;
    }

    void Install(int x, int y)
    {
        if (x < 1 || x > _row || y < 1 || y > _col)
        {
            return;
        }

        auto &show_chess = chess_show->GetChess();
        if (show_chess[x - 1][y - 1] != '#')
        {
            return;
        }

        int mid = Retmine(x, y);
        if (mid > 0)
        {
            _win++;
            show_chess[x - 1][y - 1] = mid + '0';
            return;
        }
        else if (mid == 0)
        {
            _win++;
            show_chess[x - 1][y - 1] = ' ';
            for (int dx = -1; dx <= 1; dx++)
            {
                for (int dy = -1; dy <= 1; dy++)
                {
                    if (dx == 0 && dy == 0)
                        continue; // 排除中心点
                    Install(x + dx, y + dy);
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
            printf("请输入要标记的坐标：");
            std::cin >> cin_x >> cin_y;
            cin_x -= 1;
            cin_y -= 1;
            if ((cin_x >= 0 && cin_x < _row) && (cin_y >= 0 && cin_y < _col))
            {
                show_chess[cin_x][cin_y] = '!';
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
                printf("输入错误，请重新输入！\n");
                continue;
            }
        }
    }

    // void Auto_tab()
    // {
    //     auto &show_chess = chess_show->GetChess();
    //     auto &mine_chess = chess_mine->GetChess();
    //     for (int i = 0; i < _row; i++)
    //     {
    //         for (int j = 0; j < _col; j++)
    //         {
    //             if ('1' <= show_chess[i][j] && '9' >= show_chess[i][j])
    //             {
    //                 int mid = Retmine(i + 1, j + 1);
    //                 // 当周边格都是雷时
    //                 if (mid == show_chess[i - 1][j - 1] - '0')
    //                 {
    //                     // 判断左上角情况
    //                     if ((i == 1 && j == 0))
    //                     {
    //                         if (mine_chess[i][j + 1] == '1')
    //                             show_chess[i][j + 1] = '!';
    //                         else if (mine_chess[i + 1][j] == '1')
    //                             show_chess[i + 1][j] = '!';
    //                         else if (mine_chess[i + 1][j + 1] == '1')
    //                             show_chess[i + 1][j + 1] = '!';
    //                     }
    //                     // 判断右上角情况
    //                     else if (i == 0 && j == _col - 1)
    //                     {
    //                         if (mine_chess[i][j - 1] == '1')
    //                             show_chess[i][j - 1] = '!';
    //                         else if (mine_chess[i + 1][j - 1] == '1')
    //                             show_chess[i + 1][j - 1] = '!';
    //                         else if (mine_chess[i + 1][j] == '1')
    //                             show_chess[i + 1][j] = '!';
    //                     }
    //                     // 判断左下角情况
    //                     else if (i == _row - 1 && j == 0)
    //                     {
    //                         if (mine_chess[i - 1][j] == '1')
    //                             show_chess[i - 1][j] = '!';
    //                         else if (mine_chess[i - 1][j + 1] == '1')
    //                             show_chess[i - 1][j + 1] = '!';
    //                         else if (mine_chess[i][j + 1] == '1')
    //                             show_chess[i][j + 1] = '!';
    //                     }
    //                     // 判断右下角情况
    //                     else if (i == _row - 1 && j == _col - 1)
    //                     {
    //                         if (mine_chess[i - 1][j] == '1')
    //                             show_chess[i - 1][j] = '!';
    //                         else if (mine_chess[i - 1][j - 1] == '1')
    //                             show_chess[i - 1][j - 1] = '!';
    //                         else if (mine_chess[i][j - 1] == '1')
    //                             show_chess[i][j - 1] = '!';
    //                     }
    //                     else
    //                     {
    //                         // 判断上下边界情况
    //                         if (i == 0)
    //                         {
    //                             if (mine_chess[i][j - 1] == '1')
    //                                 show_chess[i][j - 1] = '!';
    //                             else if (mine_chess[i + 1][j - 1] == '1')
    //                                 show_chess[i + 1][j - 1] = '!';
    //                             else if (mine_chess[i + 1][j] == '1')
    //                                 show_chess[i + 1][j] = '!';
    //                             else if (mine_chess[i + 1][j + 1] == '1')
    //                                 show_chess[i + 1][j + 1] = '!';
    //                         }
    //                         else if (i == _row - 1)
    //                         {
    //                             if (mine_chess[i - 1][j - 1] == '1')
    //                                 show_chess[i - 1][j - 1] = '!';
    //                             else if (mine_chess[i - 1][j] == '1')
    //                                 show_chess[i - 1][j] = '!';
    //                             else if (mine_chess[i - 1][j + 1] == '1')
    //                                 show_chess[i - 1][j + 1] = '!';
    //                             else if (mine_chess[i][j - 1] == '1')
    //                                 show_chess[i][j - 1] = '!';
    //                         }
    //                         // 判断左右边界情况
    //                         else if (j == 0)
    //                         {
    //                             if (mine_chess[i - 1][j] == '1')
    //                                 show_chess[i - 1][j] = '!';
    //                             else if (mine_chess[i - 1][j + 1] == '1')
    //                                 show_chess[i - 1][j + 1] = '!';
    //                             else if (mine_chess[i][j + 1] == '1')
    //                                 show_chess[i][j + 1] = '!';
    //                             else if (mine_chess[i + 1][j] == '1')
    //                                 show_chess[i + 1][j] = '!';
    //                             else if (mine_chess[i + 1][j + 1] == '1')
    //                                 show_chess[i + 1][j + 1] = '!';
    //                         }
    //                         else if (j == _col - 1)
    //                         {
    //                             if (mine_chess[i - 1][j - 1] == '1')
    //                                 show_chess[i - 1][j - 1] = '!';
    //                             else if (mine_chess[i - 1][j] == '1')
    //                                 show_chess[i - 1][j] = '!';
    //                             else if (mine_chess[i][j - 1] == '1')
    //                                 show_chess[i][j - 1] = '!';
    //                             else if (mine_chess[i + 1][j - 1] == '1')
    //                                 show_chess[i + 1][j - 1] = '!';
    //                             else if (mine_chess[i + 1][j] == '1')
    //                                 show_chess[i + 1][j] = '!';
    //                         }
    //                     }

    //                     // 中间情况
    //                     if (mine_chess[i - 1][j - 1] == '1')
    //                         show_chess[i - 1][j - 1] = '!';
    //                     else if (mine_chess[i - 1][j] == '1')
    //                         show_chess[i - 1][j] = '!';
    //                     else if (mine_chess[i - 1][j + 1] == '1')
    //                         show_chess[i - 1][j + 1] = '!';
    //                     else if (mine_chess[i][j - 1] == '1')
    //                         show_chess[i][j - 1] = '!';
    //                     else if (mine_chess[i][j + 1] == '1')
    //                         show_chess[i][j + 1] = '!';
    //                     else if (mine_chess[i + 1][j - 1] == '1')
    //                         show_chess[i + 1][j - 1] = '!';
    //                     else if (mine_chess[i + 1][j] == '1')
    //                         show_chess[i + 1][j] = '!';
    //                     else if (mine_chess[i + 1][j + 1] == '1')
    //                         show_chess[i + 1][j + 1] = '!';
    //                 }
    //             }
    //         }
    //     }
    // }

    void Auto_tab()
    {
        auto &show_chess = chess_show->GetChess();
        auto &mine_chess = chess_mine->GetChess();

        for (int i = 0; i < _row; i++)
        { // 修复1：全棋盘遍历
            for (int j = 0; j < _col; j++)
            {
                if (show_chess[i][j] < '1' || show_chess[i][j] > '9')
                    continue;

                const int mine_x = i + 1; // 修复2：坐标系转换
                const int mine_y = j + 1;
                const int actual_mines = Retmine(mine_x, mine_y);

                if (actual_mines != (show_chess[i][j] - '0'))
                    continue;

                // 8方向检测
                for (int dx = -1; dx <= 1; dx++)
                {
                    for (int dy = -1; dy <= 1; dy++)
                    {
                        const int nx = mine_x + dx;
                        const int ny = mine_y + dy;
                        if (nx < 1 || nx > _row || ny < 1 || ny > _col)
                            continue;

                        if (mine_chess[nx][ny] == '1' && show_chess[nx - 1][ny - 1] == '#')
                        {
                            show_chess[nx - 1][ny - 1] = '!'; // 标记未翻开的雷
                        }
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
            print_game();
            std::cout << "请输入要排查的坐标: ";
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
                    Install(x, y);
                    Auto_tab();
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