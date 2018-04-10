#include <iostream>
using namespace std;

class Base
{

  int A;

  public:
   
     Base(int X)
	{
	   A=X;	
	   cout << A << endl;   
	}

};


class Derived : public Base
{

  int B;

  public:
   
     Derived(int X) : Base(X)
	 {
            B=X;  
            cout << B << endl;   
	 }

     ~Derived() {}

};

int main()
{
    Derived d(5);
}
