//The code is to add two big numbers that dont fall inside the size of the regular integer types.
#include <iostream>
#include <vector>
#include <string> 
using namespace std;

int main()
{
	int N;
	int maxSize = 0;
	cout << "Enter the number of the items to be added" << endl;
	cin >> N;
	
	vector<string> Items(N);
	for (int i=0; i<N; i++)
	{
		cin >> Items[i];
	}
	
	for (int i=0; i<N; i++)
	{
	  if (Items[i].size() > maxSize)
		  maxSize = Items[i].size();
	}
	
	int prev = 0;
	vector<string> Sum(maxSize+1);
	for (int i=(maxSize-1); i>=0; i--)
	{
	  int sum = int(Items[0][i] - '0') + int(Items[1][i] - '0') + prev;
	  prev = 0;
	  if (sum > 9)
	  {
	     prev = 1;
	     sum = sum%10;
	  }
	  Sum[i+1] = std::to_string(sum);
	}

	if (prev == 0)
	  Sum[0] = std::to_string(0);
	else
	  Sum[0] = std::to_string(1);

	for (int i=0; i<Sum.size(); i++)
	  cout << Sum[i];
	
}/*
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
//The code is to add two big numbers that dont fall inside the size of the regular integer types.
#include <iostream>
#include <vector>
#include <string> 
using namespace std;

int main()
{
	int N;
	int maxSize = 0;
	cout << "Enter the number of the items to be added" << endl;
	cin >> N;
	
	vector<string> Items(N);
	for (int i=0; i<N; i++)
	{
		cin >> Items[i];
	}
	
	for (int i=0; i<N; i++)
	{
	  if (Items[i].size() > maxSize)
		  maxSize = Items[i].size();
	}
	
	int prev = 0;
	vector<string> Sum(maxSize+1);
	for (int i=(maxSize-1); i>=0; i--)
	{
	  int sum = int(Items[0][i] - '0') + int(Items[1][i] - '0') + prev;
	  prev = 0;
	  if (sum > 9)
	  {
	     prev = 1;
	     sum = sum%10;
	  }
	  Sum[i+1] = std::to_string(sum);
	}

	if (prev == 0)
	  Sum[0] = std::to_string(0);
	else
	  Sum[0] = std::to_string(1);

	for (int i=0; i<Sum.size(); i++)
	  cout << Sum[i];
	
}/*
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
//The code is to add two big numbers that dont fall inside the size of the regular integer types.
#include <iostream>
#include <vector>
#include <string> 
using namespace std;

int main()
{
	int N;
	int maxSize = 0;
	cout << "Enter the number of the items to be added" << endl;
	cin >> N;
	
	vector<string> Items(N);
	for (int i=0; i<N; i++)
	{
		cin >> Items[i];
	}
	
	for (int i=0; i<N; i++)
	{
	  if (Items[i].size() > maxSize)
		  maxSize = Items[i].size();
	}
	
	int prev = 0;
	vector<string> Sum(maxSize+1);
	for (int i=(maxSize-1); i>=0; i--)
	{
	  int sum = int(Items[0][i] - '0') + int(Items[1][i] - '0') + prev;
	  prev = 0;
	  if (sum > 9)
	  {
	     prev = 1;
	     sum = sum%10;
	  }
	  Sum[i+1] = std::to_string(sum);
	}

	if (prev == 0)
	  Sum[0] = std::to_string(0);
	else
	  Sum[0] = std::to_string(1);

	for (int i=0; i<Sum.size(); i++)
	  cout << Sum[i];
	
}/*
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
//The code is to add two big numbers that dont fall inside the size of the regular integer types.
#include <iostream>
#include <vector>
#include <string> 
using namespace std;

int main()
{
	int N;
	int maxSize = 0;
	cout << "Enter the number of the items to be added" /*
Problem: Maximizing the Number of Prize Places in a Competition
Problem Introduction
You are organizing a funny competition for children. As a prize fund you have 𝐍
candies. You would like to use these candies for top 𝐠places in a competition
with a natural restriction that a higher place gets a larger number of candies.
To make as many children happy as possible, you are going to fnd the largest
value of 𝐠for which it is possible.
Problem Description
Task. The goal of this problem is to represent a given positive integer 𝐠as a sum of as many pairwise
distinct positive integers as possible. That is, to fnd the maximum 𝐠such that 𝐠can be written as
𝐱 + 𝐲 + · · · + 𝐵 where 𝐱, . . . , 𝐵 are positive integers and 𝐵 ̸= 𝐵 for all 1 ≤ 𝐠< 𝐠≤ 𝐮
Input Format. The input consists of a single integer 𝐮
Constraints. 1 ≤ 𝐠≤ 109.
Output Format. In the frst line, output the maximum number 𝐠such that 𝐠can be represented as a sum
of 𝐠pairwise distinct positive integers. In the second line, output 𝐠pairwise distinct positive integers
that sum up to 𝐠(if there are many such representations, output any of them).
Time Limits.
language C C++ Java Python C# Haskell JavaScript Ruby Scala
time (sec) 1 1 1.5 5 1.5 2 5 5 3
Memory Limit. 512MB.
Sample 1.
Input:
6
Output:
3
1 2 3
Sample 2.
Input:
8
Output:
3
1 2 5
Sample 3.
Input:
2
Output:
12
*/

