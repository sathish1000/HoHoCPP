#include <iostream>
using namespace std;

class Base2;

class Base1
{
   int A;

   public:

      Base1(int x)
	{
	   A=x;
	}

      void display()
	{
           cout << "The value of A is " << A << endl;
	}

      friend int square (Base1& a, Base2& b);
	      
};

class Base2
{
   int A;

   public:

      Base2(int x)
	{
	   A=x;
	}

      void display()
	{
           cout << "The value of A is " << A << endl;
	}

      friend int square (Base1& a, Base2& b);
	      
};


      int square (Base1& b, Base2& a)
      	{
	    return (a.A*b.A);
	}

int main()
{
	Base1 b1(5);
	Base2 b2(5);
        cout << square(b1,b2) << endl;
	return 0;
}
