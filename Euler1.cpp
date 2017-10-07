#include <iostream>
using namespace std;

const int NUM = 10;

class Euler1
{

	int array[NUM];
	int SUM;

    public:

	Euler1():array {}, SUM(0)
	{
		DividebyThree();
		DividebyFive();
		SumOfMultiples();
	}

	void DividebyThree()
	{
		for (int i=0; i<NUM; i++)
		{
			if ((i%3)==0)	{ array[i] = 1; }
		}
	}

	void DividebyFive()
	{
		for (int i=0; i<NUM; i++)
		{
			if ((i%5)==0)	{ array[i] = 1; }
		}
	}

	void SumOfMultiples()
	{
		for (int i=0; i<NUM; i++)
		{
			if (array[i] == 1)	{ SUM += i; }
		}
		cout << "The value of SUM is " << SUM << endl;
	}
};

int main()
{
	Euler1 E;
	return 0;
}


