
#include <iostream>

class Point
{
private:
	double x, y ,z;
	
public:
	double GetX()
	{
		return x;
	}
	void SetX(double value)
	{
		x = value;
	}

	double GetY()
	{
		return y;
	}
	void SetY(double value)
	{
		y = value;
	}

	double GetZ()
	{
		return z;
	}
	void SetZ(double value)
	{
		z = value;
	}
	double distanceFromCenter()
	{
		double distance = sqrt(x * x + y * y + z * z);
		return distance;
	}
};



int main()
{
	Point myPoint;
	myPoint.SetX(2);
	myPoint.SetY(6);
	myPoint.SetZ(18);
	std::cout << "dystans od środka wynosi " << myPoint.distanceFromCenter();	

}

