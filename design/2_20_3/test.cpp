#include <iostream>
#include <vector>
#include <memory>
using namespace std;

// 观察者（Observer）抽象类
class Observer
{
protected:
    shared_ptr<class Subject> subject; // 关联的主题

public:
    Observer(const shared_ptr<class Subject> &sub);
    virtual void update() = 0;
    virtual ~Observer() = default;
};

// 主题（Subject）类
class Subject
{
private:
    vector<shared_ptr<Observer>> observers; // 观察者列表
    int state;                              // 主题的状态

public:
    // 添加观察者
    void attach(const shared_ptr<Observer> &obs)
    {
        observers.push_back(obs);
    }

    // 设置状态并通知所有观察者
    void setState(int newState)
    {
        state = newState;
        notifyObservers();
    }

    // 获取当前状态
    int getState() const
    {
        return state;
    }

    // 通知所有观察者
    void notifyObservers()
    {
        for (const auto &obs : observers)
        {
            obs->update();
        }
    }
};

// 观察者构造函数，延迟至声明观察者类之后实现
Observer::Observer(const shared_ptr<Subject> &sub) : subject(sub)
{
    subject->attach(shared_ptr<Observer>(this));
}

// 具体观察者（ConcreteObserver）类
class ConcreteObserver : public Observer
{
private:
    int observerState; // 观察者的状态

public:
    ConcreteObserver(const shared_ptr<Subject> &sub) : Observer(sub), observerState(0) {}

    // 更新观察者状态
    void update() override
    {
        observerState = subject->getState();
        cout << "观察者状态更新为: " << observerState << endl;
    }
};

// 客户端代码
int main()
{
    // 创建主题
    auto subject = make_shared<Subject>();

    // 创建观察者并关联主题
    auto observer1 = make_shared<ConcreteObserver>(subject);
    auto observer2 = make_shared<ConcreteObserver>(subject);

    // 改变主题状态，观察者会自动更新
    subject->setState(10);
    subject->setState(20);

    return 0;
}