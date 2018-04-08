/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Pizza {
private:
    string name;
    string base;
    string sauce;
    vector<string> toppings;
public:
    Pizza(string mName, string mBase, string mSauce, vector<string> mToppings):name(mName),base(mBase),sauce(mSauce),toppings(mToppings){};
    string getName(){return this->name;}
    string getBase(){return this->base;}
    string getSauce(){return this->sauce;}
    vector<string> getToppings(){return this->toppings;}
};

class CheesePizza: public Pizza {
public:
    CheesePizza():Pizza("Cheese", "Dough", "Tomato", {"olives","cheese"}){};
};

class MacaroniPizza: public Pizza {
public:
    MacaroniPizza():Pizza("Macaroni", "Dough", "Tomato", {"macaroni","cheese"}){};
};

class ChickenPizza: public Pizza {
public:
    ChickenPizza():Pizza("Chicken", "Dough", "Tomato", {"chicken","cheese"}){};
};

int main(){
    //Dynamic pizza creation.
    Pizza* pizza;
    string type;
    cout << "Enter the type of the pizza" << endl;
    cin >> type;
    if (type == "cheese"){
        pizza = new CheesePizza();
    } else if (type == "macaroni"){
        pizza = new CheesePizza();
    } else if (type == "chicken"){
        pizza = new CheesePizza();
    } else {
        cout << "Invalid pizza type" << endl;
        pizza = NULL;
    }
    
    if (pizza != NULL){
        cout << "Name of the pizza is " << pizza->getName() << endl;
        cout << "Base of the pizza is " << pizza->getBase() << endl;
        cout << "Sauce of the pizza is " << pizza->getSauce() << endl;
        vector<string> toppings = pizza->getToppings();
        for(vector<string>::iterator it=toppings.begin(); it !=toppings.end(); ++it){
            cout << "Toppings are " << *it << endl;
        }; 
    }
}


