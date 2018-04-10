#include <iostream>
using namespace std;

int main()
{

//proof to prove the difference between array vs pointer.
	char array[] = "My name is Sathish";
	char* ptr = "My name is Sathish";

	//array++;
	ptr++;

	cout << array << endl;
	cout << ptr << endl;

	return 0;
}
