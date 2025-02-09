#include <iostream>
#include <memory> // ��������ָ������ڴ�
using namespace std;

// �����ۿ۲��Խӿ�
class Discount
{
public:
    virtual double calculate(double price) = 0; // �����ۿۺ�ļ۸�
    virtual ~Discount() = default;              // ������ȷ����ȷ�ͷ��������
};

// ��������ࣺѧ���ۿۣ�8�ۣ�
class StudentDiscount : public Discount
{
public:
    double calculate(double price) override
    {
        return price * 0.8;
    }
};

// ��������ࣺVIP�ۿۣ�5�ۣ�
class VIPDiscount : public Discount
{
public:
    double calculate(double price) override
    {
        return price * 0.5;
    }
};

// ��������ࣺ��ͯ�ۿۣ�6�ۣ�
class ChildrenDiscount : public Discount
{
public:
    double calculate(double price) override
    {
        return price * 0.6;
    }
};

// ��ӰƱ�ࣨ�������ࣩ
class MovieTicket
{
private:
    double price;                  // ԭʼ�۸�
    unique_ptr<Discount> discount; // ��ǰ�ۿ۲��ԣ�ʹ������ָ�����

public:
    MovieTicket() : price(0.0) {}

    // ����ԭʼ�۸�
    void setPrice(double p)
    {
        price = p;
    }

    // �����ۿ۲��ԣ�ͨ������ָ�봫������Ȩ��
    void setDiscount(unique_ptr<Discount> d)
    {
        discount = move(d);
    }

    // ��ȡ�ۿۺ�ļ۸�
    double getPrice()
    {
        if (discount)
        {
            return discount->calculate(price);
        }
        else
        {
            return price; // ���ۿ�
        }
    }
};

// �ͻ��˴���
int main()
{
    MovieTicket ticket;
    ticket.setPrice(100.0); // ����ԭʼ�۸�Ϊ100Ԫ

    // Ӧ��ѧ���ۿ�
    ticket.setDiscount(make_unique<StudentDiscount>());
    cout << "ѧ���ۿۼ۸�: " << ticket.getPrice() << "Ԫ" << endl; // ���80Ԫ

    // �л�ΪVIP�ۿ�
    ticket.setDiscount(make_unique<VIPDiscount>());
    cout << "VIP�ۿۼ۸�: " << ticket.getPrice() << "Ԫ" << endl; // ���50Ԫ

    // �л�Ϊ��ͯ�ۿ�
    ticket.setDiscount(make_unique<ChildrenDiscount>());
    cout << "��ͯ�ۿۼ۸�: " << ticket.getPrice() << "Ԫ" << endl; // ���60Ԫ

    // ���ۿ����
    ticket.setDiscount(nullptr);
    cout << "���ۿۼ۸�: " << ticket.getPrice() << "Ԫ" << endl; // ���100Ԫ

    return 0;
}