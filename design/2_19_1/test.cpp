#include <iostream>
#include <memory>
using namespace std;

// 前向声明
class State;

// 上下文类（环境类）
class Context
{
private:
    unique_ptr<State> state; // 持有当前状态（关联关系）

public:
    explicit Context(State *initialState); // 构造函数需要初始状态
    ~Context();

    void request();                 // 触发状态行为
    void setState(State *newState); // 修改当前状态
};

// 抽象状态接口
class State
{
public:
    virtual void handle(Context *context) = 0; // 处理请求
    virtual ~State() = default;
};

// 具体状态类方法需要延迟至所有具体类声明之后，方法需要new其他具体状态类，若在前面声明会找不到具体类
//  具体状态A
class ConcreteStateA : public State
{
public:
    void handle(Context *context) override;
};

// 具体状态B
class ConcreteStateB : public State
{
public:
    void handle(Context *context) override;
};

void ConcreteStateA::handle(Context *context)
{
    cout << "状态A处理请求，即将切换到状态B" << endl;
    context->setState(new ConcreteStateB()); // 触发状态转换
}

void ConcreteStateB::handle(Context *context)
{
    cout << "状态B处理请求，即将切换回状态A" << endl;
    context->setState(new ConcreteStateA()); // 触发状态转换
}

// Context类实现
Context::Context(State *initialState) : state(initialState) {}

Context::~Context()
{
    // unique_ptr自动管理内存
}

void Context::request()
{
    if (state)
    {
        state->handle(this); // 委托给当前状态处理
    }
}

void Context::setState(State *newState)
{
    state.reset(newState); // 智能指针自动释放旧状态
}

// 客户端使用示例
int main()
{
    Context context(new ConcreteStateA());

    // 第一次请求：A处理并切换到B
    context.request(); // 输出：状态A处理请求，即将切换到状态B

    // 第二次请求：B处理并切换回A
    context.request(); // 输出：状态B处理请求，即将切换回状态A

    return 0;
}