#include <iostream>
using namespace std;

class Base
{
  int i;
  const int j; //const should be initialized..
  mutable int k;
  public:

	Base(int a,int b, int c):i(a),j(b),k(c)
	{		
	}


/* If the default constructor is used, it will request us to initialize teh const variable.
        Base()
	{		
	}
*/

/* A const member variable can be assigned values only in the initializer list.
	Base(int a,int b, int c)
	{		
		i=a;j=b;k=c;
	}
*/

	~Base()
	{
	}

        void show1()
	{
	     cout << "A Non const function" << endl;
	}

	void show2() const
	{
	     cout << "A Const function" << endl;
	}

        void square() 
	{
	     //j=j*j;  //Error. Cant modify a const variable.
	     cout << "The square of the j is " << j*j << endl; 
	}        

        void mute_access() const
	{
	     //j=j*j;  //Error. Cant modify a const variable.
             k=k*k;  //Can modify a mutable variable.
	     cout << "The square of the j is " << j << endl; 
	     cout << "The square of the k is " << k << endl; 
	}    

	//Const function can access a non-const variable and nonconst variables..
	void display_1() const { 
                //i = i*i; //Const function doesnt allow to change a non const variable.
                //j = j*j; //Const function doesnt allow to change a const variable.
                k = k*k; //Const function allow to change mutable variable.
		cout << "The value of i is " << i << endl;
		cout << "The value of j is " << j << endl;
		cout << "The value of k is " << k << endl;
                //show1(); //Const function cant call a non const function.
                show2();
	} 

	//Const function can access a non-const variable..
	void display_3() { 
                i = i*i; 
                //j = j*j;  //Non Const function doesnt allow to change a const variable.
                k = k*k;  //Const function doesnt allow to change a const variable.
		cout << "The value of i is " << i << endl;
		cout << "The value of j is " << j << endl;
		cout << "The value of k is " << k << endl;
                show1();
                show2(); //Non const function cant call a const function.
	} 
};

int main()
{
  Base a(5,4,3);
  a.display_1();
  a.display_3();

  const Base b(10,8,6);
  b.display_1();
  //b.display_3(); // Not a const function.
  b.mute_access();
}
