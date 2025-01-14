#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

class Project
{
public:
	virtual void print() = 0;
};

class Project_A :public Project
{
	void print() override
	{
		cout << "I am A" << endl;
	}
};

class Project_B :public Project
{
	void print() override
	{
		cout << "I am B" << endl;
	}
};

class Create
{
public:
	virtual Project* Getpro() = 0;
};

class Create_A :public Create
{
	Project* Getpro() override
	{
		cout << "工厂A..." << endl;
		return new Project_A();
	}
};

class Create_B :public Create
{
	Project* Getpro() override
	{
		cout << "工厂B..." << endl;
		return new Project_B();
	}
};

int main()
{
	Create* A = new Create_A();
	Project* a = A->Getpro();
	a->print();
	Create* B = new Create_B();
	Project* b = B->Getpro();
	b->print();
	delete A;
	delete a;
	delete B;
	delete b;
	return 0;
}