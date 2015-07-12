#include <iostream>
#include <string>
using namespace std;

class A
{
public:

	void show()
	{ cout << "Show0" << endl;}

};

class B : public A
{
};

class C : public A
{
};

class D : public B, public C
{
};

int main()
{
	D objD;
	objD.show();

//	A* ptr = &objC;
//	ptr->show();

	return 0;
}
