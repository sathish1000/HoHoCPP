/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "common.hpp"
#include "folder.cpp"

class Message {
private:
    string contents;
    vector<Folder*> folder;
    
    void addFolder(const string &folderName){
        vector<Folder*>::iterator iter;
        for(iter = folder.begin(); iter != folder.end(); iter++) {
            if ((*iter)->getName() == folderName)
            {
                break;
            }
        }
        
        if (iter != folder.end()) {
            (*iter)->addMessageToFolder(this->contents, folderName);
        }
        else
        {
            Folder* Newfolder = new Folder;
            Newfolder->addMessageToFolder(this->contents, folderName);
            folder.push_back(Newfolder);           
        }
    }
  
    void removeFolder(){      
        vector<Folder*>::iterator iter;
        for(iter = folder.begin(); iter != folder.end(); iter++) {
            (*iter)->removeMessage(this->contents);
            if ((*iter)->getSize() == 0) {
                (*iter)->~Folder();
            }
        }       
    }
    
public:
    //Constructor.
    Message(const string &s = "", const string &folderName = "temp"):contents(s){
        this->addFolder(folderName);
    }
            
    //Destructor
    ~Message(){
        this->removeFolder();
    }
    
    //Copy constructor.
    Message(Message &msg):contents(msg.contents),folder(msg.folder) {
        int i = 0;
        //Why iterator is a pointer.. 
        vector<Folder*>::iterator iter;
        for(iter = folder.begin(); iter != folder.end(); iter++) {
            this->addFolder((*iter)->getName());
        }       
    }
    
    //Copy assignment operator
    Message& operator=(Message &msg)
    {
        this->removeFolder();
        this->contents = msg.contents;
        this->folder = msg.folder;
        vector<Folder*>::iterator iter;
        for(iter = folder.begin(); iter != folder.end(); iter++) {
            this->addFolder((*iter)->getName());
        }        
        return *this;
    }
    
    void display()
    {
        cout << "Content of the message is " << this->contents << endl;
        vector<Folder*>::iterator iter;
        for(iter = folder.begin(); iter != folder.end(); iter++) {
            cout << "Folder names are " << (*iter)->getName() << endl;
        }         
    }
    
};
