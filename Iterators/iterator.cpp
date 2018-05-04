/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <vector>
#include <list>
#include<forward_list> 
#include <map>
#include <set>
using namespace std;

int main(){
    
    {//Vector.
        cout << "###############################################################" << endl;
        cout << "###############    RANDOM ACCESS ITERATOR    ##################" << endl;
        cout << "###############################################################" << endl;
        cout << "########   CAN BE USED ONLY ON VECTOR, DEQUE AND ARRAY ########" << endl;
        cout << "###############################################################" << endl;
        vector<int> vec = {1,2,3,4,5};
        vector<int>::iterator itr;
        vector<int>::iterator itr1;

        //Advance itr.
        itr = vec.begin();
        cout << "Start value of itr is " << *itr << endl;
        itr = itr + 3;//itr value is 4
        cout << "Value of itr+3 is " << *itr << endl;
        itr = itr - 2;//itr value is 2
        cout << "Value of itr-2 is " << *itr << endl; 

        //itr < itr1
        itr1 = vec.begin() + 1;//itr1 value is 2.
        cout << "value of itr is " << *itr << endl;
        cout << "value of itr1 is " << *itr1 << endl;
        if (itr > itr1){
            cout << "itr is greater than itr1" << endl;
        }else{
            cout << "itr is lesser or equal than itr1" << endl;
        }

        //itr > itr1
        itr1 = itr1 + 2;//itr1 value is 4.
        cout << "value of itr is " << *itr << endl;
        cout << "value of itr1 is " << *itr1 << endl;    
        if (itr > itr1){
            cout << "itr is greater than itr1" << endl;
        }else{
            cout << "itr is lesser or equal than itr1" << endl;
        }
    }
    
    //Bideirectional iterator.
    {
        cout << "###############################################################" << endl;
        cout << "###############    BIDIRECTIONAL ITERATOR    ##################" << endl;
        cout << "###############################################################" << endl;
        cout << "###   CAN BE USED ONLY ON LIST, SET/MULTISET, MAP/MULTIMAP ####" << endl;
        cout << "###############################################################" << endl;        
        list<int> lst = {1,2,3,4,5};
        list<int>::iterator list_itr = lst.begin();
        cout << "Positive increment of list is " << *(++list_itr) << endl;
        cout << "Negative decrement of list is " << *(--list_itr) << endl;
    }
    
    //Forward iterator.
    {
        cout << "###############################################################" << endl;
        cout << "###############      FORWARD ITERATOR        ##################" << endl;
        cout << "###############################################################" << endl;
        cout << "###           CAN BE USED ONLY ON FORWARD LIST             ####" << endl;
        cout << "###############################################################" << endl;        
        forward_list<int> forward_lst = {1,2,3,4,5};
        forward_list<int>::iterator forward_list_itr = forward_lst.begin();
        cout << "Positive increment of list is " << *(++forward_list_itr) << endl;
        //cout << "Negative decrement of list is " << *(--forward_list_itr) << endl;. //Not valid
    }

    //Iterator and const iterator.
    {
        cout << "###############################################################" << endl;
        cout << "###############      CONSTANT ITERATOR        #################" << endl;
        cout << "###############################################################" << endl;
       
        vector<int> myset = {1,2,3,4,5};
        const vector<int> const_myset = {1,2,3,4,5};
        vector<int>::iterator set_itr; 
        vector<int>::const_iterator set_citr;

        cout << "###############################################################" << endl;
        cout << "###############   Normal object, Normal iterator  #############" << endl;
        cout << "###############################################################" << endl;
        for(set_itr = myset.begin(); set_itr!=myset.end();set_itr++){
           cout << "normal object, iterator value is " << *set_itr << endl;
           *set_itr = *set_itr + 1;
        }

        cout << "###############################################################" << endl;
        cout << "###############   Normal object, Const iterator   #############" << endl;
        cout << "###############################################################" << endl;        
        for(set_citr = myset.cbegin(); set_citr!=myset.cend();set_citr++){
           cout << "normal object, Const iterator value is " << *set_citr << endl;
           //*set_citr = *set_citr + 1; //Const iterator. cant be changed.
        }

        cout << "###############################################################" << endl;
        cout << "###############   Const object, Normal iterator   #############" << endl;
        cout << "###############################################################" << endl; 
        for(set_citr = const_myset.begin(); set_citr!=const_myset.end();set_citr++){
           cout << "const object, normal iterator value is " << *set_citr << endl;
           //*set_citr = *set_citr + 1; //Const iterator. cant be changed.
        }                

        cout << "###############################################################" << endl;
        cout << "###############   Const object, Const iterator    #############" << endl;
        cout << "###############################################################" << endl;        
        for(set_citr = const_myset.cbegin(); set_citr!=const_myset.cend();set_citr++){
           cout << "const object, Const iterator value is " << *set_citr << endl; 
           //*set_citr = *set_citr + 1; //Const iterator. cant be changed.
        }        
    }

    return 0;
}


