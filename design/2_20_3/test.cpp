#include <iostream>
#include <vector>
#include <memory>
using namespace std;

// �۲��ߣ�Observer��������
class Observer
{
protected:
    shared_ptr<class Subject> subject; // ����������

public:
    Observer(const shared_ptr<class Subject> &sub);
    virtual void update() = 0;
    virtual ~Observer() = default;
};

// ���⣨Subject����
class Subject
{
private:
    vector<shared_ptr<Observer>> observers; // �۲����б�
    int state;                              // �����״̬

public:
    // ��ӹ۲���
    void attach(const shared_ptr<Observer> &obs)
    {
        observers.push_back(obs);
    }

    // ����״̬��֪ͨ���й۲���
    void setState(int newState)
    {
        state = newState;
        notifyObservers();
    }

    // ��ȡ��ǰ״̬
    int getState() const
    {
        return state;
    }

    // ֪ͨ���й۲���
    void notifyObservers()
    {
        for (const auto &obs : observers)
        {
            obs->update();
        }
    }
};

// �۲��߹��캯�����ӳ��������۲�����֮��ʵ��
Observer::Observer(const shared_ptr<Subject> &sub) : subject(sub)
{
    subject->attach(shared_ptr<Observer>(this));
}

// ����۲��ߣ�ConcreteObserver����
class ConcreteObserver : public Observer
{
private:
    int observerState; // �۲��ߵ�״̬

public:
    ConcreteObserver(const shared_ptr<Subject> &sub) : Observer(sub), observerState(0) {}

    // ���¹۲���״̬
    void update() override
    {
        observerState = subject->getState();
        cout << "�۲���״̬����Ϊ: " << observerState << endl;
    }
};

// �ͻ��˴���
int main()
{
    // ��������
    auto subject = make_shared<Subject>();

    // �����۲��߲���������
    auto observer1 = make_shared<ConcreteObserver>(subject);
    auto observer2 = make_shared<ConcreteObserver>(subject);

    // �ı�����״̬���۲��߻��Զ�����
    subject->setState(10);
    subject->setState(20);

    return 0;
}