#ifndef SALES_ITEM_H
#define SALES_ITEM_H

#include <iostream>
using namespace std;

class Sales_item
{

   string ISBN;
   int copies;
   double price;

   public:

   Sales_item():ISBN("0"),copies(0),price(0)
   {}

   ~Sales_item()
   {}

   std::string BookNo()
   {
   	return ISBN;
   }

   friend bool operator == (std::string& s1, std::string& s2)
   {
	return (s1 == s2) ? true : false;
   }

   friend std::istream& operator >> (std::istream& s, Sales_item& item)
   {
	s >> item.ISBN;
        s >> item.copies;
        s >> item.price;
        return s;
   }


   friend std::ostream& operator << (std::ostream& s, Sales_item& item)
   {
	s << item.ISBN << endl;
        s << item.copies << endl;
        s << item.price << endl                                                                                                                                                                                                                            ;
        return s;
   }

   friend Sales_item& operator + (Sales_item S1, Sales_item S2)
   {
        S1.copies = S1.copies + S2.copies;
        S1.price = (S1.copies*S1.price + S2.copies*S2.price)/(S1.copies + S2.copies);
   }	
};
#endif
