#include <iostream>
#include <memory>
using namespace std;

// 抽象状态类
class State
{
public:
    virtual void display() = 0;
    virtual ~State() = default;
};

// 正常状态类
class NormalState : public State
{
public:
    void display() override
    {
        cout << "正常大小！" << endl;
    }
};

// 二倍放大状态类
class LargerState : public State
{
public:
    void display() override
    {
        cout << "二倍大小！" << endl;
    }
};

// 四倍放大状态类
class LargestState : public State
{
public:
    void display() override
    {
        cout << "四倍大小！" << endl;
    }
};

// 屏幕类
class Screen
{
private:
    shared_ptr<State> currentState; // 当前状态
    shared_ptr<State> normalState;  // 正常状态
    shared_ptr<State> largerState;  // 二倍放大状态
    shared_ptr<State> largestState; // 四倍放大状态

public:
    Screen()
    {
        // 创建各个状态对象
        normalState = make_shared<NormalState>();
        largerState = make_shared<LargerState>();
        largestState = make_shared<LargestState>();

        // 设置初始状态为正常状态
        currentState = normalState;
        currentState->display();
    }

    // 设置当前状态
    void setState(const shared_ptr<State> &state)
    {
        currentState = state;
    }

    // 单击事件处理方法，封装了对状态类中业务方法的调用和状态的转换
    void onClick()
    {
        if (currentState == normalState)
        {
            setState(largerState);
        }
        else if (currentState == largerState)
        {
            setState(largestState);
        }
        else if (currentState == largestState)
        {
            setState(normalState);
        }
        currentState->display();
    }
};

// 客户端代码
int main()
{
    Screen screen;
    screen.onClick(); // 第一次点击，切换到二倍大小
    screen.onClick(); // 第二次点击，切换到四倍大小
    screen.onClick(); // 第三次点击，切换回正常大小

    return 0;
}