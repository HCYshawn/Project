#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Three
{
public:
	void thp()
	{
		cout << "��������ͷ" << endl;
	}
};

class Two
{
public:
	virtual void twp() = 0;
};

class adapter : public Two
{
private:
	Three* _three;

public:
	adapter(Three* three)
	{
		_three = three;
	}

	void print()
	{
		cout << "����ͷת��Ϊ˫��ͷ" << endl;
	}

	void twp()
	{
		_three->thp();
		print();
	}
};

int main()
{
	Three* three = new Three();
	Two* two = new adapter(three);

	two->twp();
	delete three;
	delete two;
	return 0;
}