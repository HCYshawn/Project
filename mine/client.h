#pragma once
#include "class.h"

class Client
{
private:
    Chessinitial *chess_mine;
    Chessinitial *chess_show;
    int _row;
    int _col;
    int win;

public:
    Client(int row = ROW1, int col = COL1, int win = WIN1)
        : _row(row), _col(col), win(win)
    {
        Chessinitial_Factory *minefactory = new MineFactory();
        Chessinitial_Factory *showfactory = new ShowFactory();
        chess_mine = minefactory->create(_row, _col, MINE);
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

    void play()
    {
        chess_mine->print_chess();
        chess_show->print_chess();
    }
};