#include <iostream>
#include <vector>
#include <cmath>

using std::vector;

vector<double> optimal_summands(int n) {
  vector<double> summands;
  double count = int(std::sqrt(n)*2);
  double sum=0;
  for (double i=count; i>=1; --i)
  {
    sum=0;
    sum=i*(i+1)/2;
    if (sum <= n)
    {
      int diff = n - sum;
      for (int j=1; j<i; ++j)
      {
        summands.push_back(j);
      }
      summands.push_back(i+diff);
      break;
    }
  }
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<double> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}/*
A left rotation operation on an array of size n shifts each of the array's elements 1 unit to the left. For example, if 2 left rotations are performed on array [1 2 3 4 5], then the array would become [3 4 5 1 2].

Given an array of n integers and a number, d, perform d left rotations on the array. Then print the updated array as a single line of space-separated integers.

Input Format

The first line contains two space-separated integers denoting the respective values of n (the number of integers) and d (the number of left rotations you must perform). 
The second line contains n space-separated integers describing the respective elements of the array's initial state.

Constraints

1 <= n <= 10^5
1 <= d <= n
1 < ai < 10^6

Output Format

Print a single line of n space-separated integers denoting the final state of the array after performing d left rotations.

Sample Input

5 4
1 2 3 4 5
Sample Output

5 1 2 3 4
Explanation

When we perform d=4 left rotations, the array undergoes the following sequence of changes:

Thus, we print the array's final state as a single line of space-separated values, which is 5 1 2 3 4.
*/

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> array_left_rotation(vector<int> a, int n, int k) {
    std::rotate(a.begin(),a.begin()+k,a.end());
    return a;
}

int main(){
    int n;
    int k;
    cin >> n >> k;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
        cin >> a[a_i];
    }
    vector<int> output = array_left_rotation(a, n, k);
    for(int i = 0; i < n;i++)
        cout << output[i] << " ";
    cout << endl;
    return 0;
}
/*
Problem: Maximizing the Number of Prize Places in a Competition
Problem Introduction
You are organizing a funny competition for children. As a prize fund you have 𝐍
candies. You would like to use these candies for top 𝐠places in a competition
with a natural restriction that a higher place gets a larger number of candies.
To make as many children happy as possible, you are going to fnd the largest
value of 𝐠for which it is possible.
Problem Description
Task. The goal of this problem is to represent a given positive integer 𝐠as a sum of as many pairwise
distinct positive integers as possible. That is, to fnd the maximum 𝐠such that 𝐠can be written as
𝐱 + 𝐲 + · · · + 𝐵 where 𝐱, . . . , 𝐵 are positive integers and 𝐵 ̸= 𝐵 for all 1 ≤ 𝐠< 𝐠≤ 𝐮
Input Format. The input consists of a single integer 𝐮
Constraints. 1 ≤ 𝐠≤ 109.
Output Format. In the frst line, output the maximum number 𝐠such that 𝐠can be represented as a sum
of 𝐠pairwise distinct positive integers. In the second line, output 𝐠pairwise distinct positive integers
that sum up to 𝐠(if there are many such representations, output any of them).
Time Limits.
language C C++ Java Python C# Haskell JavaScript Ruby Scala
time (sec) 1 1 1.5 5 1.5 2 5 5 3
Memory Limit. 512MB.
Sample 1.
Input:
6
Output:
3
1 2 3
Sample 2.
Input:
8
Output:
3
1 2 5
Sample 3.
Input:
2
Output:
12
*/

