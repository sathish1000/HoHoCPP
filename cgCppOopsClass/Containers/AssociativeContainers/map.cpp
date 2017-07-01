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
mymap.insert(make_pair('a',5));
mymap.insert(pair<char,int>('z',10));

//Insert with a hint.
map<char,int>::iterator it = mymap.begin();
mymap.insert(it,pair<char,int>('g',50));

//Find.
it = mymap.find('g');

//Print elements in the container.
print(mymap);

for(it=mymap.begin(); it!=mymap.end(); it++) {
   cout << (*it).first << " " << (*it).second << endl;
}
return 0;
}

