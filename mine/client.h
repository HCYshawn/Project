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

    void play()
    {
        chess_mine->print_chess();
        chess_show->print_chess();
    }
};