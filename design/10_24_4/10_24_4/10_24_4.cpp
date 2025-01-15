#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

//实现角色接口
class implementor
{
public:
	virtual ~implementor(){}
	virtual void operationimpl() = 0;
};

//具体实现角色接口A
class createimplementorA :public implementor
{
public:
	void operationimpl() override
	{
		cout << "I am A" << endl;
	}
};

//具体实现角色接口B
class createimplementorB :public implementor
{
public:
	void operationimpl() override
	{
		cout << "I am B" << endl;
	}
};

//抽象角色接口
class abstraction
{
protected:
	//维护该指针，通过该指针桥接
	implementor* _implementor;

public:
	abstraction(implementor* impl) :_implementor(impl) {}
	virtual ~abstraction() { delete _implementor; }
	virtual void operation() = 0;
};

//具体抽象角色
class refinedabstraction :public abstraction
{
public:
	refinedabstraction(implementor* impl) :abstraction(impl) {}

	void operation()override
	{
		cout << "ra 调用 operation" << endl;
		_implementor->operationimpl();
	}
};

//客户端调用
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