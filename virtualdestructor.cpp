#include <iostream>
using namespace std;

class Base
{

		char c;

	public:

		virtual ~Base()
		//~Base()
		{
		}
};


int main()
{
	
  cout << sizeof(Base) << endl;
  return 0;

}
