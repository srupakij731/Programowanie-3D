#include <iostream>
//kwadrat prostok¹t trapez
/*
* Dla poni¿szych klas u³ó¿ drzewko dziedziczenia.
- Tiger (Tygrys), Dog (Pies), Fish (Ryba), Eagle (Orze³), Mammal (Ssak), Lion (Lew), Sparrow (Wróbel), 
Reptile (Gad), Trout (Pstr¹g), Cat (Kot), Salmon (£osoœ), Animal (Zwierzê), Snake (W¹¿), Bird (Ptak), Turtle (¯ó³w)
- SUV (SUV), Pickup Truck (Pick-up), Truck (Ciê¿arówka), Car (Samochód), Sedan (Sedan), Motorcycle (Motocykl), Vehicle (Pojazd), Semi-Truck (Ci¹gnik siod³owy)
- Smartphone (Smartfon), Android Phone (Telefon z systemem Android), Electronic Device (Urz¹dzenie elektroniczne),
LED TV (Telewizor LED), Laptop (Laptop), iPhone (iPhone), Television (Telewizor), Smart TV (Telewizor Smart)
*/
class Animal
{

};

class Bird : public Animal
{

};
class Fish : public Animal
{

};
class Reptile : public Animal
{

};
class Mammal : public Animal
{

};

class Tiger : public Mammal
{

};
class Dog : public Mammal
{

};
class Lion : public Mammal
{

};
class Cat : public Mammal
{

};

class Trout : public Fish
{

};
class Salmon : public Fish
{

};

class Eagle : public Bird
{

};
class Eagle : public Bird
{

};
class Sparrow : public Bird
{

};

class Snake : public Reptile
{

};
class Turtle : public Reptile
{

};

class Vehicle
{
};



class Car : public Vehicle
{
};
class Motorcycle : public Vehicle
{
};
class Truck : public Vehicle
{
};

class SUV : public Car
{

};
class PickupTruck : public Car
{

};
class Sedan : public Car
{

};

class SemiTruck : public Truck
{

};



class ElectronicDevice{};

class SmartPhone : public ElectronicDevice
{

};
class Television : public ElectronicDevice
{

};
class Laptop : public ElectronicDevice 
{
};

class iPhone : public SmartPhone
{
};
class AndroidPhone : public SmartPhone
{
};

class LEDTV : public Television
{

};
class SmartTV : public Television
{

};
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
		return ((sideA + sideC) * height) / 2;
	}
};
int main()
{
	Quadrangle q(0, 0, 0, 0, 0);
	Square s(2);
	s.GetPerimeter();
	Rectangle r(1, 2);
	Trapeze t(1, 2, 3, 4, 5);

}