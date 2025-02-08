#include <iostream>
#include <string>
using namespace std;

// 抽象账户类：定义模板方法流程
class Account
{
public:
    // 模板方法：定义计算利息的流程（验证账户 -> 计算利息）
    void CalculateInterest()
    {
        if (Validate())
        {
            doCalculateInterest(); // 调用具体子类实现的利息计算
        }
        else
        {
            cout << "账户验证失败，无法计算利息！" << endl;
        }
    }

    // 验证账户（具体步骤由子类实现）
    virtual bool Validate() = 0;

    // 虚析构函数确保正确释放资源
    virtual ~Account() = default;

protected:
    // 实际计算利息的步骤（由子类实现）
    virtual void doCalculateInterest() = 0;
};

// 储蓄账户类：继承 Account，实现具体步骤
class SavingsAccount : public Account
{
public:
    SavingsAccount(const string &accountNumber, double balance)
        : accountNumber_(accountNumber), balance_(balance) {}

    // 实现账户验证逻辑
    bool Validate() override
    {
        // 简单验证：账户号长度需为10位且余额大于0
        return (accountNumber_.length() == 10 && balance_ > 0);
    }

protected:
    // 实现储蓄账户的利息计算逻辑（年利率1.5%）
    void doCalculateInterest() override
    {
        double interest = balance_ * 0.015;
        cout << "储蓄账户利息计算结果：" << interest << "元" << endl;
    }

private:
    string accountNumber_;
    double balance_;
};

// 活期账户类：继承 Account，实现具体步骤
class CurrentAccount : public Account
{
public:
    CurrentAccount(const string &accountNumber, double balance)
        : accountNumber_(accountNumber), balance_(balance) {}

    // 实现账户验证逻辑
    bool Validate() override
    {
        // 简单验证：账户号长度需为8位且余额大于100
        return (accountNumber_.length() == 8 && balance_ >= 100);
    }

protected:
    // 实现活期账户的利息计算逻辑（年利率0.5%）
    void doCalculateInterest() override
    {
        double interest = balance_ * 0.005;
        cout << "活期账户利息计算结果：" << interest << "元" << endl;
    }

private:
    string accountNumber_;
    double balance_;
};

// 客户端代码
int main()
{
    // 创建储蓄账户并计算利息
    Account *savingsAccount = new SavingsAccount("1234567890", 5000);
    savingsAccount->CalculateInterest(); // 输出：储蓄账户利息计算结果：75元

    // 创建活期账户并计算利息
    Account *currentAccount = new CurrentAccount("ABCD1234", 200);
    currentAccount->CalculateInterest(); // 输出：活期账户利息计算结果：1元

    // 验证失败的案例
    Account *invalidAccount = new CurrentAccount("1234", 50);
    invalidAccount->CalculateInterest(); // 输出：账户验证失败，无法计算利息！

    delete savingsAccount;
    delete currentAccount;
    delete invalidAccount;
    return 0;
}