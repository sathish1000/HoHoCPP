#include <iostream>
using namespace std;

class Euler2
{

	int NUM1;
	int NUM2;

    public:

	Euler2():NUM1(1),NUM2(2)
	{
		Fibonacci();	
	}

	void Fibonacci()
	{
		int sum=0;
		while (NUM1 < 4000000)
		{
			if ((NUM1%2)==0) {sum += NUM1;}
			NUM1 += NUM2;
			int temp = NUM2;
			NUM2 = NUM1;
			NUM1 = temp;
		}
		cout << "SUM is " << sum << endl;
	}
};

int main()
{
	Euler2 E;
	return 0;
}


