#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<list>
using namespace std;

//���������
class Component
{
public:
	virtual ~Component() {}
	virtual void operation() = 0;
	virtual void add(Component*component){}
	virtual void remove(Component*component){}
	virtual Component* getChild(int index) { return nullptr; }
};

//Ҷ����
class Leaf : public Component
{
public:
	void operation()override
	{
		cout << "Leaf operation" << endl;
	}
};

//���������
class Composite :public Component
{
private:
	list<Component*> children;

public:
	void operation()override
	{
		for (auto child : children)
		{
			child->operation();
		}
	}

	void add(Component* component)override
	{
		children.push_back(component);
	}

	void remove(Component* component)override
	{
		children.remove(component);
	}

	Component* getChild(int index)override
	{
		return ;
	}
};

//�ͻ���
int main()
{
	Component* root = new Composite();
	Component* leaf1 = new Leaf();
	Component* leaf2 = new Leaf();

	root->add(leaf1);
	root->add(leaf2);
	return 0;
}