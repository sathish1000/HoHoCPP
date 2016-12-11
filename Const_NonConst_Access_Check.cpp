//This is a program to check whether
//1) Const functio has access a) CONST variable b) Non CONST variable.
//2) Non Const function has access to a) CONST variable b) Non CONST variable.
#include <iostream>
using namespace std;

class Const_NonConst
{
    private:
    const int i=0;
    int j;

    public:

    Const_NonConst():j(10)
    {}


    void ConstFunc() const
    {
       cout << i << endl;
       cout << j << endl; 
    }

    void NonConstFunc()
    {
       cout << i << endl;
       cout << j << endl;
    }

    void ConstFuncMod() const
    {
//       cout << i++ << endl;
//       cout << j++ << endl; 
    }

    void NonConstFuncMod()
    {
//       cout << i++ << endl;
       cout << j++ << endl;
    }

};

int main()
{
    Const_NonConst Test;
    Test.ConstFunc();
    Test.NonConstFunc();
    Test.ConstFuncMod();
    Test.NonConstFuncMod();
    const Const_NonConst conTest;
    conTest.ConstFunc();
//    conTest.NonConstFunc();
    return 0;
}
