#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

//��Ϣ��
class Info
{
private:
	string company;		//��˾����
	string projectname;	//��Ŀ����
public:
	void setcompany(string company)
	{
		this->company = company;
	}
	void setprojectname(string projectname)
	{
		this->projectname = projectname;
	}
	string getcompany()
	{
		return this->company;
	}
	string getprojectname()
	{
		return this->projectname;
	}
	void print()
	{
		cout << company << "\n" << projectname << endl;
	}
};

//����������
class Builder
{
protected:
	Info* info = new Info();
public:
	virtual void buildercompany() = 0;
	virtual void builderproject() = 0;
	Info* getinfo()
	{
		return info;
	}
};

//����A
class BuilderA :public Builder
{
	void buildercompany()
	{
		info->setcompany("��˾A");
	}
	void builderproject()
	{
		info->setprojectname("��ĿA");
	}
};

//����B
class BuilderB :public Builder
{
	void buildercompany()
	{
		info->setcompany("��˾B");
	}
	void builderproject()
	{
		info->setprojectname("��ĿB");
	}
};

//����C
class BuilderC :public Builder
{
	void buildercompany()
	{
		info->setcompany("��˾C");
	}
	void builderproject()
	{
		info->setprojectname("��ĿC");
	}
};

//�����ն�
class control
{
public:
	Info* setinfo(Builder* b)
	{
		Info* info;
		b->buildercompany();
		b->builderproject();
		info = b->getinfo();
		return info;
	}
};


int main()
{
	control x;
	Builder* A = new BuilderA();
	Builder* B = new BuilderB();
	Builder* C = new BuilderC();
	Info* a = x.setinfo(A);
	Info* b = x.setinfo(B);
	Info* c = x.setinfo(C);
	a->print();
	b->print();
	c->print();

	delete A;
	delete B;
	delete C;
	delete a;
	delete b;
	delete c;
	return 0;
}