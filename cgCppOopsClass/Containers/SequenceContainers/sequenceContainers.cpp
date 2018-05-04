#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <array>
#include <algorithm>
using namespace std;

template <typename T>
void print(T& container)
{
   cout << "Elements in a list" << endl;
   for(auto it:container)
      cout << it << endl;
}

bool descend(int i, int j){
return i>j;
}

int arrayTest(){
	//A thin layer over the native array.
	array<int,3> a = {4,5,6};
	print(a);
	array<int,4> b = {1,2};
	print(b);
	array<int,4> c;
	c = {1,5};
	print(c);
	array<int,4> d;
	//d = {1,5,6,7,8};//Assign 5 elements to a array of size 4.
	print(d);
	return 0;
}

int dequeTest(){
	deque<int> deq = {10,34,25};
	deq.push_back(5); //{10,34,25,5}
	deq.push_front(2); //{2,10,34,25,5}
	deq.push_front(9); //{9,2,10,34,25,5}

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

int listTest(){
	list<int> lst = {5,7,8};
	lst.push_back(1); // {5,7,8,1}
	lst.push_front(9);//{9,5,7,8,1}
	cout << "Elements in a original list" << endl;
	print(lst);
	list<int>::iterator itr = find(lst.begin(), lst.end(), 7); //itr = 7
	lst.insert(itr,55); // insert 55 in front of 7. {9,5,55,7,8,1}
	cout << "Elements with 55 inserted into a list" << endl;
	print(lst);

	itr++;
	lst.erase(itr);
	cout << "Erase elements in a list" << endl;
	print(lst);

	list<int> mylist = {0,1,2};
	itr = find(mylist.begin(), mylist.end(), 1);
	list<int>::iterator itr1 = find(lst.begin(), lst.end(), 5);
	list<int>::iterator itr2 = find(lst.begin(), lst.end(), 8);

	cout << "Elements in a list before splice" << endl;
	cout << "Elements in a lst" << endl;
	print(lst);
	cout << "Elements in a mylist" << endl;
	print(mylist);
	mylist.splice(itr,lst,itr1,itr2);
	cout << "Elements in a list after splice" << endl;
	cout << "Elements in a lst" << endl;
	print(lst);
	cout << "Elements in a mylist" << endl;
	print(mylist);
	return 0;
}

int vectorTest(){
	//Dynamic array that grows in size. Allocated on the heap.
	vector<int> vec; //vec.size()=0. //Default constructor called.
	vec.push_back(5);
	vec.push_back(1);
	vec.push_back(8); //vec = {5, 1, 8} vec.size()=3

	//Begin points to the first element in the vector, end points to one past the last element in the vector.
	vector<int>::iterator itr1 = vec.begin(); //half-open [begin, end)
	vector<int>::iterator itr2 = vec.end();

	cout << *vec.end() << endl; //Undefined behaviour. Dangerous situation to get into.

	sort(itr1, itr2); //vec = {1, 5, 8}

	//Iterator is like a pointer. Iterator is a class
	//1)Assign them, Add them, compare them, dereference them
	for (vector<int>::iterator itr=itr1; itr!=itr2; itr++)
            cout << *itr << endl;

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
		
	//Vector is a dynamically allocated contiguous array in memory [heap]
	int* p = &vec[0]; //p[2] is valid	

	//////////////////////////////////////
	//Common functions across containers.
	//////////////////////////////////////
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
	vec.clear(); //vec.size() is zero.
	cout << "Clear contents of vector VEC" << endl;
	for (vector<int>::iterator itr=vec.begin(); itr!=vec.end(); itr++)
            cout << *itr << endl;

	//Swap contents of a vector.
	vec2.swap(vec); //vec.size() = 0 & vec2.size() = 3
	cout << "Swap contents of vector " << endl;
	cout << "Contents of vector VEC " << endl;
	for (vector<int>::iterator itr=vec.begin(); itr!=vec.end(); itr++)
            cout << *itr << endl;

	cout << "Contents of vector VEC2 " << endl;
	for (vector<int>::iterator itr=vec2.begin(); itr!=vec2.end(); itr++)
            cout << *itr << endl;

	return 0;
}

int main() {
	int value_1 = vectorTest();
	int value_2 = listTest();
	int value_3 = dequeTest();
	int value_4 = arrayTest();
        return 0;
}