#include <iostream>
#include <thread>
using namespace std;

void call_from_thread()
{
    cout << "Hello world" << endl;
}

void call_to_throw_exception() {
	throw "Exception";
}


int callThread()
{
    std::thread t;
    t = std::thread(call_from_thread);//Starts a thread t that calls the function.

	//If you call this throw exception function, your joining of thread will  not be called at all. In such a case, to join the thread, you have to use try catch or use RAII..
    try {
		call_to_throw_exception();
	} catch(...) {
		t.join();
		throw;
	}
    return 0;
}

int main()
{
	callThread();
	return 0;
}