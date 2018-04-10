#include <iostream>
#include <deque>
using namespace std;

int main(){
deque<int> deq = {10,34,25};
deq.push_back(5);
deq.push_front(2);
deq.push_front(9);

//C++11 way to access elements in a container.
cout << "C++11 way to access container" << endl;
for (auto itr: deq)
    cout << itr << endl;

//Random access.
cout << "Random access using deque" << endl;
cout << deq[1] << endl;

return 0;
}
