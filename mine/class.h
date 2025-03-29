#pragma once
#include "game.h"

//�������̻��࣬�ӳٳ�ʼ��������ʵ�֣�ͬʱ�������󹤳��࣬ʵ�ֿ���ԭ��
// ���̻���
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

    void print() const
    {
        for (const auto &row : chess)
        {
            for (char c : row)
            {
                std::cout << c << " ";
            }
            std::cout << "\n";
        }
    }
};

// ��������
class Chessinitial_Mine : public Chessinitial
{
public:
    Chessinitial_Mine(int row, int col, char re)
        : Chessinitial(row, col, re) {}
};

// ��ʾ������
class Chessinitial_Show : public Chessinitial
{
public:
    Chessinitial_Show(int row, int col, char re)
        : Chessinitial(row, col, re) {}
};

// ���󹤳�����
class Chessinitial_Factory
{
public:
    virtual ~Chessinitial_Factory() = default;
    virtual Chessinitial *create(int row, int col, char re) = 0;
};

// ���幤���ࡪ�����������̹���
class MineFactory : public Chessinitial_Factory
{
public:
    Chessinitial *create(int row, int col, char re) override
    {
        return new Chessinitial_Mine(row, col, MINE);
    }
};

// ���幤���ࡪ��������ʾ���̹���
class ShowFactory : public Chessinitial_Factory
{
public:
    Chessinitial *create(int row, int col, char re) override
    {
        return new Chessinitial_Show(row, col, SHOW);
    }
};

