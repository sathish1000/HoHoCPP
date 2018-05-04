#include <iostream>
#include <map>
#include <utility>
using namespace std;

template <typename T>
void print(T& container)
{
   cout << "Elements in a set" << endl;
   for(auto it:container)
      cout << (it).first << " " << (it).second << endl;
}

int main() {

map<char,int> mymap;
mymap.insert(make_pair('a',5)); // make_pair is function template. So it can infer types.
mymap.insert(pair<char,int>('z',10)); //pair is class template. So it doesn't infer types.

//Insert with a hint.
map<char,int>::iterator it = mymap.begin();
mymap.insert(it,pair<char,int>('g',50));

//Find. O(log(n))
it = mymap.find('g');

//Print elements in the container.
print(mymap);

for(it=mymap.begin(); it!=mymap.end(); it++) {
   cout << (*it).first << " " << (*it).second << endl;
}

//multi map is a map that allows duplicated keys.
multipmap<char,int> mymultimap;

//map/multimap 
//	- keys cannot be modified.
//		type of *it: pair<const char,int>
(*it).first = 'd'; //Error.


return 0;
}

