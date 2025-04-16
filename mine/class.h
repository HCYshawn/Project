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
          _re(re),
          chess(row, std::vector<char>(col, re))
    {
    }

public:
    virtual ~Chessinitial() {};
    std::vector<std::vector<char>> &GetChess()
    {
        return chess;
    }
    virtual void print_row(int i) = 0;
};

// 雷棋盘类
class Chessinitial_Mine : public Chessinitial
{
public:
    Chessinitial_Mine(int row, int col, char re)
        : Chessinitial(row, col, re) {}
    void print_row(int i) override {}
};

// 显示棋盘类
class Chessinitial_Show : public Chessinitial
{
public:
    Chessinitial_Show(int row, int col, char re)
        : Chessinitial(row, col, re) {}

    void print_row(int i)
    {
        const auto &show_chess = GetChess();
        for (int j = 0; j < show_chess[i].size(); j++)
        {
            if (j == show_chess[i].size() - 1)
            {
                std::cout << show_chess[i][j];
                continue;
            }
            std::cout << show_chess[i][j] << " ";
        }
    }
};

// 抽象工厂基类
class Chessinitial_Factory
{
public:
    virtual ~Chessinitial_Factory() = default;
    virtual Chessinitial *create(int row, int col, char re) = 0;
};

// 具体工厂类————雷棋盘工厂
class MineFactory : public Chessinitial_Factory
{
public:
    Chessinitial *create(int row, int col, char re) override
    {
        return new Chessinitial_Mine(row, col, MINE);
    }
};

// 具体工厂类————显示棋盘工厂
class ShowFactory : public Chessinitial_Factory
{
public:
    Chessinitial *create(int row, int col, char re) override
    {
        return new Chessinitial_Show(row, col, SHOW);
    }
};
