/*
Majority rule is a decision rule that selects the alternative which has a majority,
that is, more than half the votes.
Given a sequence of elements 𝑎1, 𝑎2, . . . , 𝑎𝑛, you would like to check whether
it contains an element that appears more than 𝑛/2 times. A naive way to do
this is the following.

    MajorityElement(𝑎1, 𝑎2, . . . , 𝑎𝑛):
        for 𝑖 from 1 to 𝑛:
        currentElement ← 𝑎𝑖
        count ← 0
        for 𝑗 from 1 to 𝑛:
        if 𝑎𝑗 = currentElement:
        count ← count + 1
        if count > 𝑛/2:
        return 𝑎𝑖
        return “no majority element”
        
The running time of this algorithm is quadratic. Your goal is to use the divide-and-conquer technique to
design an 𝑂(𝑛 log 𝑛) algorithm.

What To Do
As you might have already guessed, this problem can be solved by the divide-and-conquer algorithm in time
𝑂(𝑛 log 𝑛). Indeed, if a sequence of length 𝑛 contains a majority element, then the same element is also
a majority element for one of its halves. Thus, to solve this problem you first split a given sequence into
halves and make two recursive calls. Do you see how to combine the results of two recursive calls?
It is interesting to note that this problem can also be solved in 𝑂(𝑛) time by a more advanced (non-divide
and conquer) algorithm that just scans the given sequence twice.

*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using std::vector;

template <typename T>
void print(T& container)
{
   for(auto it:container)
      std::cout << (it).first << " " << (it).second << std::endl;
}

template <typename T>
int keys(T& container)
{
  for(auto it:container)
    return (it).first;
}

template <typename T>
T& mergeContents(T& container, const T& container_const)
{
   for(auto it:container_const)
   {
      if (container[(it).first] == 0)
        container[(it).first] = (it).second;
      else
        container[(it).first] += (it).second;
   }
}

template<typename T>
int maxValue(T& container, int size)
{
   std::map<int,int> maxValue;
   for(auto it:container)
   {
     if ((it).second > size)
     {
       size = (it).second;
       maxValue[(it).first] = (it).second;
     }
   }
   
   if (maxValue.empty())
   {
     return -1;
   }
   else
   {
     return keys(maxValue);
   }
   
}

std::map<int,int> get_majority_element(vector<int> &a, int left, int right) {
  std::map<int,int> count;
  if (left == right) {
    count[a[left]] = 1; 
    return count;
  }
  if (left + 1 == right) {
    if (a[left] != a[right]) 
    {
      count[a[left]] = 1; 
      count[a[right]] = 1;
    }
    else
    {
      count[a[left]] = 2;
    }
    return count;
  }
  //write your code here
  int mid = (left+right)/2;
  
  std::map<int,int> mergeCount, major1, major2;
  major1 = get_majority_element(a, left, mid);
  major2 = get_majority_element(a, mid+1, right);

  mergeContents(mergeCount, major1);
  mergeContents(mergeCount, major2);
  return mergeCount;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::map<int,int> count = get_majority_element(a, 0, (a.size()-1));
  int output = maxValue(count, floor(a.size()/2));
  std::cout << (output != -1) << std::endl;
}
