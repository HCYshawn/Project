#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cstring>
using namespace std;

// 登录方式基类
class LoginWay
{
public:
    string userName;
    string passWord;
    string phoneNum;

    string getPassword()
    {
        return passWord;
    }
    void setPassword(string password)
    {
        this->passWord = password;

        cout << "password :" << this->passWord << endl;
    }
    virtual string getLoginNameorNum() = 0;
};

// 用户名密码登录
class UserAndPassWord : public LoginWay
{
public:
    UserAndPassWord() {}
    UserAndPassWord(string name, string password)
    {
        this->userName = name;
        this->passWord = password;
    }
    string getUserName()
    {
        return userName;
    }
    void setUserName(string username)
    {
        this->userName = username;
    }
    string getLoginNameorNum()
    {
        return getUserName();
    }
};

// 手机号密码登录
class PhoneAndPassWord : public LoginWay
{
public:
    PhoneAndPassWord() {}
    PhoneAndPassWord(string phone, string password)
    {
        this->phoneNum = phone;
        this->passWord = password;
    }
    string getPhoneNum()
    {
        return phoneNum;
    }
    void setPhoneNum(string pn)
    {
        this->phoneNum = pn;
    }
    string getLoginNameorNum()
    {
        return getPhoneNum();
    }
};

// 登录方式基类
class LoginUser
{
private:
    LoginUser *luser;

public:
    void setUser(LoginUser *lu)
    {
        this->luser = lu;
    }
    bool HandleLoginUser(LoginWay *uPw)
    {
        cout << "LoginUser handle: " << uPw << endl;
        if (uPw == NULL)
        {
            return false;
        }

        // 验证登录是否成功
        cout << "luser " << this << " uPw: " << uPw << endl;
        if (this->loginSuccess(uPw))
        {
            cout << "login success" << endl;
            return true;
        }
        else
        {
            // 验证失败，使用下一个登录方式
            // 如当前登录方式是用户名密码登录，则使用手机号密码登录
            return luser != NULL && luser->HandleLoginUser(uPw);
        }
    }
    virtual bool loginSuccess(LoginWay *uPw) = 0;
};

// 用户名密码登录————登录方式1
class LoginUserAndPassWord : public LoginUser
{
public:
    bool loginSuccess(LoginWay *uPw)
    {
        cout << "this a way to login by UserAndPassWord" << endl;
        string username = uPw->getLoginNameorNum();
        string password = uPw->getPassword();
        cout << "user: " << username << "password: " << password << endl;
        cout << "user strcmp: " << strcmp(username.c_str(), "xml")
             << "password strcmp: " << strcmp(password.c_str(), "123456")
             << endl;
        if (strcmp(username.c_str(), "xml") == 0 && strcmp(password.c_str(), "123456") == 0)
        {
            return true;
        }

        return false;
    }
};

// 手机号密码登录————登录方式2
class LoginPhoneAndPassWord : public LoginUser
{
public:
    bool loginSuccess(LoginWay *uPw)
    {
        cout << "this a way to login by PhoneAndPassWord" << endl;
        string phone = uPw->getLoginNameorNum();
        string password = uPw->getPassword();
        cout << "phone: " << phone << "password: " << password << endl;
        cout << "phone strcmp: " << strcmp(phone.c_str(), "18888")
             << "password strcmp: " << strcmp(password.c_str(), "123456")
             << endl;
        if (strcmp(phone.c_str(), "18888") == 0 && strcmp(password.c_str(), "123456") == 0)
        {
            return true;
        }

        return false;
    }
};

// 登录方式管理类，形成责任链 单例模式
class LoginManager
{
public:
    vector<LoginUser *> lus;

    LoginManager()
    {
        LoginUser *lu1 = new LoginUserAndPassWord();
        LoginUser *lu2 = new LoginPhoneAndPassWord();
        // 用户名密码登录
        lus.push_back(lu1);
        // 手机号密码登录
        lus.push_back(lu2);

        // 设置登录方式的顺序
        for (int i = 0; i < lus.size(); i++)
        {
            LoginUser *secondLu = lus[i + 1];
            if (secondLu != NULL)
            {
                cout << "lu1: " << lu1 << "lu2: " << lu2 << "secondLu:" << secondLu << endl;
                lus[i]->setUser(secondLu);
            }
        }
    }

    static LoginManager *instance;
    static LoginManager *getInstance()
    {
        if (instance == NULL)
        {
            instance = new LoginManager();
        }
        return instance;
    }

public:
    bool handLoginManagere(LoginWay *uPw)
    {
        cout << "lus size: " << lus.size() << endl;
        if (lus.size() == 0)
        {
            return false;
        }
        return lus[0]->HandleLoginUser(uPw);
    }
};

// 登录主题接口
class ObjectUser
{
public:
    // 登录
    virtual bool login(LoginWay *lw) = 0;
    // 验证是否登录
    virtual bool isLogin() = 0;
};

// xml登录主题
class XMLObjectUser : public ObjectUser
{
private:
    LoginWay *lw;

public:
    bool login(LoginWay *lw)
    {
        // 设置用户密码
        string password = "123456";
        lw->setPassword(password);

        // 调用LoginManager()方法触发责任链
        if (LoginManager::getInstance()->handLoginManagere(lw))
        {
            cout << "登录成功" << endl;

            this->lw = lw;
            return true;
        }
        return false;
    }

    bool isLogin()
    {
        return lw != NULL;
    }
    string getUserName()
    {
        return lw->getLoginNameorNum();
    }
};

// 提供全局获取ObjectUser的方法
class MainEntrance
{
public:
    static XMLObjectUser *xml;
    static unordered_map<string, XMLObjectUser *> xmlOU;

    // 获取当前请求的用户信息
    static XMLObjectUser *getXMLSubject()
    {
        string name = "xml";

        // 查找是否存在该用户
        for (auto xxmm : xmlOU)
        {
            auto it = xmlOU.find(name);
            if (it != xmlOU.end())
            {
                return it->second;
            }
        }
        cout << "xml ? " << (xml) << endl;

        return (xml == NULL) ? (xml = new XMLObjectUser()) : xml;
    }

    static void addXMLObjectUser(string s, XMLObjectUser *xmlObject)
    {
        xmlOU.emplace(s, xmlObject);
    }
};

LoginManager *LoginManager::instance = new LoginManager();
XMLObjectUser *MainEntrance::xml;
unordered_map<string, XMLObjectUser *> MainEntrance::xmlOU{{"xml", new XMLObjectUser()}, {"xml1", new XMLObjectUser()}};
int main()
{
    MainEntrance::addXMLObjectUser("xml", new XMLObjectUser());
    MainEntrance::addXMLObjectUser("18888", new XMLObjectUser());

    XMLObjectUser *currentUser = MainEntrance::getXMLSubject();
    cout << "是否已经登录？ " << currentUser->isLogin() << endl;
    currentUser->login(new UserAndPassWord("xml", "123456"));
    cout << "是否已经登录？ " << currentUser->isLogin() << endl;
    currentUser->login(new PhoneAndPassWord("18888", "123456"));
    cout << "是否已经登录？ " << currentUser->isLogin() << endl;
    return 0;
}