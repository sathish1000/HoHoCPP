#include <iostream>
using namespace std;

int main()
{
  int x=20, y=35, i=1, j=0;

  x=y++ + x++;
  cout << x << " " << y << endl;
  y=++y + ++x;
  cout << x << " " << y << endl;
  i = ++i;
  cout << i << endl;
  i = ++i;
  cout << i << endl;

}
