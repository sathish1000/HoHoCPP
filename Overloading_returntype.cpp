#include <iostream>
using namespace std;

class Count
{
	private:

		int count;		

	public:

		//Constructor
		Count():count(0) { cout << "Constructor called" << endl; }

		Count(Count& C):count(C.count)
		{  
			cout << "Copy constructor called" << endl; 
		}

		//Destructor
		~Count() { cout << "Destructor called" << endl; }
				 
		//Display the value.
		 Count& display() { 
			//-->& results passed as a reference. If there is no &, it would be passed as value, involving calls 
			//-->to copy constructor.
			cout << "The value of count is " << ++count << endl; 
			return *this; //return the value of the this pointer.
		}

};

int main()
{
	Count C;
	C.display();
	cout << "The value of count" << endl;
	return 0;
}
