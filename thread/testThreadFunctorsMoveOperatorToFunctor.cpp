#include <iostream>
#include <thread>
#include <string>
#include <functional>
using namespace std;

//Functors.
class Fctor {
	public:
		void operator()(std::string s) {
			for (int i=0; i<100; i++) {
				cout << "From thread: i = " << i << " , msg = " << s << endl; 
			}
			s = "Vikram Sarabhai";
		};
};


void MoveWorking()
{
	//Certain objects cant be copied. It can only be moved.
	Fctor fct;
	std::string s = "Abdul Kalam";
	std::thread t(fct, std::move(s));
	

	t.join();
	cout << "From main: msg after reference updation = " << s << endl; 
	
	//std::thread t2 = t; //Error.
	std::thread t2 = std::move(t);	
}

void MoveAnotherWorking()
{
	//Certain objects cant be copied. It can only be moved.
	Fctor fct;
	std::string s = "Abdul Kalam";
	std::thread t(fct, std::move(s));
	std::thread t2 = std::move(t);

	t2.join(); //Since t is non-existent.
	cout << "From main: msg after reference updation = " << s << endl; 
	
	//std::thread t2 = t; //Error.	
}

int main() {
	MoveAnotherWorking();
	return 0;
}
