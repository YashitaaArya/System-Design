#include<iostream>
#include "encapsulation.cpp"
using namespace std;

class ManualCar : public Car{
    private:
        int currGear;
    public:
        ManualCar(string b, string m) : Car(b, m) {
            // constructor body (if needed)
            currGear = 0; // default gear
        }
        void shiftGear(int gear){
            if(!isEngineOn){
                cout << brand << " " << model << " : Engine is off! Cannot Shift gear." << endl;
                return;
            }
            currGear=gear;
            cout << brand << " " << model << " : Shifted to gear " << currGear << endl;
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
};
int main(){
    ManualCar* myManualCar = new ManualCar("Honda", "Civic");
    myManualCar->startEngine();
    myManualCar->shiftGear(1);
    myManualCar->accelerate();
    myManualCar->brake();
    myManualCar->stopEngine();
    delete myManualCar;
    cout << "-----------------------------" << endl;
    ElectricCar* myElectricCar = new ElectricCar("Tesla", "Model 3");
    myElectricCar->chargeBattery();
    myElectricCar->startEngine();
    myElectricCar->accelerate();
    myElectricCar->brake();
    myElectricCar->stopEngine();
    delete myElectricCar;

    return 0;
}