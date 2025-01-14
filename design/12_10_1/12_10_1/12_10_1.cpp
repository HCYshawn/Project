#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//�����ƷA
class AbstactProductA
{
public:
	virtual void print() = 0;
};

class AbstactProductA1 :public AbstactProductA
{
public:
	void print() override
	{
		cout << "I am A1" << endl;
	}
};

class AbstactProductA2 :public AbstactProductA
{
public:
	void print() override
	{
		cout << "I am A2" << endl;
	}
};

//�����ƷB
class AbstactProductB
{
public:
	virtual void print() = 0;
};

class AbstactProductB1 : public AbstactProductB
{
public:
	void print() override
	{
		cout << "I am B1" << endl;
	}
};

class AbstactProductB2 : public AbstactProductB
{
public:
	void print() override
	{
		cout << "I am B2" << endl;
	}
};

//���󹤳�
class Factory
{
public:
	virtual AbstactProductA* createA() = 0;
	virtual AbstactProductB* createB() = 0;
};

//���幤��F1������1���Ʒ
class ConcreateFactory1 :public Factory
{
	AbstactProductA* createA() override
	{
		return new AbstactProductA1();
	}

	AbstactProductB* createB() override
	{
		return new AbstactProductB1();
	}
};

//�����ƷF2������2���Ʒ
class ConcreateFactory2 :public Factory
{
	AbstactProductA* createA() override
	{
		return new AbstactProductA2();
	}

	AbstactProductB* createB() override
	{
		return new AbstactProductB2();
	}
};

int main()
{
	Factory* f1 = new ConcreateFactory1();
	Factory* f2 = new ConcreateFactory2();
	AbstactProductA* a1 = f1->createA();
	AbstactProductB* b1 = f1->createB();
	a1->print();
	b1->print();
	AbstactProductA* a2 = f2->createA();
	AbstactProductB* b2 = f2->createB();
	a2->print();
	b2->print();
	delete a1;
	delete b1;
	delete f1;
	delete a2;
	delete b2;
	delete f2;
	return 0;
}