#include <iostream>
#include <thread>
#include <string>
#include <functional>
using namespace std;

//Functors.
void func() {
	for (int i=0; i>-100; i--)
	{
		cout << "from thread: i = " << i << endl;
	}
}

int main() {
	
	std::thread t(func);
	for (int i=0; i<100; i++)
	{
		cout << "from main: i = " << i << endl;
	}	
	t.join();
	return 0;
}
