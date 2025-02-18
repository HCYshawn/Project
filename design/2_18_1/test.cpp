#include <iostream>
#include <string>
using namespace std;

// 前向声明
class Colleague;

// 抽象中介者接口
class Mediator
{
public:
    virtual void Notify(Colleague *sender, const string &message) = 0;
    virtual ~Mediator() = default;
};

// 同事抽象类
class Colleague
{
protected:
    Mediator *mediator; // 持有中介者引用

public:
    explicit Colleague(Mediator *m) : mediator(m) {}
    virtual ~Colleague() = default;

    // 发送消息接口
    virtual void Send(const string &message) = 0;
    // 接收消息接口
    virtual void Receive(const string &message) = 0;
};

// 具体同事类A
class ConcreteColleagueA : public Colleague
{
public:
    using Colleague::Colleague; // 继承构造函数

    void Send(const string &message) override
    {
        cout << "同事A发送消息: " << message << endl;
        mediator->Notify(this, message); // 通过中介者转发
    }

    void Receive(const string &message) override
    {
        cout << "同事A收到消息: " << message << endl;
    }

    void SpecificOperationA()
    {
        Send("来自A的特定操作请求");
    }
};

// 具体同事类B
class ConcreteColleagueB : public Colleague
{
public:
    using Colleague::Colleague; // 继承构造函数

    void Send(const string &message) override
    {
        cout << "同事B发送消息: " << message << endl;
        mediator->Notify(this, message); // 通过中介者转发
    }

    void Receive(const string &message) override
    {
        cout << "同事B收到消息: " << message << endl;
    }

    void SpecificOperationB()
    {
        Send("来自B的特定操作请求");
    }
};

// 具体中介者类
class ConcreteMediator : public Mediator
{
private:
    ConcreteColleagueA *colleagueA; // 关联的同事对象A
    ConcreteColleagueB *colleagueB; // 关联的同事对象B

public:
    // 设置同事对象
    void SetColleagueA(ConcreteColleagueA *a) { colleagueA = a; }
    void SetColleagueB(ConcreteColleagueB *b) { colleagueB = b; }

    // 实现中介协调逻辑
    void Notify(Colleague *sender, const string &message) override
    {
        if (sender == colleagueA)
        {
            cout << "中介者处理A的消息，通知B" << endl;
            colleagueB->Receive(message); // A的消息转发给B
        }
        else if (sender == colleagueB)
        {
            cout << "中介者处理B的消息，通知A" << endl;
            colleagueA->Receive(message); // B的消息转发给A
        }
    }
};

// 客户端使用示例
int main()
{
    // 创建中介者
    ConcreteMediator mediator;

    // 创建同事对象并绑定中介者
    ConcreteColleagueA colleagueA(&mediator);
    ConcreteColleagueB colleagueB(&mediator);

    // 中介者维护同事引用
    mediator.SetColleagueA(&colleagueA);
    mediator.SetColleagueB(&colleagueB);

    // 同事通过中介者通信
    colleagueA.SpecificOperationA(); // A发送请求，中介者转发给B
    colleagueB.SpecificOperationB(); // B发送请求，中介者转发给A

    return 0;
}