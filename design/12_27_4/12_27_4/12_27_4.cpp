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
		cout << "��ַ��" << this << endl;
	}
private:
	//��ֹ�ⲿ����
	Single()
	{
		cout << "���캯��" << endl;
	}

	//��ֹ�ⲿ����
	~Single()
	{
		cout << "��������" << endl;
	}

	// ��ֹ�ⲿ��������
	Single(const Single& single) = delete;

	// ��ֹ�ⲿ��ֵ����
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