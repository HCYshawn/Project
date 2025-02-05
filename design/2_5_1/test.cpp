#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// ������
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

// ������Ԫ��
class lgoChessman
{
public:
    virtual ~lgoChessman() {}
    virtual string getColor() const = 0;
    virtual void display(const Coordinates &coord) const = 0;
};

// ������Ԫ�ࣺ����
class BlacklgoChessman : public lgoChessman
{
public:
    string getColor() const override
    {
        return "Black";
    }

    void display(const Coordinates &coord) const override
    {
        cout << "�������꣺ (" << coord.getX() << ", " << coord.getY() << ")" << endl;
    }
};

// ������Ԫ�ࣺ����
class WhitelgoChessman : public lgoChessman
{
public:
    string getColor() const override
    {
        return "White";
    }

    void display(const Coordinates &coord) const override
    {
        cout << "�������꣺ (" << coord.getX() << ", " << coord.getY() << ")" << endl;
    }
};

// ��Ԫ������
class lgoChessmanFactory
{
private:
    unordered_map<string, lgoChessman *> chessmen; // ��Ԫ��,�洢��ͬ��ɫ�����ӣ������������ӳ����ͻ���ʵ����ʾ��ֻ����洢���Ӷ���

    lgoChessmanFactory() {} // ˽�й��캯��

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
        if (chessmen.find(color) == chessmen.end()) // ���û�и���ɫ�����ӣ��򴴽�
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