#include <iostream>
using namespace std;

enum POSNEG {POS,NEG};

class Distance 
{

protected:

	int feet;
	int inches;

public:

	//Distance():feet(0),inches(0) {};
	Distance(int f, int i):feet(f),inches(i) {};

	void display() const
	{
		cout << "Distance in feet = " << feet << " inches = " << inches << endl; 
	}

};

class Distance_POSNEG : public Distance
{
	
	POSNEG sign;

public:

	//Distance_POSNEG():Distance(),sign(POS) {};
	Distance_POSNEG(int f, int i, POSNEG p=POS): sign(p), Distance(f,i) {};

	void display() const
	{
		cout << "Distance in " << ((sign==POS) ? '+' : '-') << " feet = " << feet << " inches = " << inches << endl; 
	}
}; 

int main()
{

	Distance_POSNEG D(5,10);
	D.display();

	Distance_POSNEG C(5,10);
	C.display();

	return 0;

}