#include <iostream>
#include <vector>
#include <cmath>

using std::vector;

vector<double> optimal_summands(int n) {
  vector<double> summands;
  double count = int(std::sqrt(n)*2);
  double sum=0;
  for (double i=count; i>=1; --i)
  {
    sum=0;
    sum=i*(i+1)/2;
    if (sum <= n)
    {
      int diff = n - sum;
      for (int j=1; j<i; ++j)
      {
        summands.push_back(j);
      }
      summands.push_back(i+diff);
      break;
    }
  }
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<double> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}/*
A left rotation operation on an array of size n shifts each of the array's elements 1 unit to the left. For example, if 2 left rotations are performed on array [1 2 3 4 5], then the array would become [3 4 5 1 2].

Given an array of n integers and a number, d, perform d left rotations on the array. Then print the updated array as a single line of space-separated integers.

Input Format

The first line contains two space-separated integers denoting the respective values of n (the number of integers) and d (the number of left rotations you must perform). 
The second line contains n space-separated integers describing the respective elements of the array's initial state.

Constraints

1 <= n <= 10^5
1 <= d <= n
1 < ai < 10^6

Output Format

Print a single line of n space-separated integers denoting the final state of the array after performing d left rotations.

Sample Input

5 4
1 2 3 4 5
Sample Output

5 1 2 3 4
Explanation

When we perform d=4 left rotations, the array undergoes the following sequence of changes:

Thus, we print the array's final state as a single line of space-separated values, which is 5 1 2 3 4.
*/

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> array_left_rotation(vector<int> a, int n, int k) {
    std::rotate(a.begin(),a.begin()+k,a.end());
    return a;
}

int main(){
    int n;
    int k;
    cin >> n >> k;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
        cin >> a[a_i];
    }
    vector<int> output = array_left_rotation(a, n, k);
    for(int i = 0; i < n;i++)
        cout << output[i] << " ";
    cout << endl;
    return 0;
}
//The code is to add two big numbers that dont fall inside the size of the regular integer types.
#include <iostream>
#include <vector>
#include <string> 
using namespace std;

