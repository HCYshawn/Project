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
    Client(int i, int row = ROW1, int col = COL1)
        : _row(row), _col(col)
    {
        if (i < 1 || i > 4)
        {
            throw std::invalid_argument("Invalid mode parameter i");
        }

        Chessinitial_Factory *minefactory = new MineFactory();
        Chessinitial_Factory *showfactory = new ShowFactory();
        chess_mine = minefactory->create(_row, _col, i);
        chess_show = showfactory->create(_row, _col, i);

        switch (i)
        {
        case 1:
            win = WIN1;
            break;
        case 2:
            win = WIN2;
            break;
        case 3:
            win = WIN3;
            break;
        case 4:
            win = (row * col) / 2; // ?????????
        }
    }

    ~Client()
    {
        delete chess_mine;
        delete chess_show;
    }
    void client_print()
    {
        chess_mine->print();
        std::cout << std::endl;
        chess_show->print();
        std::cout << std::endl;
    }

    void play()
    {
    }
};