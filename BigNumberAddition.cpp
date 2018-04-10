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
	
}