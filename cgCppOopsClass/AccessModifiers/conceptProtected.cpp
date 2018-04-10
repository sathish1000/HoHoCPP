//Protected members are available in Derived class and the class itself.
//Not available in Derived_1 because it creates a object of base class and tries to access protected members.
#include <iostream>
using namespace std;

class Base
{
    protected:
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
