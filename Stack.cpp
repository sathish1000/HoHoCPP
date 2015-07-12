#include <iostream>
using namespace std;

class Stack
{

protected:

	static const int SZ = 81;
	int size;
	int Stack_array[SZ];


public:

	Stack():size(0)
	{
		for (auto &i : Stack_array)
		{
			i=0;
		}
	}


	void push(int val)
	{
		size++;
		Stack_array[size] = val;
		display();	
	}

	void pop()	
	{
		Stack_array[size] = 0;
		size--;
		display();
	}

	void display()
	{
		for (int i=1; i<=size;i++)
		{
			//cout << "The value at position " << i << " is " << Stack_array[i] << endl;
		}
	}
};


class Stack_Overflow : public Stack
{

public:

	void push(int val)
	{
		if (size < SZ)
		{
			Stack::push(val);
		}
		else
		{
			cout << "Stack Overflow size = " << size << endl;
		}				
	}

	void pop()
	{
		if (size != 0)
		{
			Stack::pop();
		}
		else
		{
			cout << "Stack Underflow" << endl;			
		}
	}
	
};

int main()
{
	Stack_Overflow S;

	for (int i=0; i<=81; i++)
		S.push(i);
	S.pop();
	S.pop();
	S.pop();
	S.pop();
	return 0;
}
