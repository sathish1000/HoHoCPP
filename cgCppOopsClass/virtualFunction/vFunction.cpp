#include <iostream>
using namespace std;

class Employee
{
string Name;
string Department;

public:
Employee(string N, string Dprt):Name(N),Department(Dprt){};
virtual int salary() {return 0;};
};

class Hourly: public Employee
{
int hoursworked;

public:
Hourly(string N, string Dprt, int hours):Employee(N, Dprt),hoursworked(hours) {};
int salary() {return 15*hoursworked;};
};

class Monthly: public Employee
{

public:
Monthly(string N, string Dprt):Employee(N, Dprt){};
int salary() {return 1500;};
};

int main()
{

Employee* E1 = new Employee("Sathish","Goods");
Employee* E2 = new Hourly("Saravana","Auto",15);
Employee* E3 = new Monthly("Siva","Electric");

cout << E1->salary() << endl;
cout << E2->salary() << endl;
cout << E3->salary() << endl;
return 0;
}
