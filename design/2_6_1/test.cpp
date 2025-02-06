#include <iostream>
#include <string>
using namespace std;

// 采购请求类
class PurchaseRequest
{
private:
    double amount;  // 采购金额
    int number;     // 采购单编号
    string purpose; // 采购目的

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

// 抽象审批者类
class Approver
{
protected:
    Approver *successor; // 后继处理对象
    string name;

public:
    Approver(const string &name) : name(name), successor(nullptr) {}
    virtual ~Approver() {}

    void setSuccessor(Approver *succ)
    {
        successor = succ;
    }

    virtual void processRequest(const PurchaseRequest &request) = 0; // 纯虚函数
};

// 具体审批者：主任
class Director : public Approver
{
public:
    Director(const string &name) : Approver(name) {}

    void processRequest(const PurchaseRequest &request) override
    {
        if (request.getAmount() < 5000)
        { // 假设主任处理5000元以下的请求
            cout << "主任" << name << "审批采购单："
                 << request.getNumber() << "，金额："
                 << request.getAmount() << "元，目的："
                 << request.getPurpose() << endl;
        }
        else if (successor != nullptr)
        {
            successor->processRequest(request);
        }
    }
};

// 具体审批者：副总裁
class VicePresident : public Approver
{
public:
    VicePresident(const string &name) : Approver(name) {}

    void processRequest(const PurchaseRequest &request) override
    {
        if (request.getAmount() < 10000)
        { // 处理10000元以下的请求
            cout << "副总裁" << name << "审批采购单："
                 << request.getNumber() << "，金额："
                 << request.getAmount() << "元，目的："
                 << request.getPurpose() << endl;
        }
        else if (successor != nullptr)
        {
            successor->processRequest(request);
        }
    }
};

// 具体审批者：总裁
class President : public Approver
{
public:
    President(const string &name) : Approver(name) {}

    void processRequest(const PurchaseRequest &request) override
    {
        if (request.getAmount() < 50000)
        { // 处理50000元以下的请求
            cout << "总裁" << name << "审批采购单："
                 << request.getNumber() << "，金额："
                 << request.getAmount() << "元，目的："
                 << request.getPurpose() << endl;
        }
        else if (successor != nullptr)
        {
            successor->processRequest(request);
        }
    }
};

// 具体审批者：董事会
class Congress : public Approver
{
public:
    Congress(const string &name) : Approver(name) {}

    void processRequest(const PurchaseRequest &request) override
    {
        cout << "董事会" << name << "审批采购单："
             << request.getNumber() << "，金额："
             << request.getAmount() << "元，目的："
             << request.getPurpose() << endl;
    }
};

int main()
{
    // 创建审批链
    Approver *director = new Director("张主任");
    Approver *vicePresident = new VicePresident("李副总裁");
    Approver *president = new President("王总裁");
    Approver *congress = new Congress("董事会");

    // 设置责任链
    director->setSuccessor(vicePresident);
    vicePresident->setSuccessor(president);
    president->setSuccessor(congress);

    // 创建采购请求
    PurchaseRequest req1(4000, 1001, "购买办公用品");
    PurchaseRequest req2(8000, 1002, "购买服务器");
    PurchaseRequest req3(45000, 1003, "建设数据中心");
    PurchaseRequest req4(100000, 1004, "收购子公司");

    // 处理请求
    director->processRequest(req1);
    director->processRequest(req2);
    director->processRequest(req3);
    director->processRequest(req4);

    // 清理内存
    delete director;
    delete vicePresident;
    delete president;
    delete congress;

    return 0;
}