#include <iostream>
#include <string>
using namespace std;

// �ɹ�������
class PurchaseRequest
{
private:
    double amount;  // �ɹ����
    int number;     // �ɹ������
    string purpose; // �ɹ�Ŀ��

public:
    PurchaseRequest(double amt, int num, const string &purp)
        : amount(amt), number(num), purpose(purp) {}

    void setAmount(double amt) { amount = amt; }
    double getAmount() const { return amount; }

    void setNumber(int num) { number = num; }
    int getNumber() const { return number; }

    void setPurpose(const string &purp) { purpose = purp; }
    string getPurpose() const { return purpose; }
};

// ������������
class Approver
{
protected:
    Approver *successor; // ��̴������
    string name;

public:
    Approver(const string &name) : name(name), successor(nullptr) {}
    virtual ~Approver() {}

    void setSuccessor(Approver *succ)
    {
        successor = succ;
    }

    virtual void processRequest(const PurchaseRequest &request) = 0; // ���麯��
};

// ���������ߣ�����
class Director : public Approver
{
public:
    Director(const string &name) : Approver(name) {}

    void processRequest(const PurchaseRequest &request) override
    {
        if (request.getAmount() < 5000)
        { // �������δ���5000Ԫ���µ�����
            cout << "����" << name << "�����ɹ�����"
                 << request.getNumber() << "����"
                 << request.getAmount() << "Ԫ��Ŀ�ģ�"
                 << request.getPurpose() << endl;
        }
        else if (successor != nullptr)
        {
            successor->processRequest(request);
        }
    }
};

// ���������ߣ����ܲ�
class VicePresident : public Approver
{
public:
    VicePresident(const string &name) : Approver(name) {}

    void processRequest(const PurchaseRequest &request) override
    {
        if (request.getAmount() < 10000)
        { // ����10000Ԫ���µ�����
            cout << "���ܲ�" << name << "�����ɹ�����"
                 << request.getNumber() << "����"
                 << request.getAmount() << "Ԫ��Ŀ�ģ�"
                 << request.getPurpose() << endl;
        }
        else if (successor != nullptr)
        {
            successor->processRequest(request);
        }
    }
};

// ���������ߣ��ܲ�
class President : public Approver
{
public:
    President(const string &name) : Approver(name) {}

    void processRequest(const PurchaseRequest &request) override
    {
        if (request.getAmount() < 50000)
        { // ����50000Ԫ���µ�����
            cout << "�ܲ�" << name << "�����ɹ�����"
                 << request.getNumber() << "����"
                 << request.getAmount() << "Ԫ��Ŀ�ģ�"
                 << request.getPurpose() << endl;
        }
        else if (successor != nullptr)
        {
            successor->processRequest(request);
        }
    }
};

// ���������ߣ����»�
class Congress : public Approver
{
public:
    Congress(const string &name) : Approver(name) {}

    void processRequest(const PurchaseRequest &request) override
    {
        cout << "���»�" << name << "�����ɹ�����"
             << request.getNumber() << "����"
             << request.getAmount() << "Ԫ��Ŀ�ģ�"
             << request.getPurpose() << endl;
    }
};

int main()
{
    // ����������
    Approver *director = new Director("������");
    Approver *vicePresident = new VicePresident("��ܲ�");
    Approver *president = new President("���ܲ�");
    Approver *congress = new Congress("���»�");

    // ����������
    director->setSuccessor(vicePresident);
    vicePresident->setSuccessor(president);
    president->setSuccessor(congress);

    // �����ɹ�����
    PurchaseRequest req1(4000, 1001, "����칫��Ʒ");
    PurchaseRequest req2(8000, 1002, "���������");
    PurchaseRequest req3(45000, 1003, "������������");
    PurchaseRequest req4(100000, 1004, "�չ��ӹ�˾");

    // ��������
    director->processRequest(req1);
    director->processRequest(req2);
    director->processRequest(req3);
    director->processRequest(req4);

    // �����ڴ�
    delete director;
    delete vicePresident;
    delete president;
    delete congress;

    return 0;
}