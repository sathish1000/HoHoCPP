#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
const int N = 1000;


class BigNumber
{

	std::string Number;

	public:

	~BigNumber()
	{ cout << "Destructor called" << endl;}

	BigNumber():Number {}
	{}

	BigNumber(const char* Num)
	{
		Number = Num;
                cout << Number << endl;
	}

	friend BigNumber& operator >> (BigNumber& B,int val);

	friend BigNumber operator + (BigNumber& , BigNumber& );

	friend ostream& operator << (ostream& s, BigNumber& Big);

	friend istream& operator >> (istream& s, BigNumber& Big);
	
	void display() const
	{ cout << Number << endl; }
};

istream& operator >> (istream& s, BigNumber& Big)
{
    s >> Big.Number;
    return s;
}

ostream& operator << (ostream& s, BigNumber& Big)
{
    s << Big.Number;
    return s;
}

BigNumber& operator >> (BigNumber& Big,int val)
{
    cout << "List 1 " << Big.Number << "val" << val << endl;
    int Num = Big.Number.size();
    for (int i=Num; i>=0; i--)
	{
                if ((i-val-1)>=0)
		{
		Big.Number[i-1]=Big.Number[i-val-1];
		Big.Number[i-val-1]='0';
                cout << "Exchange = " << Big.Number[i-val-1] << " " << Big.Number[i-1] << " value of i = " << i << endl; 
		}
		else
		{
		Big.Number[i-1]='0';
		}	
	
	}
   	 cout << "List 1"  << endl;
   	 cout << "List 1 - return" << Big.Number << endl;

        return Big;
}

BigNumber operator + (BigNumber& Str1, BigNumber& Str2)
{

	BigNumber Temp;

	int sum = 0, carry = 0;
	int val1 = 0, val2 = 0;
	int Num;

	Num = ((Str1.Number.size()) < (Str2.Number.size()))?(Str2.Number.size()):(Str1.Number.size());
	cout << "Value of Num is =" << Num << endl; 

        if (Str1.Number.size() < Num) { int val=Num-Str1.Number.size(); Str1.Number.resize(Num); Str1>>val;}
        if (Str2.Number.size() < Num) { int val=Num-Str2.Number.size(); Str2.Number.resize(Num); Str2>>val;}

        cout << "List 2 " << Str1.Number << endl;
        cout << "List 3 " << Str2.Number << endl;

	Temp.Number.resize(Num+1);
	
	for (int i=Num; i>=0; i--)
	{	

		val1 = (i < (Str1.Number.size()))?static_cast<int>(Str1.Number[i] - '0'):0;
		val2 = (i < (Str2.Number.size()))?static_cast<int>(Str2.Number[i] - '0'):0;

		sum = (val1 + val2 + carry)%10;
		carry = (val1 + val2 + carry)/10;
	
		Temp.Number[i+1] = '0' + sum;	
		cout << Temp.Number[i] << endl;	
	}

        if (carry>0)
	{
		Temp.Number[0]=carry + '0';
	}
	return BigNumber(Temp);

}

int main()
{

	//BigNumber Number1 = "5989";
	//BigNumber Number2 = "2222";
	BigNumber Number1,Number2;
	cin >> Number1;
	cin >> Number2;
	BigNumber Number3 = Number1 + Number2;	
	Number3.display();
	return 0;

}

