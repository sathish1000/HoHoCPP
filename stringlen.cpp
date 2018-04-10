#include <iostream>
using namespace std;

int arrlength( const char* j)
{
    int a;
    for (a=0; j[a]!=0; a++);
    return a;
}

int ptrlength( const char* j)
{
    const char* b;
    b=j;
    while(*b++);
    return b-j-1;
}

void ptrcopy( char* x,  const char* y)
{
    while(*x++ = *y++);
}

int main()
{
	const char* i = "H";
        cout << ptrlength(i) << endl;

        char* d;
        ptrcopy (d,i);

        cout << d << endl;

        return 0;
}
