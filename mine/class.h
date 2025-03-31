#pragma once
#include "game.h"
#include "print.h"
// 构建棋盘基类，延迟初始化至子类实现，同时构建抽象工厂类，实现开闭原则
//  棋盘基类
class Chessinitial
{
private:
    std::vector<std::vector<char>> chess;
    int _row;
    int _col;
    char _re;

protected:
    Chessinitial(int row, int col, char re)
        : _row(row),
          _col(col),
          _re(),
          chess(row, std::vector<char>(col, re))
    {
    }

public:
    virtual ~Chessinitial() {};
    virtual void print()
    {
        for (int i = 0; i < _row; i++)
        {
            for (int j = 0; j < _col; j++)
            {
                std::cout << chess[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

// 雷棋盘类
class Chessinitial_Mine_10 : public Chessinitial
{
public:
    Chessinitial_Mine_10(int row = ROW1, int col = COL1, char re = MINE)
        : Chessinitial(row, col, re) {}
};

class Chessinitial_Mine_40 : public Chessinitial
{
public:
    Chessinitial_Mine_40(int row = ROW2, int col = COL2, char re = MINE)
        : Chessinitial(row, col, re) {}
};

class Chessinitial_Mine_99 : public Chessinitial
{
public:
    Chessinitial_Mine_99(int row = ROW3, int col = COL3, char re = MINE)
        : Chessinitial(row, col, re) {}
};

class Chessinitial_Mine_custom : public Chessinitial
{
public:
    Chessinitial_Mine_custom(int row, int col, char re)
        : Chessinitial(row, col, re) {}
};

// 显示棋盘类
class Chessinitial_Show_10 : public Chessinitial
{
public:
    Chessinitial_Show_10(int row = ROW1, int col = COL1, char re = SHOW)
        : Chessinitial(row, col, re) {}
};

class Chessinitial_Show_40 : public Chessinitial
{
public:
    Chessinitial_Show_40(int row = ROW2, int col = COL2, char re = SHOW)
        : Chessinitial(row, col, re) {}
};

class Chessinitial_Show_99 : public Chessinitial
{
public:
    Chessinitial_Show_99(int row = ROW3, int col = COL3, char re = SHOW)
        : Chessinitial(row, col, re) {}
};

class Chessinitial_Show_custom : public Chessinitial
{
public:
    Chessinitial_Show_custom(int row, int col, char re)
        : Chessinitial(row, col, re) {}
};

// 抽象工厂基类
class Chessinitial_Factory
{
public:
    virtual ~Chessinitial_Factory() = default;
    virtual Chessinitial *create(int row, int col, int i) = 0;
};

// 具体工厂类————雷棋盘工厂
class MineFactory : public Chessinitial_Factory
{
public:
    Chessinitial *create(int row, int col, int i) override
    {
        switch (i)
        {
        case 1:
            return new Chessinitial_Mine_10(row, col, MINE);
        case 2:
            return new Chessinitial_Mine_40(row, col, MINE);
        case 3:
            return new Chessinitial_Mine_99(row, col, MINE);
        case 4:
            return new Chessinitial_Mine_custom(row, col, MINE);
        default:
            return nullptr;
        }
    }
};

// 具体工厂类————显示棋盘工厂
class ShowFactory : public Chessinitial_Factory
{
public:
    Chessinitial *create(int row, int col, int i) override
    {
        switch (i)
        {
        case 1:
            return new Chessinitial_Show_10(row, col, SHOW);
        case 2:
            return new Chessinitial_Show_40(row, col, SHOW);
        case 3:
            return new Chessinitial_Show_99(row, col, SHOW);
        case 4:
            return new Chessinitial_Show_custom(row, col, SHOW);
        default:
            return nullptr;
        }
    }
};
