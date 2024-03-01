
#include <iostream>

class Point
{
private:
	double x, y ,z;
	
public:
	Point(double xx, double yy, double zz)
	{
		SetX(xx);
		SetY(yy);
		SetZ(zz);
	}

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
	Point myPoint(1, 2, 3);
	std::cout << "dystans od środka wynosi " << myPoint.distanceFromCenter();	

}

