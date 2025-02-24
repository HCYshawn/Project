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