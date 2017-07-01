#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

template <typename T>
void print(T& container)
{
   cout << "Elements in a set" << endl;
   for(auto it:container)
      cout << it.first << " " << it.second << endl;
}

void foo(const unordered_map<char,string> &m){
//  m['S'] = "Sunday"; //Will not work because m is a const.
//  cout << m['S'] << endl; //This will also not work. Becoz the compiler thinks m['S'] is 
//going to change the value. 

//Correct way to do it.
  auto it = m.find('W');
  if (it != m.end())
     cout << *it << endl;

};

int main() {

//Associative array.
unordered_map<char,string> week = {{'M',"Monday"},{'F',"Friday"}};

//Access.
cout << week['M'] << endl; //No Range check.
cout << week.at('M') << endl; //Range check involved. Otherwise throws a exception.

//Comparison with vector.
vector<int> v = {1,2,3};
cout << v[5] << endl; //Invalid access.

//But in associative array.
week['T'] = "Tuesday"; //Creates a new element in the array.
week.insert(make_pair<char,string>('W',"Wednesday")); //Creates a new element in the array.

week.insert(make_pair<char,string>('W',"wednesday")); //Causes a error.It assumes it 
//changes the key.

week['W'] = "wednesday"; //This works..We are just changing the value.
print(week);
return 0;
}
