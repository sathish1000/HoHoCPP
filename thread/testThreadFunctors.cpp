#include <iostream>
#include <thread>
using namespace std;

//Functors.
class Fctor {
	public:
		void operator()() {
			for (int i=0; i<100; i++) {
				cout << "From thread: i = " << i << endl; 
			}
		}
};

int main()
{
	Fctor fct;
    std::thread t;
    t = std::thread(fct);//Starts a thread t that calls the functor. [Threads can call any callable object (functions, functors etc)]

	for (int i=0; i<100; i++) {
		cout << "From main: i = " << i << endl; 
	}
	
	t.join();
    return 0;
}
