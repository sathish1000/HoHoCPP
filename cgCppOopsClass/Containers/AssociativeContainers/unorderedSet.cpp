#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

template <typename T>
void print(T& container)
{
   cout << "Elements in a set" << endl;
   for(auto it:container)
      cout << it << endl;
}

int main() {

unordered_set<string> myset = {"blue", "red", "green"};
myset.insert("yellow"); //O(1).

//Find a element.
unordered_set<string>::iterator itr=myset.find("yellow"); //0(1)
if (itr!=myset.end()) {
   cout << *itr << endl;
}

//Inserting a vector into a unordered set.
vector<string> color={"magenta","purple"};
myset.insert(color.begin(),color.end());
print(myset);

//Hash table specific api's.
cout << "Load factor = " << myset.load_factor() << endl;//Number of elements / Number of buckets.
string x = "red";
cout << x << " is in bucket #" << myset.bucket(x) << endl;
cout << "Total number of buckets is " << myset.bucket_count() << endl;
return 0;
}

