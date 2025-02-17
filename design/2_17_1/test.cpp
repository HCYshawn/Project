#include <iostream>
#include <memory>
#include <string>
using namespace std;

// 抽象表达式节点基类
class AbstractNode
{
public:
    virtual ~AbstractNode() = default;
    virtual string interpret() = 0; // 纯虚函数，子类必须实现解释逻辑
};

// 方向节点（终结符表达式）
class DirectionNode : public AbstractNode
{
private:
    string direction;

public:
    explicit DirectionNode(const string &dir) : direction(dir) {}
    string interpret() override
    {
        return "方向[" + direction + "]";
    }
};

// 动作节点（终结符表达式）
class ActionNode : public AbstractNode
{
private:
    string action;

public:
    explicit ActionNode(const string &act) : action(act) {}
    string interpret() override
    {
        return "动作[" + action + "]";
    }
};

// 距离节点（终结符表达式）
class DistanceNode : public AbstractNode
{
private:
    string distance;

public:
    explicit DistanceNode(const string &dist) : distance(dist) {}
    string interpret() override
    {
        return "距离[" + distance + "米]";
    }
};

// 复合AND节点（非终结符表达式）
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
        return left->interpret() + " 然后 " + right->interpret();
    }
};

// 句子节点（组合多个终结符表达式）
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

// 指令处理器（构建解释器结构）
class InstructionHandler
{
private:
    shared_ptr<AbstractNode> nodeTree;

public:
    // 构建指令结构（此处简化解析逻辑）
    void handle(const string &instruction)
    {
        // 示例解析逻辑：假设输入为 "左 走 100"
        auto direction = make_shared<DirectionNode>("左");
        auto action = make_shared<ActionNode>("走");
        auto distance = make_shared<DistanceNode>("100");

        // 组合成复合结构
        nodeTree = make_shared<SentenceNode>(direction, action, distance);
    }

    string interpret()
    {
        if (nodeTree)
        {
            return nodeTree->interpret();
        }
        return "指令未初始化";
    }
};

int main()
{
    // 示例用法
    InstructionHandler handler;
    handler.handle("左 走 100"); // 实际场景需要更复杂的解析逻辑
    cout << handler.interpret() << endl;

    // 测试AND节点组合
    auto dir1 = make_shared<DirectionNode>("右");
    auto act1 = make_shared<ActionNode>("跑");
    auto dist1 = make_shared<DistanceNode>("50");
    auto sentence1 = make_shared<SentenceNode>(dir1, act1, dist1);

    auto dir2 = make_shared<DirectionNode>("上");
    auto act2 = make_shared<ActionNode>("跳");
    auto dist2 = make_shared<DistanceNode>("2");
    auto sentence2 = make_shared<SentenceNode>(dir2, act2, dist2);

    AndNode andNode(sentence1, sentence2);
    cout << andNode.interpret() << endl;

    return 0;
}