#include <iostream>
using namespace std;

class List
{

  public:
	  int val;
	  List* next;



	  List( int x, List* t)
	  {
	    val=x;
	    next=t;
	  }

};

int main()
{
    int N=10;

    List* node = new List(1,NULL);
    node->next = node;

    for (int i=2; i<10; i++)
    {
        List* node_new = new List(i,node->next);
        node->next=node_new;
        node=node_new;      
    }  

    for (int j=1; j<10; j++)
    {
        node=node->next;
        cout << node->val << endl;    
    }

    while (node->next!=node)
    {
	    for (int k=1; k<5; k++)
	    {
		node=node->next; 
	    }
            cout << node->next->val << endl;   
            node->next=node->next->next;
    }
}


