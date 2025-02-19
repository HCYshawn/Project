#include <iostream>
#include <memory>
using namespace std;

// ǰ������
class State;

// �������ࣨ�����ࣩ
class Context
{
private:
    unique_ptr<State> state; // ���е�ǰ״̬��������ϵ��

public:
    explicit Context(State *initialState); // ���캯����Ҫ��ʼ״̬
    ~Context();

    void request();                 // ����״̬��Ϊ
    void setState(State *newState); // �޸ĵ�ǰ״̬
};

// ����״̬�ӿ�
class State
{
public:
    virtual void handle(Context *context) = 0; // ��������
    virtual ~State() = default;
};

// ����״̬�෽����Ҫ�ӳ������о���������֮�󣬷�����Ҫnew��������״̬�࣬����ǰ���������Ҳ���������
//  ����״̬A
class ConcreteStateA : public State
{
public:
    void handle(Context *context) override;
};

// ����״̬B
class ConcreteStateB : public State
{
public:
    void handle(Context *context) override;
};

void ConcreteStateA::handle(Context *context)
{
    cout << "״̬A�������󣬼����л���״̬B" << endl;
    context->setState(new ConcreteStateB()); // ����״̬ת��
}

void ConcreteStateB::handle(Context *context)
{
    cout << "״̬B�������󣬼����л���״̬A" << endl;
    context->setState(new ConcreteStateA()); // ����״̬ת��
}

// Context��ʵ��
Context::Context(State *initialState) : state(initialState) {}

Context::~Context()
{
    // unique_ptr�Զ������ڴ�
}

void Context::request()
{
    if (state)
    {
        state->handle(this); // ί�и���ǰ״̬����
    }
}

void Context::setState(State *newState)
{
    state.reset(newState); // ����ָ���Զ��ͷž�״̬
}

// �ͻ���ʹ��ʾ��
int main()
{
    Context context(new ConcreteStateA());

    // ��һ������A�����л���B
    context.request(); // �����״̬A�������󣬼����л���״̬B

    // �ڶ�������B�����л���A
    context.request(); // �����״̬B�������󣬼����л���״̬A

    return 0;
}