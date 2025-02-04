#include <iostream>
#include <string>
using namespace std;

// ǰ������
class RealSearcher;

// ��������ӿ�
class Searcher
{
public:
    virtual string DoSearch(const string &userId, const string &keyword) = 0;
    virtual ~Searcher() = default;
};

// ��ʵ������
class RealSearcher : public Searcher
{
public:
    string DoSearch(const string &userId, const string &keyword) override
    {
        // ģ����������
        return "�������: " + keyword; // �����������
    }
};

// ������֤��
class AccessValidator
{
public:
    bool Validate(const string &userId)
    {
        // ģ�������֤
        if (userId == "validUser") // ��֤�û��Ƿ�Ϊ��Ч�û�
        {
            return true;
        }
        return false;
    }
};

// ��־��¼��
class Logger
{
public:
    void Log(const string &userId)
    {
        // ģ����־��¼
        cout << "��־: �û� " << userId << " ִ������ " << endl; // ��¼��־
    }
};

// ������
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
            string result = realsearcher->DoSearch(userId, keyword); // ������ʵ�������Ĳ�ѯ����
            Log(userId);                                             // ��¼��ѯ��־
            return result;                                           // ���ز�ѯ���
        }
        else
        {
            return "�û� " + userId + " ���ʱ��ܾ� ";
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

// �ͻ��˴���
int main()
{
    Searcher *searcher = new ProxySearcher();
    string userId1 = "validUser";       // �û���1
    string userId2 = "hehe";            // �û���2
    string keyword = "design patterns"; // �����ؼ���
    string result1 = searcher->DoSearch(userId1, keyword);
    string result2 = searcher->DoSearch(userId2, keyword);
    cout << result1 << endl;
    cout << result2 << endl;

    delete searcher;
    return 0;
}