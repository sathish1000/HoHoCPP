#include <iostream>
#include <cstring>
#include <bitset>
using namespace std;
const int N = 1000;


class BigNumber
{

	std::bitset<N> Number;

	public:


	BigNumber():Number {}
	{}

	//BigNumber(long long int Num):Number(Num)
	//{}

	BigNumber(std::string Str)
	{ Number(Str); }

	friend BigNumber& operator + (BigNumber& , BigNumber& );
	
	void display()
	{ cout << std::bitset<N>(Number).to_ullong() << endl; }

};

BigNumber& operator + (BigNumber& a, BigNumber&  b)
{

	while (b.Number != 0)
	{
		bitset<N> c = a.Number ^ b.Number;
		bitset<N> d = a.Number & b.Number;
		d = d << 1;
		a.Number = c; b.Number = d;
	}

	return a;

}


int main()
{

	BigNumber Number1 = "111111111111111111111111111111111111111111111111111111111111111111111111111";
	BigNumber Number2 = "2222222222222222222222222222222222222222222";

	Number1.display();
	Number2.display();

	Number1 = Number1 + Number2;

	Number1.display();

	return 0;

}

