#include <iostream>
#include <string>
using namespace std;

// 前向声明
class Switch;

// 抽象状态类
class State
{
public:
    virtual ~State() = default;
    virtual void on(Switch *context) = 0;  // 打开操作
    virtual void off(Switch *context) = 0; // 关闭操作
};

// 具体状态：开启状态
class OnState : public State
{
public:
    void on(Switch *context) override
    {
        cout << "已经打开！\n"; // 已经是开启状态，无需操作
    }

    void off(Switch *context) override;
};

// 具体状态：关闭状态
class OffState : public State
{
public:
    void on(Switch *context) override;

    void off(Switch *context) override
    {
        cout << "已经关闭！\n"; // 已经是关闭状态，无需操作
    }
};

// 上下文类：开关
class Switch
{
private:
    string name;            // 开关名称
    static State *state;    // 当前状态（静态成员，共享状态）
    static State *onState;  // 开启状态（静态成员，共享状态）
    static State *offState; // 关闭状态（静态成员，共享状态）

public:
    explicit Switch(const string &name) : name(name)
    {
        // 初始化静态状态对象
        if (onState == nullptr)
        {
            onState = new OnState();
        }
        if (offState == nullptr)
        {
            offState = new OffState();
        }
        state = onState; // 初始状态为开启状态
    }

    // 设置当前状态
    void setState(State *newState)
    {
        state = newState;
    }

    // 根据类型获取共享状态对象
    static State *getState(const string &type)
    {
        if (type == "on")
        {
            return onState;
        }
        else
        {
            return offState;
        }
    }

    // 打开开关
    void on()
    {
        cout << name;
        state->on(this);
    }

    // 关闭开关
    void off()
    {
        cout << name;
        state->off(this);
    }
};

// 静态成员初始化
State *Switch::state = nullptr;
State *Switch::onState = nullptr;
State *Switch::offState = nullptr;

// 实现 OffState 的 on 方法
void OffState::on(Switch *context)
{
    cout << "打开！\n";
    context->setState(Switch::getState("on")); // 切换到开启状态
}

// 实现 OnState 的 off 方法
void OnState::off(Switch *context)
{
    cout << "关闭！\n";
    context->setState(Switch::getState("off")); // 切换到关闭状态
}

// 客户端代码
int main()
{
    // 创建两个开关对象
    Switch s1("开关1");
    Switch s2("开关2");

    // 操作开关
    s1.on();  // 开关1已经打开！
    s2.on();  // 开关2已经打开！
    s1.off(); // 开关1关闭！
    s2.off(); // 开关2已经关闭！
    s2.on();  // 开关2打开！
    s1.on();  // 开关1已经打开！

    return 0;
}