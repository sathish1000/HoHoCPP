#include <iostream>
#include <set>
using namespace std;

template <typename T>
void print(T& container)
{
   cout << "Elements in a set" << endl;
   for(auto it:container)
      cout << it << endl;
}

int main() {

//Declare a set.
set<int> myset;

//Insert into a set. Always sorted.
myset.insert(5); //myset = {5}
myset.insert(1); //myset = {1,5}
myset.insert(9); //myset = {1,5,9}. O(log(n)).

set<int>::iterator it = myset.find(5);//O(log(n)). Sequence containers dont have even a find method.

//signature of ret is pair<set<int>::iterator,bool>.
pair<set<int>::iterator,bool> ret;
ret = myset.insert(3);

if (ret.second==false)
   it=ret.first;

myset.insert(it,11);//Why does insert have iterator pointing to 5. 11 is not going to inserted after 5. Iterator acts as a hint to reduce O(log(n)) to 0(1).

cout << "Elements in the set before it is erased" << endl;
print(myset);
myset.erase(1);
myset.erase(it); //Should delete 5.
cout << "Elements in the set after it is erased" << endl;
print(myset);

return 0;
}
