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
public:

	void show()
	{ cout << "Show1" << endl;}

};

class C : public B
{
public:
	void show()
	{ cout << "Show2" << endl;}
};

int main()
{
	C objC;
	objC.show();

	A* ptr = &objC;
	ptr->show();

	B objB;
	objB.show();

	ptr = &objB;
	ptr->show();

	cout << sizeof(objB) << endl;
	cout << sizeof(objC) << endl;

	return 0;
}
