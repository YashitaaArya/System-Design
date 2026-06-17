#include<iostream>
#include<stdexcept>
using namespace std;

class Shape{
    public:
        virtual double area()=0; // pure virtual function
        virtual double volume()=0; // pure virtual function
};

class Square : public Shape{
    private:
        double side;
    public:
        Square(double s) : side(s){}
        double area() override{
            return side * side;
        }
        double volume() override{
            throw logic_error("Volume not applicable for Square!");
        }
};

class Rectangle : public Shape{
    private:
        double length, width;
    public:
        Rectangle(double l, double w) : length(l), width(w){}
        double area() override{
            return length * width;
        }
        double volume() override{
            throw logic_error("Volume not applicable for Rectangle!");
        }
};

class Cube : public Shape{
    private:
        double side;
    public:
        Cube(double s) : side(s){}
        double area() override{
            return 6 * side * side;
        }
        double volume() override{
            return side * side * side;
        }
};



int main(){
    Shape* square=new Square(5);
    Shape* rectangle=new Rectangle(4, 6);
    Shape* cube=new Cube(3);
    cout << "Square area: " << square->area() << endl;
    cout << "Rectangle area: " << rectangle->area() << endl;
    cout << "Cube area: " << cube->area() << endl;

    try{
        cout << "Square volume: " << square->volume() << endl;
    }catch(const logic_error& e){
        cout << "Exception: " << e.what() << endl;
    } 
    return 0;
}