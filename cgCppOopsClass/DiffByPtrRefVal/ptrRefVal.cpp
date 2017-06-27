#include <iostream>
using namespace std;

class Name{
	private:
	string Fname;
	string Lname;

	public:
	Name(string A, string B):Fname(A),Lname(B){
                cout << "In constructor. The name is " << Fname << "." << Lname << endl;
	};
        ~Name(){
                cout << "In destructor. The name is " << Fname << "." << Lname << endl;
        };
	void getname(){
		cout << "In getname. The name is " << Fname << "." << Lname << endl;
	};
	void setname(string s){
		Fname=s;
	};
};

void nonConstFunction(Name a, Name* b, Name& c){

cout << "Entering non const function" << endl;
	a.setname("Bhavani");
        b->setname("Savita");
        c.setname("Renuka");

        a.getname();
        b->getname();
        c.getname();
cout << "Leaving non const function" << endl;
};

int main()
{
	Name First("Sathish","Kumar");
        Name Second("Saravana","Kumar");
        Name Third("Siva","Kumar");

        nonConstFunction(First,&Second,Third);
        cout << "Objects are destructed in the reverse order they are constructed" << endl;
}
