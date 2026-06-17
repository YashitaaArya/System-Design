#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class TwoDShape{
    public:
        virtual double area()=0; // pure virtual function
};

class ThreeDShape{
    public:
        virtual double volume()=0; // pure virtual function
        virtual double area()=0; // pure virtual function
};

class Square : public TwoDShape{
    private:
        double side;
    public:
        Square(double s) : side(s){}
        double area() override{
            return side * side;
        }
};

class Rectangle : public TwoDShape{
    private:
        double length, width;
    public:
        Rectangle(double l, double w) : length(l), width(w){}
        double area() override{
            return length * width;
        }
};

class Cube : public ThreeDShape{
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
    TwoDShape* square=new Square(5);
    TwoDShape* rectangle=new Rectangle(4, 6);
    ThreeDShape* cube=new Cube(3);
    cout << "Square area: " << square->area() << endl;
    cout << "Rectangle area: " << rectangle->area() << endl;    
    cout << "Cube area: " << cube->area() << endl;
    cout << "Cube volume: " << cube->volume() << endl;
    
    return 0;
}