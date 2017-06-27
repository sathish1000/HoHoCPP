//Gives a error becoz privateInteger is private.
#include <iostream>
using namespace std;

class Base
{
    private:
        int privateInteger=5;
};

class Derived: private Base //Even though , Base is inherited private, if it is public in base class,
//Derived class can access it.
{
    public:
        int readPrivate()
        {
            return Base::privateInteger;
        }
};

int main()
{
    Derived Der;
    Der.readPrivate();
    return 0;
}