int main()
{
	int N;
	int maxSize = 0;
	cout << "Enter the number of the items to be added" << endl;
	cin >> N;
	
	vector<string> Items(N);
	for (int i=0; i<N; i++)
	{
		cin >> Items[i];
	}
	
	for (int i=0; i<N; i++)
	{
	  if (Items[i].size() > maxSize)
		  maxSize = Items[i].size();
	}
	
	int prev = 0;
	vector<string> Sum(maxSize+1);
	for (int i=(maxSize-1); i>=0; i--)
	{
	  int sum = int(Items[0][i] - '0') + int(Items[1][i] - '0') + prev;
	  prev = 0;
	  if (sum > 9)
	  {
	     prev = 1;
	     sum = sum%10;
	  }
	  Sum[i+1] = std::to_string(sum);
	}

	if (prev == 0)
	  Sum[0] = std::to_string(0);
	else
	  Sum[0] = std::to_string(1);

	for (int i=0; i<Sum.size(); i++)
	  cout << Sum[i];
	
}/*
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
//The code is to add two big numbers that dont fall inside the size of the regular integer types.
#include <iostream>
#include <vector>
#include <string> 
using namespace std;

int main()
{
	int N;
	int maxSize = 0;
	cout << "Enter the number of the items to be added" << endl;
	cin >> N;
	
	vector<string> Items(N);
	for (int i=0; i<N; i++)
	{
		cin >> Items[i];
	}
	
	for (int i=0; i<N; i++)
	{
	  if (Items[i].size() > maxSize)
		  maxSize = Items[i].size();
	}
	
	int prev = 0;
	vector<string> Sum(maxSize+1);
	for (int i=(maxSize-1); i>=0; i--)
	{
	  int sum = int(Items[0][i] - '0') + int(Items[1][i] - '0') + prev;
	  prev = 0;
	  if (sum > 9)
	  {
	     prev = 1;
	     sum = sum%10;
	  }
	  Sum[i+1] = std::to_string(sum);
	}

	if (prev == 0)
	  Sum[0] = std::to_string(0);
	else
	  Sum[0] = std::to_string(1);

	for (int i=0; i<Sum.size(); i++)
	  cout << Sum[i];
	
}/*
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
//The code is to add two big numbers that dont fall inside the size of the regular integer types.
#include <iostream>
#include <vector>
#include <string> 
using namespace std;

int main()
{
	int N;
	int maxSize = 0;
	cout << "Enter the number of the items to be added" << endl;
	cin >> N;
	
	vector<string> Items(N);
	for (int i=0; i<N; i++)
	{
		cin >> Items[i];
	}
	
	for (int i=0; i<N; i++)
	{
	  if (Items[i].size() > maxSize)
		  maxSize = Items[i].size();
	}
	
	int prev = 0;
	vector<string> Sum(maxSize+1);
	for (int i=(maxSize-1); i>=0; i--)
	{
	  int sum = int(Items[0][i] - '0') + int(Items[1][i] - '0') + prev;
	  prev = 0;
	  if (sum > 9)
	  {
	     prev = 1;
	     sum = sum%10;
	  }
	  Sum[i+1] = std::to_string(sum);
	}

	if (prev == 0)
	  Sum[0] = std::to_string(0);
	else
	  Sum[0] = std::to_string(1);

	for (int i=0; i<Sum.size(); i++)
	  cout << Sum[i];
	
}/*
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
//The code is to add two big numbers that dont fall inside the size of the regular integer types.
#include <iostream>
#include <vector>
#include <string> 
using namespace std;

int main()
{
	int N;
	int maxSize = 0;
	cout << "Enter the number of the items to be added" /*
Problem: Maximizing the Number of Prize Places in a Competition
Problem Introduction
You are organizing a funny competition for children. As a prize fund you have 𝐍
candies. You would like to use these candies for top 𝐠places in a competition
with a natural restriction that a higher place gets a larger number of candies.
To make as many children happy as possible, you are going to fnd the largest
value of 𝐠for which it is possible.
Problem Description
Task. The goal of this problem is to represent a given positive integer 𝐠as a sum of as many pairwise
distinct positive integers as possible. That is, to fnd the maximum 𝐠such that 𝐠can be written as
𝐱 + 𝐲 + · · · + 𝐵 where 𝐱, . . . , 𝐵 are positive integers and 𝐵 ̸= 𝐵 for all 1 ≤ 𝐠< 𝐠≤ 𝐮
Input Format. The input consists of a single integer 𝐮
Constraints. 1 ≤ 𝐠≤ 109.
Output Format. In the frst line, output the maximum number 𝐠such that 𝐠can be represented as a sum
of 𝐠pairwise distinct positive integers. In the second line, output 𝐠pairwise distinct positive integers
that sum up to 𝐠(if there are many such representations, output any of them).
Time Limits.
language C C++ Java Python C# Haskell JavaScript Ruby Scala
time (sec) 1 1 1.5 5 1.5 2 5 5 3
Memory Limit. 512MB.
Sample 1.
Input:
6
Output:
3
1 2 3
Sample 2.
Input:
8
Output:
3
1 2 5
Sample 3.
Input:
2
Output:
12
*/

#include <iostream>
#include <vector>
#include <cmath>

using std::vector;

