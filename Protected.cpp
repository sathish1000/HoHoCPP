#include <iostream>
using namespace std;

class Base
{
public:		int A;
		Base():A(1),B(2),C(3) {};
protected:	int B;
private:	int C;

};

class Derived1 : public Base
{
//public.
//protected.
//Not accessed outside the Base class.
};

class Derived2 : private Base
{
//private.
//private.
//Not accessed outside the Base class.
};

class Derived3 : protected Base
{
//protected.
//protected.
//Not accessed outside the Base class.

public:

void display()
{ cout << "1" << B << endl; }

};

class Derived4 : protected Derived3
{
//protected.
//protected.
//Not accessed outside the Base class.

public:

void display()
{ cout << "2" << B << endl; }

};

int main()
{
	Derived3 A;
	Derived4 B;
	A.display();
	B.display();
	return 0;
}



