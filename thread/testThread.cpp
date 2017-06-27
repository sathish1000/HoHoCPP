#include <iostream>
#include <thread>
using namespace std;

void call_from_thread()
{
    cout << "Hello world" << endl;
}

int main()
{
    std::thread t;
    t = std::thread(call_from_thread);//Starts a thread t that calls the function.
    t.join();//The main program waits for the thread to finish its execution.
    return 0;
}

