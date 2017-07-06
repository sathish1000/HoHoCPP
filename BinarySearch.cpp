/*
Binary search problem.
In this problem, you will implement the binary search algorithm that allows searching
very efficiently (even huge) lists, provided that the list is sorted.

Sample 1.
Input:
5 1 5 8 12 13
5 8 1 23 1 11
Output:
2 0 -1 0 -1
Explanation:
In this sample, we are given an increasing sequence 𝑎0 = 1, 𝑎1 = 5, 𝑎2 = 8, 𝑎3 = 12, 𝑎4 = 13 of length
five and five keys to search: 8, 1, 23, 1, 11. We see that 𝑎2 = 8 and 𝑎0 = 1, but the keys 23 and 11 do
not appear in the sequence 𝑎. For this reason, we output a sequence 2, 0, −1, 0, −1.
*/

#include <iostream>
#include <cassert>
#include <vector>
//#include <ctime>

using std::vector;

signed int recursive_binary(const vector<int> &a, int x, int left, int right) {
  unsigned int mid = (int)((left + right)/2);

  //Base case :- if the value is found, return the index mid for the value.
  if (a.at(mid) == x)
	  return mid;
	  
  //Base case:- If the mid has reached the ends(left or right) and it doesnt match the value, then 
  //return -1 for not found.
  if ((mid == left) or (mid == right))
    return -1;	  

  //Recursion case.
  if (a.at(mid) <= x) {
    mid = recursive_binary(a, x, mid+1, right);
  }
  else {
  	mid = recursive_binary(a, x, left, mid);
  }
  return mid;
}

int binary_search(const vector<int> &a, int x) {
  int left = 0, right = ((int)a.size()-1); 
  signed int mid = recursive_binary(a, x, left, right);
  return mid;
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    //const clock_t begin_time1 = clock();
    std::cout << linear_search(a, b[i]) << std::endl;
    //std::cout << float( clock () - begin_time1 ) /  CLOCKS_PER_SEC << std::endl;
    
    //const clock_t begin_time2 = clock();
    std::cout << binary_search(a, b[i]) << std::endl;
    //std::cout << float( clock () - begin_time2 ) /  CLOCKS_PER_SEC << std::endl;
  }
  return 0;
}
