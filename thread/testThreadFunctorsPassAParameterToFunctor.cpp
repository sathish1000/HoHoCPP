#include <iostream>
#include <thread>
using namespace std;

//Functors.
class Fctor {
	public:
		void operator()(string s) {
			for (int i=0; i<100; i++) {
				cout << "From thread: i = " << i << " , msg = " << s << endl; 
			}
		};
};

int main()
{
	std::thread t((Fctor()),"Fin"); //This creates a thread.
	
	for (int i=0; i<100; i++) {
		cout << "From main: i = " << i << endl; 
	}
	
	t.join();
    return 0;
}
