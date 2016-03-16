#include <iostream>
#include <vector>

using namespace std;

template <class T>
class SimpleList
{
	protected:
	string name;
	int size;
	class Node 
	{
		public:
		T value;
		Node* next;
		Node(T input);
	};
	Node* root;
	
	public:
	virtual T pop() = 0;
	virtual void push(T input) = 0;
	string getname()
	{
		return name;
	};
	int getsize()
	{
		return size;
	};
	SimpleList(string inputname);
};

template <class T>
SimpleList<T>::SimpleList(string inputname)
{
	name = inputname;
	size = 0;
	root = 0;
}

template <class T>
SimpleList<T>::Node::Node(T input)
{
	value = input;
	next = 0;
}
