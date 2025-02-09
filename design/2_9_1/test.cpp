#include <iostream>
#include <memory> // 用于智能指针管理内存
using namespace std;

// 抽象折扣策略接口
class Discount
{
public:
    virtual double calculate(double price) = 0; // 计算折扣后的价格
    virtual ~Discount() = default;              // 虚析构确保正确释放子类对象
};

// 具体策略类：学生折扣（8折）
class StudentDiscount : public Discount
{
public:
    double calculate(double price) override
    {
        return price * 0.8;
    }
};

// 具体策略类：VIP折扣（5折）
class VIPDiscount : public Discount
{
public:
    double calculate(double price) override
    {
        return price * 0.5;
    }
};

// 具体策略类：儿童折扣（6折）
class ChildrenDiscount : public Discount
{
public:
    double calculate(double price) override
    {
        return price * 0.6;
    }
};

// 电影票类（上下文类）
class MovieTicket
{
private:
    double price;                  // 原始价格
    unique_ptr<Discount> discount; // 当前折扣策略（使用智能指针管理）

public:
    MovieTicket() : price(0.0) {}

    // 设置原始价格
    void setPrice(double p)
    {
        price = p;
    }

    // 设置折扣策略（通过智能指针传递所有权）
    void setDiscount(unique_ptr<Discount> d)
    {
        discount = move(d);
    }

    // 获取折扣后的价格
    double getPrice()
    {
        if (discount)
        {
            return discount->calculate(price);
        }
        else
        {
            return price; // 无折扣
        }
    }
};

// 客户端代码
int main()
{
    MovieTicket ticket;
    ticket.setPrice(100.0); // 设置原始价格为100元

    // 应用学生折扣
    ticket.setDiscount(make_unique<StudentDiscount>());
    cout << "学生折扣价格: " << ticket.getPrice() << "元" << endl; // 输出80元

    // 切换为VIP折扣
    ticket.setDiscount(make_unique<VIPDiscount>());
    cout << "VIP折扣价格: " << ticket.getPrice() << "元" << endl; // 输出50元

    // 切换为儿童折扣
    ticket.setDiscount(make_unique<ChildrenDiscount>());
    cout << "儿童折扣价格: " << ticket.getPrice() << "元" << endl; // 输出60元

    // 无折扣情况
    ticket.setDiscount(nullptr);
    cout << "无折扣价格: " << ticket.getPrice() << "元" << endl; // 输出100元

    return 0;
}