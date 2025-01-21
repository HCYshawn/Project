#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<list>
using namespace std;

//组件抽象类
class Component
{
public:
	virtual ~Component() {}
	virtual void operation() = 0;
	virtual void add(Component*component){}
	virtual void remove(Component*component){}
	virtual Component* getChild(int index) { return nullptr; }
};

//叶子类
class Leaf : public Component
{
public:
	void operation()override
	{
		cout << "Leaf operation" << endl;
	}
};

//组件具体类
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

//客户端
int main()
{
	Component* root = new Composite();
	Component* leaf1 = new Leaf();
	Component* leaf2 = new Leaf();

	root->add(leaf1);
	root->add(leaf2);
	return 0;
}