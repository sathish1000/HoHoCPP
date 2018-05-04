#include <iostream>
#include <array>
using namespace std;

template <typename T>
void print(T& container)
{
   cout << "Elements in a list" << endl;
   for(auto it:container)
      cout << it << endl;
}

int main(){
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
