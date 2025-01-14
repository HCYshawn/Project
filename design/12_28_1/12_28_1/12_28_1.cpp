#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

//证书模板类
class Info
{
public:
	Info(){}
	string getAwards()
	{
		return awards;
	}
	
	string getAwardsclass()
	{
		return awardsclass;
	}

	void setawards(string _awards)
	{
		awards = _awards;
	}

	void setawardsclass(string _class)
	{
		awardsclass = _class;
	}

	//克隆接口
	Info* Clone()
	{
		Info* info = new Info();
		*info = *this;
		return info;
	}

private:
	string awards;
	string awardsclass;

};

//个人信息父类
class Certificate
{
public:
	Certificate(){}
	virtual void Display() = 0;
	virtual void SetInfo(string name, string sex, string college) = 0;
	virtual void SetAwardsInfo(string data, string class_) = 0;
	virtual Certificate* Clone() = 0;
	
protected:
	string name;
	string sex;
	string college;
};

//个人信息子类
class Citation :public Certificate
{
public:
	Citation() = default;
	//设置个人信息
	void SetInfo(string name, string sex, string college)
	{
		this->name = name;
		this->sex = sex;
		this->college = college;
	}
	//设置证书模板
	void SetAwardsInfo(string data, string class_)
	{
		_info->setawards(data);
		_info->setawardsclass(class_);
	}
	void Display()
	{
		cout << name << " " << sex << " " << college << endl;
		cout << _info->getAwards() << " " << _info->getAwardsclass() << endl;
	}

	//克隆接口实现
	Certificate* Clone() override
	{
		Citation* clonecitation = new Citation(_info);
		clonecitation->name = this->name;
		clonecitation->sex = this->sex;
		clonecitation->college = this->college;
		return clonecitation;
	}

private:
	//new模板类
	Info* _info = new Info();
	explicit Citation(Info* info) :_info((Info*)info->Clone()){}
};

int main()
{
	Citation* a = new Citation();
	a->SetInfo("张三", "男", "计算机学院");
	a->SetAwardsInfo("全国计算机竞赛", "二等奖");
	a->Display();

	Citation* b = (Citation*)a->Clone();
	b->SetInfo("李四", "女", "计算机学院");
	b->SetAwardsInfo("全国计算机竞赛", "一等奖");
	b->Display();
	delete a;
	delete b;

	return 0;
}