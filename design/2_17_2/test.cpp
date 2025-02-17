#include <iostream>
#include <vector>
#include <memory>
using namespace std;

//------------------------ ����������ӿ� ------------------------//
class Iterator
{
public:
    virtual ~Iterator() = default;
    virtual void first() = 0;            // ���õ���ʼλ��
    virtual void next() = 0;             // �ƶ�����һ��Ԫ��
    virtual bool hasNext() const = 0;    // �ж��Ƿ�ɼ�������
    virtual int currentItem() const = 0; // ��ȡ��ǰԪ�أ���intΪ����
};

//------------------------ �ۺϳ���ӿ� ------------------------//
class Aggregate
{
public:
    virtual ~Aggregate() = default;
    virtual unique_ptr<Iterator> createIterator() = 0;
};

//------------------------ ����ۺ��ࣨ�������ݼ��ϣ� ------------------------//
class ConcreteAggregate : public Aggregate
{
private:
    vector<int> data_; // �洢��������

public:
    // ���������
    void add(int value)
    {
        data_.push_back(value);
    }

    // ʵ�ִ����������ķ���
    unique_ptr<Iterator> createIterator() override;

    // �ṩ���ݷ��ʽӿڣ�����������ʹ�ã�
    const vector<int> &getData() const { return data_; }
};

//------------------------ ���������ʵ�� ------------------------//
class ConcreteIterator : public Iterator
{
private:
    const ConcreteAggregate &aggregate_; // �����ۺ϶���
    size_t current_index_;               // ��ǰ����λ��

public:
    explicit ConcreteIterator(const ConcreteAggregate &agg)
        : aggregate_(agg), current_index_(0) {}

    void first() override
    {
        current_index_ = 0; // ���õ���һ��Ԫ��
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
            throw out_of_range("����Խ��");
        return aggregate_.getData()[current_index_];
    }
};

// ʵ�־ۺ���ĵ�������������
unique_ptr<Iterator> ConcreteAggregate::createIterator()
{
    return make_unique<ConcreteIterator>(*this);
}

//------------------------ �������� ------------------------//
int main()
{
    // �����ۺ϶����������
    ConcreteAggregate agg;
    agg.add(10);
    agg.add(20);
    agg.add(30);

    // ����������������
    auto iter = agg.createIterator();
    cout << "�������: ";
    for (iter->first(); iter->hasNext(); iter->next())
    {
        cout << iter->currentItem() << " ";
    }
    cout << endl;

    // �������ʾ��������չ��������
    cout << "�������: ";
    iter->first();
    while (iter->hasNext())
    {
        iter->next(); // ���ߵ����һ��Ԫ��
    }
    for (; iter->hasNext(); /* �Զ����߼� */)
    {
        cout << iter->currentItem() << " ";
        // ��Ҫ��չ������ʵ��������
    }

    return 0;
}