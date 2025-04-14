#pragma once
#include "class.h"

class Client
{
private:
    Chessinitial *chess_mine;
    Chessinitial *chess_show;
    int _row;
    int _col;
    int _win;

public:
    Client(int row = ROW1, int col = COL1, int win = WIN1)
        : _row(row), _col(col), _win(win)
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

    void Arrangemine()
    {
        int mid = _win;
        auto &mine_chess = chess_mine->GetChess();
        while (mid)
        {
            int x = rand() % _row + 1;
            int y = rand() % _col + 1;

            if (mine_chess[x][y] == '0')
            {
                mine_chess[x][y] = '1';
                mid--;
            }
        }
    }

    int Retmine(int x, int y)
    {
        auto &mine_chess = chess_mine->GetChess();
        int ret = (mine_chess[x - 1][y - 1] + mine_chess[x - 1][y] + mine_chess[x - 1][y + 1] + mine_chess[x][y - 1] + mine_chess[x][y] + mine_chess[x][y + 1] + mine_chess[x + 1][y - 1] + mine_chess[x + 1][y] + mine_chess[x + 1][y + 1] - 8 * '0');
        return ret;
    }

    void Install(int x, int y)
    {
        if (x < 1 || x >= _row || y < 1 || y > _col)
        {
            printf("输入错误，请重新输入！\n");
            return;
        }

        auto &mine_chess = chess_mine->GetChess();
        auto &show_chess = chess_show->GetChess();
        if (show_chess[x][y] != '#')
        {
            return;
        }

        int mid = Retmine(x, y);
        if (mid > 0)
        {
            _win++;
            show_chess[x][y] = mid + '0';
            return;
        }
        else if (mid == 0)
        {
            _win++;
            show_chess[x][y] = ' ';
            Install(x - 1, y - 1);
            Install(x - 1, y);
            Install(x - 1, y + 1);
            Install(x, y - 1);
            Install(x, y);
            Install(x, y + 1);
            Install(x + 1, y - 1);
            Install(x = 1, y);
            Install(x + 1, y + 1);
        }
    }

    void Tab()
    {
        int x = 1;
        int y = 1;
        int cin_x = 0;
        int cin_y = 0;
        auto &show_chess = chess_show->GetChess();
        while (1)
        {
            printf("请输入要标记的坐标：");
            std::cin >> cin_x >> cin_y;
            if ((x > 1 && x <= _row) && (y >= 1 && y <= _col))
            {
                show_chess[x][y] = '!';
            }
            else if (cin_x == 0 && cin_y == 0)
            {
                break;
            }
            else if (cin_x == 0 && cin_y == 1)
            {
                show_chess[x][y] = '#';
            }
            else
            {
                printf("输入错误，请重新输入！\n");
                continue;
            }
        }
    }

    void Play()
    {
    }
};