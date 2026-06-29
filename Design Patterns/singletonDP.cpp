#include<iostream>
// #include<mutex>
// #include<thread>

#include<bits/stdc++.h>

using namespace std;

// class Singleton{
//     private:
//         static Singleton* instance;
//         static mutex mtx; // Mutex for thread safety
//         Singleton(){
//             cout << "Singleton Instance Created." << endl;
//         } // Private constructor to prevent instantiation
        
//     public:
//         static Singleton* getInstance(){
//             if(instance == nullptr){
//                 lock_guard<mutex> lock(mtx);
//                 if(instance == nullptr) instance = new Singleton();
//             }
//             return instance;
//         }
// };

// Eager Initialization : Not much practical
// only used when object is not much heavy
class Singleton{
    private:
        static Singleton* instance;
        Singleton(){
            cout << "Singleton Constructor Called!" << endl;
        }
    public:
        static Singleton* getInstance(){
            return instance;
        }
};

// Singleton* Singleton::instance = nullptr;
// mutex Singleton::mtx;

Singleton* Singleton::instance = new Singleton();

int main(){
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();
    cout << (s1==s2) << endl;
    return 0;
}