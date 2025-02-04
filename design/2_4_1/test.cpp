#include <iostream>
using namespace std;

// 子系统A
class SubSystemA
{
public:
    void OperationA()
    {
        cout << "SubSystemA::OperationA" << endl;
    }
};

// 子系统B
class SubSystemB
{
public:
    void OperationB()
    {
        cout << "SubSystemB::OperationB" << endl;
    }
};

// 子系统C
class SubSystemC
{
public:
    void OperationC()
    {
        cout << "SubSystemC::OperationC" << endl;
    }
};

// 外观类
class Facade
{
private:
    SubSystemA *m_subA;
    SubSystemB *m_subB;
    SubSystemC *m_subC;

public:
    Facade(SubSystemA *subA, SubSystemB *subB, SubSystemC *subC)
        : m_subA(subA), m_subB(subB), m_subC(subC)
    {
    }

    ~Facade()
    {
        delete m_subA;
        delete m_subB;
        delete m_subC;
    }

    void Operation()
    {
        m_subA->OperationA();
        m_subB->OperationB();
        m_subC->OperationC();
    }
};

// 客户端
int main()
{
    SubSystemA *subA = new SubSystemA();
    SubSystemB *subB = new SubSystemB();
    SubSystemC *subC = new SubSystemC();

    Facade *facade = new Facade(subA, subB, subC);
    facade->Operation();

    delete facade;
    delete subA;
    delete subB;
    delete subC;
    return 0;
}