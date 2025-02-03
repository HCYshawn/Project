#include <iostream>
using namespace std;

// 抽象构件
class Component
{
public:
    virtual void dispaly() = 0;
};

// 窗口类
class Window : public Component
{
public:
    void dispaly()
    {
        cout << "窗口！" << endl;
    }
};

// 文本框类
class TextBox : public Component
{
public:
    void dispaly()
    {
        cout << "文本框！" << endl;
    }
};

// 列表框类
class ListBox : public Component
{
public:
    void dispaly()
    {
        cout << "列表框！" << endl;
    }
};

// 构件装饰类
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

// 滚动条装饰类
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
        cout << "为构件增加滚动条！" << endl;
    }
};

// 黑色边框装饰类
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
        cout << "为构件增加黑色边框！" << endl;
    }
};

// 客户端
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