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
}