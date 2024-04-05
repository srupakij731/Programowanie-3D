#include <iostream>
//kwadrat prostok¹t trapez

class Quadrangle
{
public:
protected:
    double sideA, sideB, sideC, sideD, height;
};

class Square : public Quadrangle
{
public:
    Square(double sideA)
    {
        this->sideA = height = sideD = sideC = sideB = sideA;
    }
};

class Rectangle : public Quadrangle
{
public:
    Rectangle(double sideA, double sideB)
    {
        this->sideA = sideC = sideA;
        this->sideB = sideD = sideB;
    }
};

class Trapeze : public Quadrangle
{
protected:
    
public:
    Trapeze(double sideA, double sideB, double sideC, double sideD, double height)
    {
        this->sideA = sideA;
        this->sideB ==sideB;
        this->sideC == sideC;
        this->sideD == sideD;
        this->height == height;
    }
};
int main()
{
    Square s(2);
    Rectangle r(1,2);
    Trapeze t(1,2,3,4,5);

}