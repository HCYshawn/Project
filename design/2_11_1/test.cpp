#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 前向声明
class ChessmanMemento;

// 棋子类（Originator）
class Chessman
{
private:
    string label;
    int x;
    int y;

public:
    Chessman(const string &label, int x, int y)
        : label(label), x(x), y(y) {}

    // 保存当前状态到备忘录
    ChessmanMemento save();

    // 从备忘录恢复状态
    void restore(const ChessmanMemento &memento);

    // Getter和Setter
    string getLabel() const { return label; }
    void setLabel(const string &label) { this->label = label; }
    int getX() const { return x; }
    void setX(int x) { this->x = x; }
    int getY() const { return y; }
    void setY(int y) { this->y = y; }
};

// 棋子备忘录类（Memento）
class ChessmanMemento
{
private:
    string label;
    int x;
    int y;

    // 声明友元类，允许Chessman访问私有成员
    friend class Chessman;

    // 构造函数私有化，确保只有Chessman可以创建备忘录
    ChessmanMemento(const string &label, int x, int y)
        : label(label), x(x), y(y) {}

public:
    // Getter方法（Caretaker可以获取状态但不修改）
    string getLabel() const { return label; }
    int getX() const { return x; }
    int getY() const { return y; }
};

// Chessman的save和restore实现
ChessmanMemento Chessman::save()
{
    return ChessmanMemento(label, x, y); // 调用私有构造函数
}

void Chessman::restore(const ChessmanMemento &memento)
{
    label = memento.label;
    x = memento.x;
    y = memento.y;
}

// 备忘录管理者（Caretaker）
class MementoCaretaker
{
private:
    vector<ChessmanMemento> mementoList; // 存储备忘录对象

public:
    // 获取指定位置的备忘录
    ChessmanMemento getMemento(int index) const
    {
        if (index >= 0 && index < mementoList.size())
        {
            return mementoList[index];
        }
        throw out_of_range("无效的索引");
    }

    // 添加新的备忘录
    void setMemento(const ChessmanMemento &memento)
    {
        mementoList.push_back(memento);
    }
};

int main()
{
    // 创建棋子并设置初始状态
    Chessman chessman("车", 1, 2);
    MementoCaretaker caretaker;

    // 保存初始状态
    caretaker.setMemento(chessman.save());      // 保存状态
    cout << "初始状态: " << chessman.getLabel() // 输出状态
         << " (" << chessman.getX() << ", " << chessman.getY() << ")\n";

    // 修改棋子状态
    chessman.setX(3);
    chessman.setY(4);
    cout << "修改后状态: " << chessman.getLabel()
         << " (" << chessman.getX() << ", " << chessman.getY() << ")\n";

    // 从备忘录恢复状态
    chessman.restore(caretaker.getMemento(0));
    cout << "恢复后状态: " << chessman.getLabel()
         << " (" << chessman.getX() << ", " << chessman.getY() << ")\n";

    return 0;
}