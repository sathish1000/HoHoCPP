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

		Count  operator ++ () {
			count++;
			Count temp;
			temp.count = count;
			return temp;
			//return *this;

		}
				 
		//Display the value.
		 void display() { 
			cout << "The value of count is " << count << endl; 
			//return *this; //return the value of the this pointer.
		}

};

int main()
{
			Count C;
		Count D;
		C.display();
		D.display();
		D=++C;
		C.display();
		D.display();
		return 0;
}
