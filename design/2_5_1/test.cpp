#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// 坐标类
class Coordinates
{
private:
    int x, y;

public:
    Coordinates(int x = 0, int y = 0) : x(x), y(y) {}

    int getX() const { return x; }
    void setX(int x) { this->x = x; }

    int getY() const { return y; }
    void setY(int y) { this->y = y; }
};

// 抽象享元类
class lgoChessman
{
public:
    virtual ~lgoChessman() {}
    virtual string getColor() const = 0;
    virtual void display(const Coordinates &coord) const = 0;
};

// 具体享元类：黑棋
class BlacklgoChessman : public lgoChessman
{
public:
    string getColor() const override
    {
        return "Black";
    }

    void display(const Coordinates &coord) const override
    {
        cout << "黑棋坐标： (" << coord.getX() << ", " << coord.getY() << ")" << endl;
    }
};

// 具体享元类：白棋
class WhitelgoChessman : public lgoChessman
{
public:
    string getColor() const override
    {
        return "White";
    }

    void display(const Coordinates &coord) const override
    {
        cout << "白棋坐标： (" << coord.getX() << ", " << coord.getY() << ")" << endl;
    }
};

// 享元工厂类
class lgoChessmanFactory
{
private:
    unordered_map<string, lgoChessman *> chessmen; // 享元池,存储不同颜色的棋子，将坐标数据延迟至客户端实现显示，只负责存储棋子对象

    lgoChessmanFactory() {} // 私有构造函数

public:
    ~lgoChessmanFactory()
    { 
        for (auto &pair : chessmen)
        {
            delete pair.second;
        }
    }

    static lgoChessmanFactory &getInstance()
    {
        static lgoChessmanFactory instance;
        return instance;
    }

    lgoChessman *getlgoChessman(const string &color)
    {
        if (chessmen.find(color) == chessmen.end()) // 如果没有该颜色的棋子，则创建
        {
            if (color == "Black")
            {
                chessmen[color] = new BlacklgoChessman();
            }
            else if (color == "White")
            {
                chessmen[color] = new WhitelgoChessman();
            }
        }
        return chessmen[color];
    }
};

int main()
{
    lgoChessmanFactory &factory = lgoChessmanFactory::getInstance();

    lgoChessman *blackChessman1 = factory.getlgoChessman("Black");
    lgoChessman *whiteChessman1 = factory.getlgoChessman("White");
    lgoChessman *blackChessman2 = factory.getlgoChessman("Black");

    blackChessman1->display(Coordinates(1, 2));
    whiteChessman1->display(Coordinates(3, 4));
    blackChessman2->display(Coordinates(5, 6));

    return 0;
}