vector<double> optimal_summands(int n) {
  vector<double> summands;
  double count = int(std::sqrt(n)*2);
  double sum=0;
  for (double i=count; i>=1; --i)
  {
    sum=0;
    sum=i*(i+1)/2;
    if (sum <= n)
    {
      int diff = n - sum;
      for (int j=1; j<i; ++j)
      {
        summands.push_back(j);
      }
      summands.push_back(i+diff);
      break;
    }
  }
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<double> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}/*
A left rotation operation on an array of size n shifts each of the array's elements 1 unit to the left. For example, if 2 left rotations are performed on array [1 2 3 4 5], then the array would become [3 4 5 1 2].

Given an array of n integers and a number, d, perform d left rotations on the array. Then print the updated array as a single line of space-separated integers.

Input Format

The first line contains two space-separated integers denoting the respective values of n (the number of integers) and d (the number of left rotations you must perform). 
The second line contains n space-separated integers describing the respective elements of the array's initial state.

Constraints

1 <= n <= 10^5
1 <= d <= n
1 < ai < 10^6

Output Format

Print a single line of n space-separated integers denoting the final state of the array after performing d left rotations.

Sample Input

5 4
1 2 3 4 5
Sample Output

5 1 2 3 4
Explanation

When we perform d=4 left rotations, the array undergoes the following sequence of changes:

Thus, we print the array's final state as a single line of space-separated values, which is 5 1 2 3 4.
*/

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> array_left_rotation(vector<int> a, int n, int k) {
    std::rotate(a.begin(),a.begin()+k,a.end());
    return a;
}

int main(){
    int n;
    int k;
    cin >> n >> k;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
        cin >> a[a_i];
    }
    vector<int> output = array_left_rotation(a, n, k);
    for(int i = 0; i < n;i++)
        cout << output[i] << " ";
    cout << endl;
    return 0;
}
/*
Problem: Maximizing the Number of Prize Places in a Competition
Problem Introduction
You are organizing a funny competition for children. As a prize fund you have 𝐍
candies. You would like to use these candies for top 𝐠places in a competition
with a natural restriction that a higher place gets a larger number of candies.
To make as many children happy as possible, you are going to fnd the largest
value of 𝐠for which it is possible.
Problem Description
Task. The goal of this problem is to represent a given positive integer 𝐠as a sum of as many pairwise
distinct positive integers as possible. That is, to fnd the maximum 𝐠such that 𝐠can be written as
𝐱 + 𝐲 + · · · + 𝐵 where 𝐱, . . . , 𝐵 are positive integers and 𝐵 ̸= 𝐵 for all 1 ≤ 𝐠< 𝐠≤ 𝐮
Input Format. The input consists of a single integer 𝐮
Constraints. 1 ≤ 𝐠≤ 109.
Output Format. In the frst line, output the maximum number 𝐠such that 𝐠can be represented as a sum
of 𝐠pairwise distinct positive integers. In the second line, output 𝐠pairwise distinct positive integers
that sum up to 𝐠(if there are many such representations, output any of them).
Time Limits.
language C C++ Java Python C# Haskell JavaScript Ruby Scala
time (sec) 1 1 1.5 5 1.5 2 5 5 3
Memory Limit. 512MB.
Sample 1.
Input:
6
Output:
3
1 2 3
Sample 2.
Input:
8
Output:
3
1 2 5
Sample 3.
Input:
2
Output:
12
*/

#include <iostream>
#include <vector>
#include <cmath>

using std::vector;

vector<double> optimal_summands(int n) {
  vector<double> summands;
  double count = int(std::sqrt(n)*2);
  double sum=0;
  for (double i=count; i>=1; --i)
  {
    sum=0;
    sum=i*(i+1)/2;
    if (sum <= n)
    {
      int diff = n - sum;
      for (int j=1; j<i; ++j)
      {
        summands.push_back(j);
      }
      summands.push_back(i+diff);
      break;
    }
  }
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<double> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}/*
A left rotation operation on an array of size n shifts each of the array's elements 1 unit to the left. For example, if 2 left rotations are performed on array [1 2 3 4 5], then the array would become [3 4 5 1 2].

Given an array of n integers and a number, d, perform d left rotations on the array. Then print the updated array as a single line of space-separated integers.

Input Format

The first line contains two space-separated integers denoting the respective values of n (the number of integers) and d (the number of left rotations you must perform). 
The second line contains n space-separated integers describing the respective elements of the array's initial state.

Constraints

1 <= n <= 10^5
1 <= d <= n
1 < ai < 10^6

Output Format

Print a single line of n space-separated integers denoting the final state of the array after performing d left rotations.

Sample Input

5 4
1 2 3 4 5
Sample Output

5 1 2 3 4
Explanation

When we perform d=4 left rotations, the array undergoes the following sequence of changes:

Thus, we print the array's final state as a single line of space-separated values, which is 5 1 2 3 4.
*/

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> array_left_rotation(vector<int> a, int n, int k) {
    std::rotate(a.begin(),a.begin()+k,a.end());
    return a;
}

