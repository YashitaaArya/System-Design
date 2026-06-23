#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Burger{
    public:
        virtual void prepare() = 0;
        virtual ~Burger(){}
};

class BasicBurger : public Burger{
    public:
        void prepare() override{
            cout<<"Preparing Basic Burger with bun, patty and ketchup."<<endl;
        }
};

class StandardBurger : public Burger{
    public:
        void prepare() override{
            cout<<"Preparing Standard Burger with bun, patty, lettuce, tomato and cheese."<<endl;
        }
};

class PremiumBurger : public Burger{
    public:
        void prepare() override{
            cout<<"Preparing Premium Burger with bun, patty, lettuce, tomato, cheese, bacon and special sauce."<<endl;
        }
};

// class BurgerFactory{
//     public:
//         static Burger* createBurger(string type){
//             if(type == "basic"){
//                 return new BasicBurger();
//             }else if(type == "standard"){
//                 return new StandardBurger();
//             }else if(type == "premium"){
//                 return new PremiumBurger();
//             }else{
//                 return nullptr;
//             }
//         }
// };

// int main(){
//     string type="premium";
//     BurgerFactory* factory = new BurgerFactory();
//     Burger* burger = factory->createBurger(type);
//     burger->prepare();
//     return 0;
// }