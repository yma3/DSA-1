#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <class T>
class SimpleList
{
protected:
	static vector<string> UsedNames;
	int nameIndex;
	int size;	

	class Node 
	{
	public:
		T info;
		Node* pNext;
		Node(T input);
	};

	Node* pRoot;
	Node* pEnd;
	
public:
	virtual T pop() = 0;
	virtual void push(T input) = 0;
	string getname()
	{
		return UsedNames[nameIndex];;
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
	for(int i = 0; i < UsedNames.size(); i++)
	{
		if(inputname == UsedNames[i])
		{
			throw exception();
		}
	}

	nameIndex = UsedNames.size();
	UsedNames.push_back(inputname);
	size = 0;
	pRoot = pEnd = 0;
}

template <class T>
SimpleList<T>::Node::Node(T input)
{
	info = input;
	pNext = 0;
}

template <class T>
class Stack: public SimpleList<T>
{
	public:
	T pop()
	{
		if(this->size == 0)
		{
			throw exception();
		} 
		T popdata = this->pRoot->info;
		class SimpleList<T>::Node* hold = this->pRoot;
		this->pRoot = hold->pNext;
		delete(hold);
		this->size--;
		return popdata;
	};
	void push(T input)
	{
		class SimpleList<T>::Node* hold = new class SimpleList<T>::Node(input);
		if(this->size == 0)
		{
			this->pRoot = this->pEnd = hold;
			hold->pNext = 0;
			this->size++;
			return;
		}
		hold->pNext = this->pRoot;
		this->pRoot = hold;
		this->size++;	
	};
	Stack(string inputname):SimpleList<T>(inputname){};
};

template <class T>
class Queue: public SimpleList<T>
{
	public:
	T pop()
	{
		if(this->size == 0)
		{
			throw exception();
		}
		T popdata = this->pRoot->info;
		class SimpleList<T>::Node* hold = this->pRoot;
		this->pRoot = hold->pNext;
		delete(hold);
		this->size--;
		return popdata;
	};
	void push(T input)
	{
		class SimpleList<T>::Node* hold = new class SimpleList<T>::Node(input);
		if(this->size == 0)
		{
			this->pRoot = this->pEnd = hold;
			hold->pNext = 0;
			this->size++;
			return;
		}
		this->pEnd->pNext = hold;
		this->pEnd = hold;
		this->size++;
	};
	Queue(string inputname):SimpleList<T>(inputname){};
};

int main()
{
	
	return 0;
}
