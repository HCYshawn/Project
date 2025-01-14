#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;



class Project
{
public:
	virtual void print() = 0;
};

class Project_A : public Project
{
public:
	void print() override
	{
		cout << "I am Project_A" << endl;
	}
};

class Project_B : public Project
{
public:
	void print() override
	{
		cout << "I am Project_B" << endl;
	}
};

class createproject
{
public:
	Project* GetProject(string str)
	{
		if (str == "A")
			return new Project_A();
		else if (str == "B")
			return new Project_B();
		else
			return nullptr;
	}

};

int main()
{
	string str;
	cin >> str;
	createproject* create = new createproject;
	Project* pro = create->GetProject(str);
	pro->print();

	return 0;
}