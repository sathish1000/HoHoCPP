#include <iostream>
using namespace std;

class Count
{
	private:

		int count;		

	public:

		//Constructor
		Count():count(0) { cout << "Constructor called" << endl; }

		//Destructor
		~Count() { cout << "Destructor called" << endl; }

		//Operator Overloading.
		void operator ++ ()  { count++; }
				 
		//Display the value.
		void display()	{ cout << "The value of count is " << count << endl; }

};

int main()
{
	Count C;
	++C;
	++C;
	++C;
	C.display();
}
