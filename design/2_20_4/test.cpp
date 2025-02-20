#include <iostream>
#include <vector>
#include <memory>
using namespace std;

// 前向声明具体元素类
class ConcreteElementA;
class ConcreteElementB;

// 抽象访问者类
class Visitor
{
public:
    virtual void visitConcreteElementA(ConcreteElementA *element) = 0;
    virtual void visitConcreteElementB(ConcreteElementB *element) = 0;
    virtual ~Visitor() = default;
};

// 抽象元素类
class Element
{
public:
    virtual void accept(Visitor *visitor) = 0; // 接受访问者的访问
    virtual ~Element() = default;
};

// 具体元素A
class ConcreteElementA : public Element
{
public:
    void accept(Visitor *visitor) override
    {
        visitor->visitConcreteElementA(this); // 调用访问者的对应方法
    }
    void operationA()
    {
        cout << "执行ConcreteElementA的operationA操作" << endl;
    }
};

// 具体元素B
class ConcreteElementB : public Element
{
public:
    void accept(Visitor *visitor) override
    {
        visitor->visitConcreteElementB(this); // 调用访问者的对应方法
    }
    void operationB()
    {
        cout << "执行ConcreteElementB的operationB操作" << endl;
    }
};

// 具体访问者A
class ConcreteVisitorA : public Visitor
{
public:
    void visitConcreteElementA(ConcreteElementA *element) override
    {
        cout << "ConcreteVisitorA正在访问ConcreteElementA: ";
        element->operationA();
    }
    void visitConcreteElementB(ConcreteElementB *element) override
    {
        cout << "ConcreteVisitorA正在访问ConcreteElementB: ";
        element->operationB();
    }
};

// 具体访问者B
class ConcreteVisitorB : public Visitor
{
public:
    void visitConcreteElementA(ConcreteElementA *element) override
    {
        cout << "ConcreteVisitorB正在访问ConcreteElementA: ";
        element->operationA();
    }
    void visitConcreteElementB(ConcreteElementB *element) override
    {
        cout << "ConcreteVisitorB正在访问ConcreteElementB: ";
        element->operationB();
    }
};

// 对象结构类（管理元素集合）
class ObjectStructure
{
private:
    vector<Element *> elements; // 存储元素的容器

public:
    void addElement(Element *element)
    {
        elements.push_back(element);
    }

    void accept(Visitor *visitor)
    {
        for (auto element : elements)
        {
            element->accept(visitor); // 每个元素接受访问者的访问
        }
    }
};

// 客户端代码
int main()
{
    ObjectStructure structure;

    // 创建具体元素对象
    ConcreteElementA elementA;
    ConcreteElementB elementB;

    // 将元素添加到对象结构中
    structure.addElement(&elementA);
    structure.addElement(&elementB);

    // 创建具体访问者对象
    ConcreteVisitorA visitorA;
    ConcreteVisitorB visitorB;

    // 访问者访问对象结构中的元素
    cout << "--- 访问者A的操作 ---" << endl;
    structure.accept(&visitorA);

    cout << "\n--- 访问者B的操作 ---" << endl;
    structure.accept(&visitorB);

    return 0;
}