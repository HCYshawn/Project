#include <iostream>
#include <string>
using namespace std;

// �����˻��ࣺ����ģ�巽������
class Account
{
public:
    // ģ�巽�������������Ϣ�����̣���֤�˻� -> ������Ϣ��
    void CalculateInterest()
    {
        if (Validate())
        {
            doCalculateInterest(); // ���þ�������ʵ�ֵ���Ϣ����
        }
        else
        {
            cout << "�˻���֤ʧ�ܣ��޷�������Ϣ��" << endl;
        }
    }

    // ��֤�˻������岽��������ʵ�֣�
    virtual bool Validate() = 0;

    // ����������ȷ����ȷ�ͷ���Դ
    virtual ~Account() = default;

protected:
    // ʵ�ʼ�����Ϣ�Ĳ��裨������ʵ�֣�
    virtual void doCalculateInterest() = 0;
};

// �����˻��ࣺ�̳� Account��ʵ�־��岽��
class SavingsAccount : public Account
{
public:
    SavingsAccount(const string &accountNumber, double balance)
        : accountNumber_(accountNumber), balance_(balance) {}

    // ʵ���˻���֤�߼�
    bool Validate() override
    {
        // ����֤���˻��ų�����Ϊ10λ��������0
        return (accountNumber_.length() == 10 && balance_ > 0);
    }

protected:
    // ʵ�ִ����˻�����Ϣ�����߼���������1.5%��
    void doCalculateInterest() override
    {
        double interest = balance_ * 0.015;
        cout << "�����˻���Ϣ��������" << interest << "Ԫ" << endl;
    }

private:
    string accountNumber_;
    double balance_;
};

// �����˻��ࣺ�̳� Account��ʵ�־��岽��
class CurrentAccount : public Account
{
public:
    CurrentAccount(const string &accountNumber, double balance)
        : accountNumber_(accountNumber), balance_(balance) {}

    // ʵ���˻���֤�߼�
    bool Validate() override
    {
        // ����֤���˻��ų�����Ϊ8λ��������100
        return (accountNumber_.length() == 8 && balance_ >= 100);
    }

protected:
    // ʵ�ֻ����˻�����Ϣ�����߼���������0.5%��
    void doCalculateInterest() override
    {
        double interest = balance_ * 0.005;
        cout << "�����˻���Ϣ��������" << interest << "Ԫ" << endl;
    }

private:
    string accountNumber_;
    double balance_;
};

// �ͻ��˴���
int main()
{
    // ���������˻���������Ϣ
    Account *savingsAccount = new SavingsAccount("1234567890", 5000);
    savingsAccount->CalculateInterest(); // ����������˻���Ϣ��������75Ԫ

    // ���������˻���������Ϣ
    Account *currentAccount = new CurrentAccount("ABCD1234", 200);
    currentAccount->CalculateInterest(); // ����������˻���Ϣ��������1Ԫ

    // ��֤ʧ�ܵİ���
    Account *invalidAccount = new CurrentAccount("1234", 50);
    invalidAccount->CalculateInterest(); // ������˻���֤ʧ�ܣ��޷�������Ϣ��

    delete savingsAccount;
    delete currentAccount;
    delete invalidAccount;
    return 0;
}