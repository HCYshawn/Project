#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cstring>
using namespace std;

// ��¼��ʽ����
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

// �û��������¼
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

// �ֻ��������¼
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

// ��¼��ʽ����
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

        // ��֤��¼�Ƿ�ɹ�
        cout << "luser " << this << " uPw: " << uPw << endl;
        if (this->loginSuccess(uPw))
        {
            cout << "login success" << endl;
            return true;
        }
        else
        {
            // ��֤ʧ�ܣ�ʹ����һ����¼��ʽ
            // �統ǰ��¼��ʽ���û��������¼����ʹ���ֻ��������¼
            return luser != NULL && luser->HandleLoginUser(uPw);
        }
    }
    virtual bool loginSuccess(LoginWay *uPw) = 0;
};

// �û��������¼����������¼��ʽ1
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

// �ֻ��������¼����������¼��ʽ2
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

// ��¼��ʽ�����࣬�γ������� ����ģʽ
class LoginManager
{
public:
    vector<LoginUser *> lus;

    LoginManager()
    {
        LoginUser *lu1 = new LoginUserAndPassWord();
        LoginUser *lu2 = new LoginPhoneAndPassWord();
        // �û��������¼
        lus.push_back(lu1);
        // �ֻ��������¼
        lus.push_back(lu2);

        // ���õ�¼��ʽ��˳��
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