#include<iostream>
using namespace std;

class Car{
    protected: 
        // characteristics
        string brand, model;
        bool isEngineOn;
        int currSpeed;

    private:
        int currGear;
        string tyre;
        
    public:
        Car(string b, string m){
            this->brand = b;
            this->model=m;
            isEngineOn=false;
            currSpeed=0, currGear=0;
            tyre="MRF";
        }
        // getters and setters
        int getspeed(){
            return this->currSpeed;
        }
        string gettyre(){
            return this->tyre;
        }
        void settyre(string tyre){
            // validations
            this->tyre=tyre;
        }
        // behaviours --> methods
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
// int main(){
//     Car* myCar = new Car("Mercedes", "Benz");
//     myCar->startEngine();
//     myCar->shiftGear(1);
//     myCar->accelerate();
//     myCar->shiftGear(2);
//     myCar->accelerate();
//     myCar->brake();
//     myCar->stopEngine();

//     delete(myCar);
//     return 0;
// }