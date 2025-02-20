#include <iostream>
#include <string>
using namespace std;

// ǰ������
class Switch;

// ����״̬��
class State
{
public:
    virtual ~State() = default;
    virtual void on(Switch *context) = 0;  // �򿪲���
    virtual void off(Switch *context) = 0; // �رղ���
};

// ����״̬������״̬
class OnState : public State
{
public:
    void on(Switch *context) override
    {
        cout << "�Ѿ��򿪣�\n"; // �Ѿ��ǿ���״̬���������
    }

    void off(Switch *context) override;
};

// ����״̬���ر�״̬
class OffState : public State
{
public:
    void on(Switch *context) override;

    void off(Switch *context) override
    {
        cout << "�Ѿ��رգ�\n"; // �Ѿ��ǹر�״̬���������
    }
};

// �������ࣺ����
class Switch
{
private:
    string name;            // ��������
    static State *state;    // ��ǰ״̬����̬��Ա������״̬��
    static State *onState;  // ����״̬����̬��Ա������״̬��
    static State *offState; // �ر�״̬����̬��Ա������״̬��

public:
    explicit Switch(const string &name) : name(name)
    {
        // ��ʼ����̬״̬����
        if (onState == nullptr)
        {
            onState = new OnState();
        }
        if (offState == nullptr)
        {
            offState = new OffState();
        }
        state = onState; // ��ʼ״̬Ϊ����״̬
    }

    // ���õ�ǰ״̬
    void setState(State *newState)
    {
        state = newState;
    }

    // �������ͻ�ȡ����״̬����
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

    // �򿪿���
    void on()
    {
        cout << name;
        state->on(this);
    }

    // �رտ���
    void off()
    {
        cout << name;
        state->off(this);
    }
};

// ��̬��Ա��ʼ��
State *Switch::state = nullptr;
State *Switch::onState = nullptr;
State *Switch::offState = nullptr;

// ʵ�� OffState �� on ����
void OffState::on(Switch *context)
{
    cout << "�򿪣�\n";
    context->setState(Switch::getState("on")); // �л�������״̬
}

// ʵ�� OnState �� off ����
void OnState::off(Switch *context)
{
    cout << "�رգ�\n";
    context->setState(Switch::getState("off")); // �л����ر�״̬
}

// �ͻ��˴���
int main()
{
    // �����������ض���
    Switch s1("����1");
    Switch s2("����2");

    // ��������
    s1.on();  // ����1�Ѿ��򿪣�
    s2.on();  // ����2�Ѿ��򿪣�
    s1.off(); // ����1�رգ�
    s2.off(); // ����2�Ѿ��رգ�
    s2.on();  // ����2�򿪣�
    s1.on();  // ����1�Ѿ��򿪣�

    return 0;
}