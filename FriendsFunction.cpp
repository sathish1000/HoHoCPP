#include <iostream>
using namespace std;

class Base
{
   int A;

   public:

      Base(int x)
	{
	   A=x;
	}

      void display()
	{
           cout << "The value of A is " << A << endl;
	}

      friend int square (Base& b);
	      
};

      int square (Base& b)
      	{
	    return (b.A*b.A);
	}

int main()
{
	Base b(5);
        cout << square(b) << endl;
	return 0;
}
