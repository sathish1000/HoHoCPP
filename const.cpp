#include <iostream>
using namespace std;

int main()
{
    const char* str = "I am an Indian";
    int count = 0;

    while ((*str)!='\0')
	{
		cout << *str << endl;
		count++;
		str++;
	}
    cout << "The length of the string is " << count << endl;    
    return 0;
}
