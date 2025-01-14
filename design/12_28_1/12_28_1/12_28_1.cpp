#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

//֤��ģ����
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

	//��¡�ӿ�
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

//������Ϣ����
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

//������Ϣ����
class Citation :public Certificate
{
public:
	Citation() = default;
	//���ø�����Ϣ
	void SetInfo(string name, string sex, string college)
	{
		this->name = name;
		this->sex = sex;
		this->college = college;
	}
	//����֤��ģ��
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

	//��¡�ӿ�ʵ��
	Certificate* Clone() override
	{
		Citation* clonecitation = new Citation(_info);
		clonecitation->name = this->name;
		clonecitation->sex = this->sex;
		clonecitation->college = this->college;
		return clonecitation;
	}

private:
	//newģ����
	Info* _info = new Info();
	explicit Citation(Info* info) :_info((Info*)info->Clone()){}
};

int main()
{
	Citation* a = new Citation();
	a->SetInfo("����", "��", "�����ѧԺ");
	a->SetAwardsInfo("ȫ�����������", "���Ƚ�");
	a->Display();

	Citation* b = (Citation*)a->Clone();
	b->SetInfo("����", "Ů", "�����ѧԺ");
	b->SetAwardsInfo("ȫ�����������", "һ�Ƚ�");
	b->Display();
	delete a;
	delete b;

	return 0;
}