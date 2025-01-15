#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

//ʵ�ֽ�ɫ�ӿ�
class implementor
{
public:
	virtual ~implementor(){}
	virtual void operationimpl() = 0;
};

//����ʵ�ֽ�ɫ�ӿ�A
class createimplementorA :public implementor
{
public:
	void operationimpl() override
	{
		cout << "I am A" << endl;
	}
};

//����ʵ�ֽ�ɫ�ӿ�B
class createimplementorB :public implementor
{
public:
	void operationimpl() override
	{
		cout << "I am B" << endl;
	}
};

//�����ɫ�ӿ�
class abstraction
{
protected:
	//ά����ָ�룬ͨ����ָ���Ž�
	implementor* _implementor;

public:
	abstraction(implementor* impl) :_implementor(impl) {}
	virtual ~abstraction() { delete _implementor; }
	virtual void operation() = 0;
};

//��������ɫ
class refinedabstraction :public abstraction
{
public:
	refinedabstraction(implementor* impl) :abstraction(impl) {}

	void operation()override
	{
		cout << "ra ���� operation" << endl;
		_implementor->operationimpl();
	}
};

//�ͻ��˵���
int main()
{
	abstraction* A = new refinedabstraction(new createimplementorA());
	A->operation();

	abstraction* B = new refinedabstraction(new createimplementorB());
	B->operation();

	delete A;
	delete B;
	return 0;
}