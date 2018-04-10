 #include <iostream>
using namespace std;

class Counter
{

protected:

	int count;


public:

	//Counter():count(0) { cout << "Constructor called" << endl; };
	//Counter(int c):count(c) {};

	void operator ++ ()
	{
		count++;
	}	

	void display() const
	{
		cout << "The value of count is " << count << endl;
	}
	
};

class CountDn : public Counter
{

	int Dn;

public:

	//CountDn():Dn(0) { cout << "Constructor Derived called" << count << endl; };

	void operator -- ()
	{
		count--;
	}

	void display() const
	{
		cout << "The value of Dn is " << Dn << endl;
	}


};

int main()
{
	Counter C;
	++C;
	C.display();

	//CountDn D;
	//++D;
	//--D;
	//D.display();

	return 0;
}
