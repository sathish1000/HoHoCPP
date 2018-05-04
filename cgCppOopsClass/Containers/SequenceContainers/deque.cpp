#include <iostream>
#include <deque>
using namespace std;

int main(){
deque<int> deq = {10,34,25};
deq.push_back(5); {10,34,25,5}
deq.push_front(2); {2,10,34,25,5}
deq.push_front(9); {9,2,10,34,25,5}

//C++11 way to access elements in a container.
cout << "C++11 way to access container" << endl;
for (auto itr: deq)
    cout << itr << endl;

//Random access.
//No contiguous storage like vector.
cout << "Random access using deque" << endl;
cout << deq[1] << endl;

return 0;
}
