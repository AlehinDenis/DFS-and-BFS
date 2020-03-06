#include <iostream>
#include <stack>
template<class T>
class MyQueue
{
protected:
	std::stack<T> First;
	std::stack<T> Second;
public:
	void Push(T Element)
	{
		First.push(Element);
	}
	T Pop()
	{
		if (Second.empty())
		{
			if (!First.empty())
			{

				while (!First.empty())
				{
					Second.push(First.top());
					First.pop();
				}
				T tmp = Second.top();
				Second.pop();
				return tmp;
			}
			else throw("Queue is empty!");
		}
		else
		{
			T tmp = Second.top();
			Second.pop();
			return tmp;
		}
	}
	T Top()
	{
		if (!Second.empty())
			return Second.top();
		if (First.empty())
			throw("Queue is empty!");
		while (!First.empty())
		{
			Second.push(First.top());
			First.pop();
		}
		return Second.top();

	}
};

template<class T>
class MyCycleQueue
{
protected:
	T* top;
	T* tail;
	T* queue;
public:
	MyCycleQueue(int N = 0)
	{
		queue = new T[N];
		top = tail = queue[0];
	}
	void Push(T Element)
	{
		queue[tail] = Element;
		tail++;
	}
};

int main()
{
	
}
