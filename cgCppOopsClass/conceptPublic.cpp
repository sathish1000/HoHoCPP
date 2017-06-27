#include <iostream>
using namespace std;

class Base
{
    public:
        int protectedInteger=5;
};

class Derived: private Base
{
    public:
        int readProtected()
        {
            return Base::protectedInteger;
        }
};

class Derived_1
{
    private:
        Base protectedBase;
    public:
        int readProtected()
        {
            return protectedBase.protectedInteger;
        }
};

int main()
{
    Derived Der;
    Der.readProtected();
    return 0;
}
