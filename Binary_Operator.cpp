#include <iostream>
using namespace std;

class Distance
{
	int feet;
	int inches;

public:

	Distance():feet(0),inches(0)	{cout << "Constructor 1 called" << endl;}

	Distance(int f, int i):feet(f),inches(i)    {cout << "Constructor 2 called" << endl;}

	Distance(Distance& d)
	{
		cout << "Constructor 3 called" << endl;
		feet = d.feet;
		inches = d.inches;
	}

	~Distance()	{cout << "Destructor called" << endl;}

	Distance operator + (Distance& d) 
	{
		Distance temp;
		temp.inches = (inches + d.inches)%12;
		temp.feet = feet + d.feet + static_cast<int> ((inches + d.inches)/12);
		return temp;
	}

	void display()
	{
		cout << "The value is " << feet << " feet " << inches << " inches " << endl;
	}
	
};

int main()
{

	Distance D1(11,10);
	Distance D2(5,10);
	
	Distance D3;

        D3 = D1 + D2;
	D3.display();
	return 0;
}
