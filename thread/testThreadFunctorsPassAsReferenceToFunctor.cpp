#include <iostream>
#include <thread>
#include <string>
#include <functional>
using namespace std;

//Functors.
class Fctor {
	public:
		void operator()(std::string &s) {
			for (int i=0; i<100; i++) {
				cout << "From thread: i = " << i << " , msg = " << s << endl; 
			}
			s = "Vikram Sarabhai";
		};
};

/* This will not work with &s. So commenting.
void PassByReferenceNotWorking()
{
	Fctor fct;
	std::string s = "Abdul Kalam";
	std::thread t(fct, s);

	t.join();
	cout << "From main: msg after reference updation = " << s << endl; 
}
*/

void PassByReferenceWorking()
{
	Fctor fct;
	std::string s = "Abdul Kalam";
	std::thread t(fct, std::ref(s));
	
	t.join();
	cout << "From main: msg after reference updation = " << s << endl; 	
}

int main() {
	PassByReferenceWorking();
	return 0;
}
