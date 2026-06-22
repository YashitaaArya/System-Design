#include<iostream>
using namespace std;

// Real life Car
class Car{
    public:
        virtual void startEngine() = 0;
        virtual void shiftGear(int gear) = 0;
        virtual void accelerate() = 0;
        virtual void brake() = 0;
        virtual void stopEngine() = 0;
        virtual ~Car() {}
};

class SportsCar : public Car{
    public: 
        string brand, model;
        bool isEngineOn;
        int currSpeed, currGear;

        SportsCar(string b, string m){
            this->brand = b;
            this->model=m;
            isEngineOn=false;
            currSpeed=0, currGear=0;
        }

        void startEngine(){
            isEngineOn = true;
            cout << brand << " " << model << " : Engine starts with a roar!" << endl;
        }

        void shiftGear(int gear){
            if(!isEngineOn){
                cout << brand << " " << model << " : Engine is off! Cannot Shift gear." << endl;
                return;
            }
            currGear=gear;
            cout << brand << " " << model << " : Shifted to gear " << currGear << endl;
        }
        void accelerate(){
            if(!isEngineOn){
                cout << brand << " " << model << " : Engine is off! Cannot accelerate." << endl;
                return;
            }
            currSpeed+=20;
            cout << brand << " " << model << " : Accelerating to " << currSpeed << " kmph." << endl;
        }
        void brake(){
            currSpeed-=20;
            if(currSpeed<0) currSpeed=0;
            cout << brand << " " << model << " : Braking! Speed is now " << currSpeed << " kmph." << endl;
        }
        void stopEngine(){
            isEngineOn = false;
            currGear =0;
            currSpeed=0;
            cout << brand << " " << model << " : Engine turned off." << endl;
        }

};
int main(){
    Car *myCar = new SportsCar("Mercedes", "Benz");
    myCar->startEngine();
    myCar->shiftGear(1);
    myCar->accelerate();
    myCar->shiftGear(2);
    myCar->accelerate();
    myCar->brake();
    myCar->stopEngine();

    delete myCar;
    return 0;
}