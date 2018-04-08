/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "common.hpp"

class Folder 
{
private:
    string name;
    vector<string> Message;
    
public:
    ~Folder(){        
    }    
    
    int getSize() {
        return Message.size();
    }
    
    string getName() {
        cout << "Call is here = " << name << endl; 
        return name;
    }
    
    void addMessageToFolder(string &s, string folderName){
        Message.push_back(s);
        if (name.empty()){
            name = folderName;
        }
    }
    
    void removeMessage(string &s){
        //Error the message.
        vector<string>::iterator result = find(Message.begin(), Message.end(), s);

        if (result == Message.end())
            cout << "The string is not in there!" << endl;
        else
            Message.erase(result);           
    }   
};
