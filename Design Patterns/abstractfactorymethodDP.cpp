#include<iostream>
#include<bits/stdc++.h>
#include"factorymethodDP.cpp"
using namespace std;

class GarlicBread{
    
    public:
        virtual void prepare() = 0;
        virtual ~GarlicBread(){}
};

class BasicGarlicBread : public GarlicBread{
    public:
        void prepare() override{
            cout<<"Preparing Basic Garlic Bread with garlic and butter."<<endl;
        }
};

class StandardGarlicBread : public GarlicBread{
    public:
        void prepare() override{
            cout<<"Preparing Standard Garlic Bread with garlic, butter and cheese."<<endl;
        }
};

class PremiumGarlicBread : public GarlicBread{
    public:
        void prepare() override{
            cout<<"Preparing Premium Garlic Bread with garlic, butter, cheese and herbs."<<endl;
        }
};

class BasicWheatGarlicBread : public GarlicBread{
    public:
        void prepare() override{
            cout<<"Preparing Basic Wheat Garlic Bread with wheat flour, garlic and butter."<<endl;
        }
};

class StandardWheatGarlicBread : public GarlicBread{
    public:
        void prepare() override{
            cout<<"Preparing Standard Wheat Garlic Bread with wheat flour, garlic, butter and cheese."<<endl;
        }
};

class PremiumWheatGarlicBread : public GarlicBread{
    public:
        void prepare() override{
            cout<<"Preparing Premium Wheat Garlic Bread with wheat flour, garlic, butter, cheese and herbs."<<endl;
        }
};

class MealFactory{
    public:
        virtual Burger* createBurger(string type) = 0;
        virtual GarlicBread* createGarlicBread(string type) = 0;
};

class SinghMeal : public MealFactory{
    public:
        Burger* createBurger(string type) override{
            if(type == "basic"){
                return new BasicWheatBurger();
            }else if(type == "standard"){
                return new StandardWheatBurger();
            }else if(type == "premium"){
                return new PremiumWheatBurger();
            }else{
                cout << "Invalid burger type. Please choose from 'basic', 'standard', or 'premium'." << endl;
                return nullptr;
            }
        }
        
        GarlicBread* createGarlicBread(string type) override{
            if(type == "basic"){
                return new BasicWheatGarlicBread();
            }else if(type == "standard"){
                return new StandardWheatGarlicBread();
            }else if(type == "premium"){
                return new PremiumWheatGarlicBread();
            }else{
                cout << "Invalid garlic bread type. Please choose from 'basic', 'standard', or 'premium'." << endl;
                return nullptr;
            }
        }
};

class KingMeal : public MealFactory{
    public:
        Burger* createBurger(string type) override{
            if(type == "basic"){
                return new BasicBurger();
            }else if(type == "standard"){
                return new StandardBurger();
            }else if(type == "premium"){
                return new PremiumBurger();
            }else{
                cout << "Invalid burger type. Please choose from 'basic', 'standard', or 'premium'." << endl;
                return nullptr;
            }
        }
        
        GarlicBread* createGarlicBread(string type) override{
            if(type == "basic"){
                return new BasicGarlicBread();
            }else if(type == "standard"){
                return new StandardGarlicBread();
            }else if(type == "premium"){
                return new PremiumGarlicBread();
            }else{
                cout << "Invalid garlic bread type. Please choose from 'basic', 'standard', or 'premium'." << endl;
                return nullptr;
            }
        }
};

int main(){
    string burgerType = "premium";
    string garlicBreadType = "standard";
    MealFactory* mealFactory = new SinghMeal();
    Burger* burger = mealFactory->createBurger(burgerType);
    GarlicBread* garlicBread = mealFactory->createGarlicBread(garlicBreadType);
    if(burger){
        burger->prepare();
    }
    if(garlicBread){
        garlicBread->prepare();
    }
    
    return 0;
}