
#include <iostream>

class Point
{
public:
	double x;
	double y;
	double z;

	double GetX()
	{
		return x;
	}
};

double distanceFromCenter(Point p)
{

	double distance = sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
	return distance;
}

int main()
{
	Point myPoint;
	myPoint.x = 2;
	myPoint.y = 6;
	myPoint.z = 5;
	std::cout << "dystans od środka wynosi " << distanceFromCenter(myPoint);
}

