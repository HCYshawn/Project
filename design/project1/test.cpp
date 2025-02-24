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