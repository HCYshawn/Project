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

	void add(Component* component)
	{
		children.push_back(component);
	}

	void remove(Component* component)
	{
		children.remove(component);
	}

	Component* getChild(int index)
	{
		return NULL;
	}
};

//�ͻ���
int main()
{
	Composite* root = new Composite();
	Component* leaf1 = new Leaf();
	Component* leaf2 = new Leaf();

	root->add(leaf1);
	root->add(leaf2);
	root->operation();
	
	delete root;
	delete leaf1;
	delete leaf2;
	return 0;
}