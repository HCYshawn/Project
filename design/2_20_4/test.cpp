#include <iostream>
#include <vector>
#include <memory>
using namespace std;

// ǰ����������Ԫ����
class ConcreteElementA;
class ConcreteElementB;

// �����������
class Visitor
{
public:
    virtual void visitConcreteElementA(ConcreteElementA *element) = 0;
    virtual void visitConcreteElementB(ConcreteElementB *element) = 0;
    virtual ~Visitor() = default;
};

// ����Ԫ����
class Element
{
public:
    virtual void accept(Visitor *visitor) = 0; // ���ܷ����ߵķ���
    virtual ~Element() = default;
};

// ����Ԫ��A
class ConcreteElementA : public Element
{
public:
    void accept(Visitor *visitor) override
    {
        visitor->visitConcreteElementA(this); // ���÷����ߵĶ�Ӧ����
    }
    void operationA()
    {
        cout << "ִ��ConcreteElementA��operationA����" << endl;
    }
};

// ����Ԫ��B
class ConcreteElementB : public Element
{
public:
    void accept(Visitor *visitor) override
    {
        visitor->visitConcreteElementB(this); // ���÷����ߵĶ�Ӧ����
    }
    void operationB()
    {
        cout << "ִ��ConcreteElementB��operationB����" << endl;
    }
};

// ���������A
class ConcreteVisitorA : public Visitor
{
public:
    void visitConcreteElementA(ConcreteElementA *element) override
    {
        cout << "ConcreteVisitorA���ڷ���ConcreteElementA: ";
        element->operationA();
    }
    void visitConcreteElementB(ConcreteElementB *element) override
    {
        cout << "ConcreteVisitorA���ڷ���ConcreteElementB: ";
        element->operationB();
    }
};

// ���������B
class ConcreteVisitorB : public Visitor
{
public:
    void visitConcreteElementA(ConcreteElementA *element) override
    {
        cout << "ConcreteVisitorB���ڷ���ConcreteElementA: ";
        element->operationA();
    }
    void visitConcreteElementB(ConcreteElementB *element) override
    {
        cout << "ConcreteVisitorB���ڷ���ConcreteElementB: ";
        element->operationB();
    }
};

// ����ṹ�ࣨ����Ԫ�ؼ��ϣ�
class ObjectStructure
{
private:
    vector<Element *> elements; // �洢Ԫ�ص�����

public:
    void addElement(Element *element)
    {
        elements.push_back(element);
    }

    void accept(Visitor *visitor)
    {
        for (auto element : elements)
        {
            element->accept(visitor); // ÿ��Ԫ�ؽ��ܷ����ߵķ���
        }
    }
};

// �ͻ��˴���
int main()
{
    ObjectStructure structure;

    // ��������Ԫ�ض���
    ConcreteElementA elementA;
    ConcreteElementB elementB;

    // ��Ԫ����ӵ�����ṹ��
    structure.addElement(&elementA);
    structure.addElement(&elementB);

    // ������������߶���
    ConcreteVisitorA visitorA;
    ConcreteVisitorB visitorB;

    // �����߷��ʶ���ṹ�е�Ԫ��
    cout << "--- ������A�Ĳ��� ---" << endl;
    structure.accept(&visitorA);

    cout << "\n--- ������B�Ĳ��� ---" << endl;
    structure.accept(&visitorB);

    return 0;
}