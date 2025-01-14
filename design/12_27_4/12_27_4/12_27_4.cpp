#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Single
{
public:
	static Single& getSingle()
	{
		static Single single;
		return single;
	}
	void print()
	{
		cout << "地址：" << this << endl;
	}
private:
	//禁止外部构造
	Single()
	{
		cout << "构造函数" << endl;
	}

	//禁止外部析构
	~Single()
	{
		cout << "析构函数" << endl;
	}

	// 禁止外部拷贝构造
	Single(const Single& single) = delete;

	// 禁止外部赋值操作
	const Single& operator=(const Single& single) = delete;
};

int main()
{
	Single& single1 = Single::getSingle();
	single1.print();
	Single& single2 = Single::getSingle();
	single2.print();

	return 0;
}