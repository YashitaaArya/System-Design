#include<iostream>
#include<bits/stdc++.h>
#include"simplefactory.cpp"
using namespace std;

class BasicWheatBurger : public Burger{
    public:
        void prepare() override{
            cout<<"Preparing Basic Wheat Burger with wheat bun, patty and ketchup."<<endl;
        }
};

class StandardWheatBurger : public Burger{
    public:
        void prepare() override{
            cout<<"Preparing Standard Wheat Burger with wheat bun, patty, lettuce, tomato and cheese."<<endl;
        }
};

class PremiumWheatBurger : public Burger{
    public:
        void prepare() override{
            cout<<"Preparing Premium Wheat Burger with wheat bun, patty, lettuce, tomato, cheese, bacon and special sauce."<<endl;
        }
};

class BurgerFactory{
    public:
        virtual Burger* createBurger(string type) = 0;
};

class BurgerKing : public BurgerFactory{
    public:
        Burger* createBurger(string type) override{
            if(type == "basic"){
                return new BasicBurger();
            }else if(type == "standard"){
                return new StandardBurger();
            }else if(type == "premium"){
                return new PremiumBurger();
            }else{
                return nullptr;
            }
        }
};

class BurgerSingh : public BurgerFactory{
    public:
        Burger* createBurger(string type) override{
            if(type == "basic"){
                return new BasicWheatBurger();
            }else if(type == "standard"){
                return new StandardWheatBurger();
            }else if(type == "premium"){
                return new PremiumWheatBurger();
            }else{
                return nullptr;
            }
        }
};

// int main(){
//     string type="basic";
//     BurgerFactory* factory = new BurgerSingh();
//     Burger* burger = factory->createBurger(type);
//     burger->prepare();
//     return 0;
// }