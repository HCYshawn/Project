#include <iostream>
#include <string>
using namespace std;

// ǰ������
class Colleague;

// �����н��߽ӿ�
class Mediator
{
public:
    virtual void Notify(Colleague *sender, const string &message) = 0;
    virtual ~Mediator() = default;
};

// ͬ�³�����
class Colleague
{
protected:
    Mediator *mediator; // �����н�������

public:
    explicit Colleague(Mediator *m) : mediator(m) {}
    virtual ~Colleague() = default;

    // ������Ϣ�ӿ�
    virtual void Send(const string &message) = 0;
    // ������Ϣ�ӿ�
    virtual void Receive(const string &message) = 0;
};

// ����ͬ����A
class ConcreteColleagueA : public Colleague
{
public:
    using Colleague::Colleague; // �̳й��캯��

    void Send(const string &message) override
    {
        cout << "ͬ��A������Ϣ: " << message << endl;
        mediator->Notify(this, message); // ͨ���н���ת��
    }

    void Receive(const string &message) override
    {
        cout << "ͬ��A�յ���Ϣ: " << message << endl;
    }

    void SpecificOperationA()
    {
        Send("����A���ض���������");
    }
};

// ����ͬ����B
class ConcreteColleagueB : public Colleague
{
public:
    using Colleague::Colleague; // �̳й��캯��

    void Send(const string &message) override
    {
        cout << "ͬ��B������Ϣ: " << message << endl;
        mediator->Notify(this, message); // ͨ���н���ת��
    }

    void Receive(const string &message) override
    {
        cout << "ͬ��B�յ���Ϣ: " << message << endl;
    }

    void SpecificOperationB()
    {
        Send("����B���ض���������");
    }
};

// �����н�����
class ConcreteMediator : public Mediator
{
private:
    ConcreteColleagueA *colleagueA; // ������ͬ�¶���A
    ConcreteColleagueB *colleagueB; // ������ͬ�¶���B

public:
    // ����ͬ�¶���
    void SetColleagueA(ConcreteColleagueA *a) { colleagueA = a; }
    void SetColleagueB(ConcreteColleagueB *b) { colleagueB = b; }

    // ʵ���н�Э���߼�
    void Notify(Colleague *sender, const string &message) override
    {
        if (sender == colleagueA)
        {
            cout << "�н��ߴ���A����Ϣ��֪ͨB" << endl;
            colleagueB->Receive(message); // A����Ϣת����B
        }
        else if (sender == colleagueB)
        {
            cout << "�н��ߴ���B����Ϣ��֪ͨA" << endl;
            colleagueA->Receive(message); // B����Ϣת����A
        }
    }
};

// �ͻ���ʹ��ʾ��
int main()
{
    // �����н���
    ConcreteMediator mediator;

    // ����ͬ�¶��󲢰��н���
    ConcreteColleagueA colleagueA(&mediator);
    ConcreteColleagueB colleagueB(&mediator);

    // �н���ά��ͬ������
    mediator.SetColleagueA(&colleagueA);
    mediator.SetColleagueB(&colleagueB);

    // ͬ��ͨ���н���ͨ��
    colleagueA.SpecificOperationA(); // A���������н���ת����B
    colleagueB.SpecificOperationB(); // B���������н���ת����A

    return 0;
}