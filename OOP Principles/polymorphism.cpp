#include<iostream>
#include <string>
// #include "encapsulation.cpp"
using namespace std;

class Car{
    protected: 
        // characteristics
        string brand, model;
        bool isEngineOn;
        int currSpeed;
        
    public:
        Car(string b, string m){
            this->brand = b;
            this->model=m;
            this->isEngineOn=false;
            this->currSpeed=0;
        }
        // behaviours --> methods
        void startEngine(){
            isEngineOn = true;
            cout << brand << " " << model << " : Engine starts with a roar!" << endl;
        }
        void stopEngine(){
            isEngineOn = false;
            // currGear =0;
            currSpeed=0;
            cout << brand << " " << model << " : Engine turned off." << endl;
        }
        virtual ~Car() {}
        virtual void accelerate()=0;
        virtual void accelerate(int speed)=0;
        virtual void brake()=0;
};

class ManualCar : public Car{
    private:
        int currGear;
    public:
        ManualCar(string b, string m) : Car(b, m) {
            // constructor body (if needed)
            this->currGear = 0; // default gear
        }
        void shiftGear(int gear){
            if(!isEngineOn){
                cout << brand << " " << model << " : Engine is off! Cannot Shift gear." << endl;
                return;
            }
            currGear=gear;
            cout << brand << " " << model << " : Shifted to gear " << currGear << endl;
        }
        // overring accelerate and brake - Dynamin Polymorphism
        void accelerate(){
            if(!isEngineOn){
                cout << brand << " " << model << " : Engine is off! Cannot accelerate." << endl;
                return;
            }
            currSpeed+=20;
            cout << brand << " " << model << " : Accelerating to " << currSpeed << " kmph." << endl;
        }
        // overloading accelerate method - Static Polymorphism
        void accelerate(int speed){
            if(!isEngineOn){
                cout << brand << " " << model << " : Engine is off! Cannot accelerate." << endl;
                return;
            }
            cout << brand << " " << model << " : Accelerating to " << speed << " kmph." << endl;
        }
        void brake(){
            currSpeed-=20;
            if(currSpeed<0) currSpeed=0;
            cout << brand << " " << model << " : Braking! Speed is now " << currSpeed << " kmph." << endl;
        }
};

class ElectricCar : public Car{
    private:
        int batteryLevel;
    public:
        ElectricCar(string b, string m) : Car(b, m) {
            // constructor body (if needed)
            batteryLevel = 100; // default battery level
        }
        void chargeBattery(){
            batteryLevel = 100;
            cout << brand << " " << model << " : Battery fully charged!" << endl;
        }
        // overring accelerate and brake - Dynamin Polymorphism
        void accelerate(){
            if(!isEngineOn){
                cout << brand << " " << model << " : Engine is off! Cannot accelerate." << endl;
                return;
            }
            if(batteryLevel<=0){
                cout << brand << " " << model << " : Battery dead! Cannot accelerate." << endl;
                return;
            }
            batteryLevel-=10;
            currSpeed+=15;
            cout << brand << " " << model << " : Accelerating to " << currSpeed << " kmph." << endl;
        }
        void brake(){
            currSpeed-=15;
            if(currSpeed<0) currSpeed=0;
            cout << brand << " " << model << " : Regenartive Braking! Speed is now " << currSpeed << " kmph." << endl;
        }
};

int main(){
    Car* myManualCar = new ManualCar("Honda", "Civic");
    myManualCar->startEngine();
    myManualCar->accelerate(); 
    myManualCar->accelerate(60);
    myManualCar->brake();
    myManualCar->stopEngine();
    delete myManualCar;
    cout << "-----------------------------" << endl;
    // Car* myElectricCar = new ElectricCar("Tesla", "Model 3");
    // myElectricCar->startEngine();
    // myElectricCar->accelerate();
    // // myElectricCar->accelerate();
    // myElectricCar->brake();
    // myElectricCar->stopEngine();
    // delete myElectricCar;

    return 0;
}