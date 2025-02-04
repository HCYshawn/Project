#include <iostream>
#include <string>
using namespace std;

// 前置声明
class RealSearcher;

// 抽象主题接口
class Searcher
{
public:
    virtual string DoSearch(const string &userId, const string &keyword) = 0;
    virtual ~Searcher() = default;
};

// 真实主题类
class RealSearcher : public Searcher
{
public:
    string DoSearch(const string &userId, const string &keyword) override
    {
        // 模拟搜索操作
        return "搜索结果: " + keyword; // 返回搜索结果
    }
};

// 访问验证类
class AccessValidator
{
public:
    bool Validate(const string &userId)
    {
        // 模拟访问验证
        if (userId == "validUser") // 验证用户是否为有效用户
        {
            return true;
        }
        return false;
    }
};

// 日志记录类
class Logger
{
public:
    void Log(const string &userId)
    {
        // 模拟日志记录
        cout << "日志: 用户 " << userId << " 执行搜索 " << endl; // 记录日志
    }
};

// 代理类
class ProxySearcher : public Searcher
{
private:
    RealSearcher *realsearcher;
    AccessValidator *validator;
    Logger *logger;

public:
    ProxySearcher()
    {
        realsearcher = new RealSearcher();
        validator = new AccessValidator();
        logger = new Logger();
    }

    ~ProxySearcher()
    {
        delete realsearcher;
        delete validator;
        delete logger;
    }

    string DoSearch(const string &userId, const string &keyword) override
    {
        if (Validate(userId))
        {
            string result = realsearcher->DoSearch(userId, keyword); // 调用真实主题对象的查询方法
            Log(userId);                                             // 记录查询日志
            return result;                                           // 返回查询结果
        }
        else
        {
            return "用户 " + userId + " 访问被拒绝 ";
        }
    }

private:
    bool Validate(const string &userId)
    {
        return validator->Validate(userId);
    }

    void Log(const string &userId)
    {
        logger->Log(userId);
    }
};

// 客户端代码
int main()
{
    Searcher *searcher = new ProxySearcher();
    string userId1 = "validUser";       // 用户名1
    string userId2 = "hehe";            // 用户名2
    string keyword = "design patterns"; // 搜索关键字
    string result1 = searcher->DoSearch(userId1, keyword);
    string result2 = searcher->DoSearch(userId2, keyword);
    cout << result1 << endl;
    cout << result2 << endl;

    delete searcher;
    return 0;
}