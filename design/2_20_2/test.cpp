#include <iostream>
#include <memory>
using namespace std;

// ����״̬��
class State
{
public:
    virtual void display() = 0;
    virtual ~State() = default;
};

// ����״̬��
class NormalState : public State
{
public:
    void display() override
    {
        cout << "������С��" << endl;
    }
};

// �����Ŵ�״̬��
class LargerState : public State
{
public:
    void display() override
    {
        cout << "������С��" << endl;
    }
};

// �ı��Ŵ�״̬��
class LargestState : public State
{
public:
    void display() override
    {
        cout << "�ı���С��" << endl;
    }
};

// ��Ļ��
class Screen
{
private:
    shared_ptr<State> currentState; // ��ǰ״̬
    shared_ptr<State> normalState;  // ����״̬
    shared_ptr<State> largerState;  // �����Ŵ�״̬
    shared_ptr<State> largestState; // �ı��Ŵ�״̬

public:
    Screen()
    {
        // ��������״̬����
        normalState = make_shared<NormalState>();
        largerState = make_shared<LargerState>();
        largestState = make_shared<LargestState>();

        // ���ó�ʼ״̬Ϊ����״̬
        currentState = normalState;
        currentState->display();
    }

    // ���õ�ǰ״̬
    void setState(const shared_ptr<State> &state)
    {
        currentState = state;
    }

    // �����¼�����������װ�˶�״̬����ҵ�񷽷��ĵ��ú�״̬��ת��
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

// �ͻ��˴���
int main()
{
    Screen screen;
    screen.onClick(); // ��һ�ε�����л���������С
    screen.onClick(); // �ڶ��ε�����л����ı���С
    screen.onClick(); // �����ε�����л���������С

    return 0;
}