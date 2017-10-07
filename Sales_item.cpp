#include <Sales_item.h>

int main()
{
  Sales_item A;
  Sales_item B;
  cin >> A;
  cin >> B;

  if (A.BookNo() == B.BookNo())
  {
     //cout << "true" << endl;
     cout << A + B << endl;
  }

  return 0;
}
