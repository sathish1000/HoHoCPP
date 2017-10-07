#include <iostream>
using namespace std;

void display(char *ptr){
	while (*ptr)
	cout << *ptr++ << endl;
}


int main()
{

//proof to prove the difference between array vs pointer.
	char array[] = "My name is Sathish";
	display(array);
	return 0;
}
