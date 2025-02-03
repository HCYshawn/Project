#include <iostream>
using namespace std;

// ���󹹼�
class Component
{
public:
    virtual void dispaly() = 0;
};

// ������
class Window : public Component
{
public:
    void dispaly()
    {
        cout << "���ڣ�" << endl;
    }
};

// �ı�����
class TextBox : public Component
{
public:
    void dispaly()
    {
        cout << "�ı���" << endl;
    }
};

// �б����
class ListBox : public Component
{
public:
    void dispaly()
    {
        cout << "�б��" << endl;
    }
};

// ����װ����
class ComponentDecorator : public Component
{
private:
    Component *component;

public:
    ComponentDecorator(Component *component)
    {
        this->component = component;
    }
    void dispaly()
    {
        component->dispaly();
    }
};

// ������װ����
class ScrollBarDecorator : public ComponentDecorator
{
public:
    ScrollBarDecorator(Component *component) : ComponentDecorator(component) {}
    void dispaly()
    {
        setScrollBar();
        ComponentDecorator::dispaly();
    }
    void setScrollBar()
    {
        cout << "Ϊ�������ӹ�������" << endl;
    }
};

// ��ɫ�߿�װ����
class BlackBorderDecorator : public ComponentDecorator
{
public:
    BlackBorderDecorator(Component *component) : ComponentDecorator(component) {}
    void dispaly()
    {
        setBlackBorder();
        ComponentDecorator::dispaly();
    }
    void setBlackBorder()
    {
        cout << "Ϊ�������Ӻ�ɫ�߿�" << endl;
    }
};

// �ͻ���
int main()
{
    Component *component;
    Component *componentA;
    component = new Window();
    componentA = new ScrollBarDecorator(component);
    componentA->dispaly();
    component = new TextBox();
    componentA = new ScrollBarDecorator(component);
    componentA->dispaly();
    delete componentA;
    delete component;
    return 0;
}