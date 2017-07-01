#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool descend(int i, int j){
return i>j;
}

int main(){

vector<int> vec; //vec.size()=0
vec.push_back(5);
vec.push_back(1);
vec.push_back(8);

//Size command
cout << "vector size is " << vec.size() << endl;

//Accessing using index.
cout << "Index access vec[4] = " << vec[4] << endl; //No range check.
//cout << "Index access vec.at(4) = " << vec.at(4) << endl; //Throws an exception when it accesses outside the range.

//Method 1
for (int i=0; i<vec.size(); i++)
    cout << vec[i] << endl;

//Method 2
for (vector<int>::iterator itr=vec.begin(); itr!=vec.end(); itr++)
    cout << *itr << endl;

//Method 2:-
//1) It is faster.
//2) Universal way to access a container. This method will work irrespective of the container. list, vector, 
//deque etc.

sort(vec.begin(),vec.end());
cout << "Print in ascending order" << endl;
for (vector<int>::iterator itr=vec.begin(); itr!=vec.end(); itr++)
    cout << *itr << endl;

//Using the std ::sort algorithm to print in descending order.
cout << "Print in descending order" << endl;
sort(vec.begin(),vec.end(),descend);

for (vector<int>::iterator itr=vec.begin(); itr!=vec.end(); itr++)
    cout << *itr << endl;

//C++11 way to access elements in a container.
cout << "C++11 way to access container" << endl;
for (auto itr: vec)
    cout << itr << endl;

//Common functions across containers.
//Empty
if (vec.empty()) {cout << "Vector is empty" << endl;};

//Size.
cout << "vector size is " << vec.size() << endl;
//cout << vec.size() << endl;

//Copy constructor to copy a vector.
vector<int> vec2(vec);
cout << "vector copy constructor [copy vec into vec2] is " << endl;
for (vector<int>::iterator itr=vec2.begin(); itr!=vec2.end(); itr++)
    cout << *itr << endl;

//Clear contents of a vector.
vec.clear();
cout << "Clear contents of vector VEC" << endl;
for (vector<int>::iterator itr=vec.begin(); itr!=vec.end(); itr++)
    cout << *itr << endl;

//Swap contents of a vector.
vec2.swap(vec);
cout << "Swap contents of vector " << endl;
cout << "Contents of vector VEC " << endl;
for (vector<int>::iterator itr=vec.begin(); itr!=vec.end(); itr++)
    cout << *itr << endl;

cout << "Contents of vector VEC2 " << endl;
for (vector<int>::iterator itr=vec2.begin(); itr!=vec2.end(); itr++)
    cout << *itr << endl;

return 0;
}
