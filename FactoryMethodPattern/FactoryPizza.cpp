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

class ChicagoCheesePizza: public Pizza {
public:
    ChicagoCheesePizza():Pizza("ChicagoCheese", "Dough", "Tomato", {"olives","cheese"}){};
};

class ChicagoMacaroniPizza: public Pizza {
public:
    ChicagoMacaroniPizza():Pizza("ChicagoMacaroni", "Dough", "Tomato", {"macaroni","cheese"}){};
};

class ChicagoChickenPizza: public Pizza {
public:
    ChicagoChickenPizza():Pizza("ChicagoChicken", "Dough", "Tomato", {"chicken","cheese"}){};
};

class NYCheesePizza: public Pizza {
public:
    NYCheesePizza():Pizza("NYCheese", "Dough", "Tomato", {"olives","cheese"}){};
};

class NYMacaroniPizza: public Pizza {
public:
    NYMacaroniPizza():Pizza("NYMacaroni", "Dough", "Tomato", {"macaroni","cheese"}){};
};

class NYChickenPizza: public Pizza {
public:
    NYChickenPizza():Pizza("NYChicken", "Dough", "Tomato", {"chicken","cheese"}){};
};

class PizzaFactory{
public:
    virtual Pizza* createOrder(string type){};
};

class ChicagoPizzaFactory: public PizzaFactory{
public:
    Pizza* createOrder(string type){
        if (type == "cheese"){
            return new ChicagoCheesePizza();
        } else if (type == "macaroni"){
            return new ChicagoMacaroniPizza();
        } else if (type == "chicken"){
            return new ChicagoChickenPizza();
        } else {
            cout << "Invalid pizza type" << endl;
            return NULL;
        }        
    }
};

class NYPizzaFactory: public PizzaFactory{
public:
    Pizza* createOrder(string type){
        if (type == "cheese"){
            return new NYCheesePizza();
        } else if (type == "macaroni"){
            return new NYMacaroniPizza();
        } else if (type == "chicken"){
            return new NYChickenPizza();
        } else {
            cout << "Invalid pizza type" << endl;
            return NULL;
        }        
    }
};

class PizzaStore{
    PizzaFactory* pizzafactory;
    
public:
    PizzaStore(PizzaFactory* pizzafactori){
        PizzaFactory* newFactory = new PizzaFactory();
        newFactory = pizzafactori;
        this->pizzafactory = newFactory;
    }
    
    Pizza* orderPizza(string type){
        return pizzafactory->createOrder(type);
    }
};

int main(){
    //Dynamic pizza creation.
    PizzaFactory* pizzafactory = new ChicagoPizzaFactory();
    PizzaStore* pizzaStore = new PizzaStore(pizzafactory);
    Pizza* pizza;
    string type;
    cout << "Enter the type of the pizza" << endl;
    cin >> type;

    pizza = pizzaStore->orderPizza(type);
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