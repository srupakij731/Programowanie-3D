#include <iostream>
//kwadrat prostok¹t trapez

class Quadrangle
{
public:
    Quadrangle(double sideA, double sideB, double sideC, double sideD, double height)
    {
        this->sideA = sideA;
        this->sideB == sideB;
        this->sideC == sideC;
        this->sideD == sideD;
        this->height == height;
    }
    double GetPerimeter()
    {
        return sideA + sideB + sideC + sideD;
    }
protected:
    double sideA, sideB, sideC, sideD, height;
};



class Rectangle : public Quadrangle
{
public:
    Rectangle(double sideA, double sideB) : Quadrangle(sideA, sideB, sideA, sideB, sideB)
    {
    }
    double GetArea()
    {
        return sideA * sideB;
    }
};

class Square : public Rectangle
{
public:
    Square(double side) : Rectangle(side, side)
    {

    }

};

class Trapeze : public Quadrangle
{
protected:
    
public:
    Trapeze(double sideA, double sideB, double sideC, double sideD, double height) 
        : Quadrangle(sideA, sideB, sideC, sideD, height)
    {
    }
    double GetArea()
    {
        return ((sideA + sideC) * height)/2;
    }
};
int main()
{
    Quadrangle q(0, 0, 0, 0, 0);
    Square s(2);
    s.GetPerimeter();
    Rectangle r(1,2);
    Trapeze t(1,2,3,4,5);

}