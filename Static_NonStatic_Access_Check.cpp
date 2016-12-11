//This is a program to check whether
//1) Static functio has access a) Static variable b) Non static variable.
//2) Non static function has access to a) Static variable b) Non static variable.
#include <iostream>
using namespace std;

class Static_NonStatic
{
    private:
    static int i;
    int j;

    public:

    Static_NonStatic():j(10)
    {}

    static void StaticFunc()
    {
       cout << i << endl;
//       cout << j << endl; 
    }

    void NonStaticFunc()
    {
       cout << i << endl;
       cout << j << endl;
    }

};

int Static_NonStatic::i=0;

int main()
{
    Static_NonStatic Test;
    Test.StaticFunc();
    Test.NonStaticFunc();
    return 0;
}
