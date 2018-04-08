/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: sivagusa
 *
 * Created on January 12, 2018, 8:05 PM
 */

#include <cstdlib>
#include "message.cpp"
/*
 * 
 */
int main(int argc, char** argv) {
    Message* msg1 = new Message("Hello","home");
    Message* msg2 = new Message("MelloW","home");
    //msg1->display();
    //msg2->display();
    Message msg3(*msg2);
    msg3.display();
    Message msg4;
    msg4 = *msg1;
    cout << "Message 4 - 1" << endl;
    msg4.display();    
    msg4 = *msg2;
    cout << "Message 4 - 2" << endl;
    msg4.display();
    cout << "Message 4 - 3" << endl;
    msg4 = msg4;
    msg4.display();
    return 0;
}

