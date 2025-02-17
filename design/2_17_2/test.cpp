#include <iostream>
#include <vector>
#include <memory>
using namespace std;

//------------------------ 迭代器抽象接口 ------------------------//
class Iterator
{
public:
    virtual ~Iterator() = default;
    virtual void first() = 0;            // 重置到起始位置
    virtual void next() = 0;             // 移动到下一个元素
    virtual bool hasNext() const = 0;    // 判断是否可继续迭代
    virtual int currentItem() const = 0; // 获取当前元素（以int为例）
};

//------------------------ 聚合抽象接口 ------------------------//
class Aggregate
{
public:
    virtual ~Aggregate() = default;
    virtual unique_ptr<Iterator> createIterator() = 0;
};

//------------------------ 具体聚合类（管理数据集合） ------------------------//
class ConcreteAggregate : public Aggregate
{
private:
    vector<int> data_; // 存储具体数据

public:
    // 添加数据项
    void add(int value)
    {
        data_.push_back(value);
    }

    // 实现创建迭代器的方法
    unique_ptr<Iterator> createIterator() override;

    // 提供数据访问接口（仅供迭代器使用）
    const vector<int> &getData() const { return data_; }
};

//------------------------ 具体迭代器实现 ------------------------//
class ConcreteIterator : public Iterator
{
private:
    const ConcreteAggregate &aggregate_; // 关联聚合对象
    size_t current_index_;               // 当前迭代位置

public:
    explicit ConcreteIterator(const ConcreteAggregate &agg)
        : aggregate_(agg), current_index_(0) {}

    void first() override
    {
        current_index_ = 0; // 重置到第一个元素
    }

    void next() override
    {
        if (hasNext())
        {
            ++current_index_;
        }
    }

    bool hasNext() const override
    {
        return current_index_ < aggregate_.getData().size();
    }

    int currentItem() const override
    {
        if (!hasNext())
            throw out_of_range("迭代越界");
        return aggregate_.getData()[current_index_];
    }
};

// 实现聚合类的迭代器创建方法
unique_ptr<Iterator> ConcreteAggregate::createIterator()
{
    return make_unique<ConcreteIterator>(*this);
}

//------------------------ 测试用例 ------------------------//
int main()
{
    // 创建聚合对象并填充数据
    ConcreteAggregate agg;
    agg.add(10);
    agg.add(20);
    agg.add(30);

    // 创建迭代器并遍历
    auto iter = agg.createIterator();
    cout << "正向遍历: ";
    for (iter->first(); iter->hasNext(); iter->next())
    {
        cout << iter->currentItem() << " ";
    }
    cout << endl;

    // 反向遍历示例（需扩展迭代器）
    cout << "反向遍历: ";
    iter->first();
    while (iter->hasNext())
    {
        iter->next(); // 先走到最后一个元素
    }
    for (; iter->hasNext(); /* 自定义逻辑 */)
    {
        cout << iter->currentItem() << " ";
        // 需要扩展迭代器实现逆向功能
    }

    return 0;
}