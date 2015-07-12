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

		Count& operator ++ () {
			//-->& results passed as a reference. If there is no &, it would be passed as value, involving calls 
			//-->to copy constructor.

			//-->Return type of a display is mainly dependent upon what we do.
 			//-->Incase we just do "++C" in the code, return type of void would be sufficient.
 			//-->Incase we just do "D=++C" in the code, return type of void would not be sufficient.
			//-->You probably need Count as return type.

			count++;
			return *this;
		}
				 
		Count& operator ++ (int) {
			//-->& results passed as a reference. If there is no &, it would be passed as value, involving calls 
			//-->to copy constructor.

			//-->Return type of a display is mainly dependent upon what we do.
 			//-->Incase we just do "++C" in the code, return type of void would be sufficient.
 			//-->Incase we just do "D=++C" in the code, return type of void would not be sufficient.
			//-->You probably need Count as return type.

			count++;
			return *this;
		}
				 

		//Display the value.
		 Count& display() { 

			cout << "The value of count is " << ++count << endl; 
			return *this; //return the value of the this pointer.
		}

};

int main()
{
	Count C;
	C.display();
	Count D;
	D=++C;
	Count E;
	E=C++;
	cout << "The value of count" << endl;
	return 0;
}