int main(){
    int n;
    int k;
    cin >> n >> k;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
        cin >> a[a_i];
    }
    vector<int> output = array_left_rotation(a, n, k);
    for(int i = 0; i < n;i++)
        cout << output[i] << " ";
    cout << endl;
    return 0;
}
//The code is to add two big numbers that dont fall inside the size of the regular integer types.
#include <iostream>
#include <vector>
#include <string> 
using namespace std;

int main()
{
	int N;
	int maxSize = 0;
	cout << "Enter the number of the items to be added" << endl;
	cin >> N;
	
	vector<string> Items(N);
	for (int i=0; i<N; i++)
	{
		cin >> Items[i];
	}
	
	for (in//Gives a error becoz privateInteger is private.
#include <iostream>
using namespace std;

class Base
{
    private:
        int privateInteger=5;
};

class Derived: private Base //Even though , Base is inherited private, if it is public in base class,
//Derived class can access it.
{
    public:
        int readPrivate()
        {
            return Base::privateInteger;
        }
};

int main()
{
    Derived Der;
    Der.readPrivate();
    return 0;
}
//Protected members are available in Derived class and the class itself.
//Not available in Derived_1 because it creates a object of base class and tries to access protected members.
#include <iostream>
using namespace std;

class Base
{
    protected:
        int protectedInteger=5;
};

class Derived: private Base
{
    public:
        int readProtected()
        {
            return Base::protectedInteger;
        }
};

class Derived_1
{
    private:
        Base protectedBase;
    public:
        int readProtected()
        {
            return protectedBase.protectedInteger;
        }
};

int main()
{
    Derived Der;
    Der.readProtected();
    return 0;
}
#include <iostream>
using namespace std;

class Base
{
    public:
        int protectedInteger=5;
};

class Derived: private Base
{
    public:
        int readProtected()
        {
            return Base::protectedInteger;
        }
};

class Derived_1
{
    private:
        Base protectedBase;
    public:
        int readProtected()
        {
            return protectedBase.protectedInteger;
        }
};

int main()
{
    Derived Der;
    Der.readProtected();
    return 0;
}
#include <iostream>
using namespace std;

class Rectangle{

    private:
        int x;
        int y;

    public:
        Rectangle(int a, int b):x(a),y(b){};
        int area(){
            return (x*y);
        } 
};

int main(){
    Rectangle RectA(5,10);
    cout << RectA.area() << endl;
    return 0;
}
#include <iostream>
using namespace std;

class Rectangle{

    private:
        int* x;
        int* y;

    public:
        Rectangle(int a, int b){
            x = new int;
            y = new int;
            *x = a;
	    *y = b;		
	};
        ~Rectangle(){
            cout << "Deconstructor called" << endl;
            delete x;
	    delete y;
	}
        int area(){
            return ((*x)*(*y));
        } 
};

int main(){
    Rectangle RectA(5,10);
    cout << RectA.area() << endl;
    cout << "Return 0" << endl;
    return 0;
}
#include <iostream>
using namespace std;

class Rectangle{

    private:
        int x;
        int y;

    public:
//        Rectangle():x(15),y(20){};
        Rectangle(int a):x(a),y(a){};
        Rectangle(int a, int b):x(a),y(b){};
        int area(){
            return (x*y);
        } 
};

int main(){
    //Constructors are called based on the number of arguments passed.
    Rectangle RectA(5,10);
    Rectangle RectB(5);
//    Rectangle RectC;
    cout << RectA.area() << endl;
    cout << RectB.area() << endl;
//    cout << RectC.area() << endl;
    return 0;
}
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
#include <iostream>
#include <deque>
using namespace std;

int main(){
deque<int> deq = {10,34,25};
deq.push_back(5);
deq.push_front(2);
deq.push_front(9);

//C++11 way to access elements in a container.
cout << "C++11 way to access container" << endl;
for (auto itr: deq)
    cout << itr << endl;

//Random access.
cout << "Random access using deque" << endl;
cout << deq[1] << endl;

return 0;
}
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
lst.push_back(1);
lst.push_front(9);
cout << "Elements in a original list" << endl;
print(lst);
list<int>::iterator itr = find(lst.begin(), lst.end(), 7);
lst.insert(itr,55);
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
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool descend(int i, int j){
return i>j;
}

int main(){

vector<int> vec; //vec.size()=0
vec.push_back(5);
vec.push_back(1);
vec.push_back(8);

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

//Common functions across containers.
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
vec.clear();
cout << "Clear contents of vector VEC" << endl;
for (vector<int>::iterator itr=vec.begin(); itr!=vec.end(); itr++)
    cout << *itr << endl;

//Swap contents of a vector.
vec2.swap(vec);
cout << "Swap contents of vector " << endl;
cout << "Contents of vector VEC " << endl;
for (vector<int>::iterator itr=vec.begin(); itr!=vec.end(); itr++)
    cout << *itr << endl;

cout << "Contents of vector VEC2 " << endl;
for (vector<int>::iterator itr=vec2.begin(); itr!=vec2.end(); itr++)
    cout << *itr << endl;

return 0;
}
//Difference between Function and class template.
//Function template can infer the datatype from function call itself. But in class template, it is not possible.
//You have to explicitly mention the datatype in class template class.


#include <iostream>
using namespace std;

template <typename T>
T square (T x){
cout << "template function" << endl;
return x*x;
}

template <typename T>
class Stack
{
T array[100];
int size;

public:
Stack():size(0) {};
void push(int a) {array[size]=a; size++;};
void print() const { for (int i=0; i<size; i++){cout << array[i] << endl;} }
int getSize() const {return size;}
int get(int i) const {return array[i];}
};

//Basically, this is a array multiplication independent of the type.
template <typename T>
Stack<T> operator* (Stack<T>& rhs1, Stack<T>& rhs2){
Stack<T> stack;
for (int i=0; i<rhs1.getSize(); i++)
{
stack.push(rhs1.get(i)*rhs2.get(i));
}
return stack;
};

int main(){
Stack<int> stack;
stack.push(5);
stack.push(1);
stack.push(4);
stack.print();
stack = square(stack);
stack.print();
return 0;
}
//CODE BLOAT ISSUE WITH TEMPLATES.
//Even though, we have a single template function, when you call it using different datatypes, a function for
//each datatype is generated in the background. So in the final image, each template will generate code for 
//the no of different datatypes that are used on the template.

#include <iostream>
using namespace std;

/*
int square (int a){
cout << "int function" << endl;
return a*a;
};

double square (double a){
cout << "double function" << endl;
return a*a;
};
*/

template <typename T>
T square (T x){
cout << "template function" << endl;
return x*x;
}

int square (int a){
cout << "int function" << endl;
return a*a;
};

double square (double a){
cout << "double function" << endl;
return a*a;
};

int main(){
cout << square<int>(5) << endl;
cout << square<float>(5.5) << endl;
cout << square(5) << endl;
cout << square(5.5) << endl;
return 0;
}
#include <iostream>
using namespace std;

class Name{
	private:
	string Fname;
	string Lname;

	public:
	Name(string A, string B):Fname(A),Lname(B){
                cout << "In constructor. The name is " << Fname << "." << Lname << endl;
	};
        ~Name(){
                cout << "In destructor. The name is " << Fname << "." << Lname << endl;
        };
	void getname(){
		cout << "In getname. The name is " << Fname << "." << Lname << endl;
	};
	void setname(string s){
		Fname=s;
	};
};

void nonConstFunction(Name a, Name* b, Name& c){

cout << "Entering non const function" << endl;
	a.setname("Bhavani");
        b->setname("Savita");
        c.setname("Renuka");

        a.getname();
        b->getname();
        c.getname();
cout << "Leaving non const function" << endl;
};

int main()
{
	Name First("Sathish","Kumar");
        Name Second("Saravana","Kumar");
        Name Third("Siva","Kumar");

        nonConstFunction(First,&Second,Third);
        cout << "Objects are destructed in the reverse order they are constructed" << endl;
}
#include <iostream>
#include <sstream>
using namespace std;

class ComplexNumber{

	private:
	int real;
	int imaginary;

	public:
	ComplexNumber(int x, int y):real(x),imaginary(y){};
	ComplexNumber operator+ (const ComplexNumber &cNum){
		this->real = this->real + cNum.real;//These steps will update the variables of c1.
		//To avoid updating c1, use commented steps below.
		this->imaginary = this->imaginary + cNum.imaginary;

                //int treal = this->real + cNum.real;
                //int timaginary = this->imaginary + cNum.imaginary;
                //return ComplexNumber(treal,timaginary);

		return ComplexNumber(this->real,this->imaginary);
	}

        ComplexNumber add(const ComplexNumber &cNum){
                this->real = this->real + cNum.real;
                this->imaginary = this->imaginary + cNum.imaginary;
                return ComplexNumber(this->real,this->imaginary);
        }

        string toString(){
		ostringstream ostr;
		ostr << "Real = " << real << ", Imaginary = " << imaginary << "." << endl;
		return ostr.str();
	}

};

int main(){
	ComplexNumber c1 = ComplexNumber(10,5);
        ComplexNumber c2 = ComplexNumber(5,10);

        ComplexNumber c3 = c1+c2;
        ComplexNumber c4 = c1.add(c2);

        cout << c3.toString() << endl;
        cout << c4.toString() << endl;
	return 0;
}
#include <iostream>
using namespace std;

class Temp{
	int count;
	public:
	Temp():count(5) {};
        //Prefix increment.
	void operator ++(){
		count++;
	};
        //Postfix increment.
        void operator ++(int){
                count++;
        };
	void display(){
		cout << count << endl;
	};
};

int main(){
	Temp t;
	++t;
//	t++;//error: no ‘operator++(int)’ declared for postfix ‘++’ [-fpermissive]
        t++;
	t.display();
	return 0;
}
#include <iostream>
using namespace std;

class RectangleC{

        int x;
        int y;

    public:
        RectangleC(int a, int b):x(a),y(b){};
        int area(){
            return (x*y);
        } 
};

struct RectangleS{

        int x;
        int y;

        RectangleS(int a, int b){
            x=a;
            y=b;
	};
        int area(){
            return (x*y);
        } 
};


int main(){

    //Difference between struct anfd class.

    RectangleC RectA(5,10);
    //cout << RectA.x << endl; //Gives a error.

    RectangleS RectB(5,10);
    cout << RectB.x << endl;

    //Pointer to a class.
    RectangleC* rect = new RectangleC(15,20);
    cout << rect->area() << endl;
    return 0;
}
#include <iostream>
using namespace std;

class Employee
{
string Name;
string Department;

public:
Employee(string N, string Dprt):Name(N),Department(Dprt){};
virtual int salary() {return 0;};
};

class Hourly: public Employee
{
int hoursworked;

public:
Hourly(string N, string Dprt, int hours):Employee(N, Dprt),hoursworked(hours) {};
int salary() {return 15*hoursworked;};
};

class Monthly: public Employee
{

public:
Monthly(string N, string Dprt):Employee(N, Dprt){};
int salary() {return 1500;};
};

int main()
{

Employee* E1 = new Employee("Sathish","Goods");
Employee* E2 = new Hourly("Saravana","Auto",15);
Employee* E3 = new Monthly("Siva","Electric");

cout << E1->salary() << endl;
cout << E2->salary() << endl;
cout << E3->salary() << endl;
return 0;
}
#include <iostream>
#include <thread>
using namespace std;

void call_from_thread()
{
    cout << "Hello world" << endl;
}

int main()
{
    std::thread t;
    t = std::thread(call_from_thread);//Starts a thread t that calls the function.
    t.join();//The main program waits for the thread to finish its execution.
    return 0;
}

#include <iostream>
#include <thread>
using namespace std;

void call_from_thread()
{
    cout << "Hello world" << endl;
}

int main()
{
    std::thread t;
    t = std::thread(call_from_thread);//Starts a thread t that calls the function.
//    t.join();//The main program waits for the thread to finish its execution.
    t.detach();
    return 0;
}

#include <iostream>
#include <thread>
using namespace std;

void call_from_thread()
{
    cout << "Hello world" << endl;
}

int main()
{
    std::thread t;
    t = std::thread(call_from_thread);//Starts a thread t that calls the function.
//    t.join();//The main program waits for the thread to finish its execution.
    t.detach();

    if (t.joinable())
    {
       t.join();
    }

    return 0;
}

