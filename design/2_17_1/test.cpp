#include <iostream>
#include <memory>
#include <string>
using namespace std;

// ������ʽ�ڵ����
class AbstractNode
{
public:
    virtual ~AbstractNode() = default;
    virtual string interpret() = 0; // ���麯�����������ʵ�ֽ����߼�
};

// ����ڵ㣨�ս�����ʽ��
class DirectionNode : public AbstractNode
{
private:
    string direction;

public:
    explicit DirectionNode(const string &dir) : direction(dir) {}
    string interpret() override
    {
        return "����[" + direction + "]";
    }
};

// �����ڵ㣨�ս�����ʽ��
class ActionNode : public AbstractNode
{
private:
    string action;

public:
    explicit ActionNode(const string &act) : action(act) {}
    string interpret() override
    {
        return "����[" + action + "]";
    }
};

// ����ڵ㣨�ս�����ʽ��
class DistanceNode : public AbstractNode
{
private:
    string distance;

public:
    explicit DistanceNode(const string &dist) : distance(dist) {}
    string interpret() override
    {
        return "����[" + distance + "��]";
    }
};

// ����AND�ڵ㣨���ս�����ʽ��
class AndNode : public AbstractNode
{
private:
    shared_ptr<AbstractNode> left;
    shared_ptr<AbstractNode> right;

public:
    AndNode(shared_ptr<AbstractNode> l, shared_ptr<AbstractNode> r)
        : left(l), right(r) {}
    string interpret() override
    {
        return left->interpret() + " Ȼ�� " + right->interpret();
    }
};

// ���ӽڵ㣨��϶���ս�����ʽ��
class SentenceNode : public AbstractNode
{
private:
    shared_ptr<AbstractNode> direction;
    shared_ptr<AbstractNode> action;
    shared_ptr<AbstractNode> distance;

public:
    SentenceNode(shared_ptr<AbstractNode> dir,
                 shared_ptr<AbstractNode> act,
                 shared_ptr<AbstractNode> dist)
        : direction(dir), action(act), distance(dist) {}
    string interpret() override
    {
        return direction->interpret() + " " +
               action->interpret() + " " +
               distance->interpret();
    }
};

// ָ������������������ṹ��
class InstructionHandler
{
private:
    shared_ptr<AbstractNode> nodeTree;

public:
    // ����ָ��ṹ���˴��򻯽����߼���
    void handle(const string &instruction)
    {
        // ʾ�������߼�����������Ϊ "�� �� 100"
        auto direction = make_shared<DirectionNode>("��");
        auto action = make_shared<ActionNode>("��");
        auto distance = make_shared<DistanceNode>("100");

        // ��ϳɸ��Ͻṹ
        nodeTree = make_shared<SentenceNode>(direction, action, distance);
    }

    string interpret()
    {
        if (nodeTree)
        {
            return nodeTree->interpret();
        }
        return "ָ��δ��ʼ��";
    }
};

int main()
{
    // ʾ���÷�
    InstructionHandler handler;
    handler.handle("�� �� 100"); // ʵ�ʳ�����Ҫ�����ӵĽ����߼�
    cout << handler.interpret() << endl;

    // ����AND�ڵ����
    auto dir1 = make_shared<DirectionNode>("��");
    auto act1 = make_shared<ActionNode>("��");
    auto dist1 = make_shared<DistanceNode>("50");
    auto sentence1 = make_shared<SentenceNode>(dir1, act1, dist1);

    auto dir2 = make_shared<DirectionNode>("��");
    auto act2 = make_shared<ActionNode>("��");
    auto dist2 = make_shared<DistanceNode>("2");
    auto sentence2 = make_shared<SentenceNode>(dir2, act2, dist2);

    AndNode andNode(sentence1, sentence2);
    cout << andNode.interpret() << endl;

    return 0;
}