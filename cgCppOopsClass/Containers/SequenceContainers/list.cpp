#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

template <typename T>
void print(T& container)
{
   cout << "Elements in a list" << endl;
   for(auto it:container)
      cout << it << endl;
}

int main(){
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
