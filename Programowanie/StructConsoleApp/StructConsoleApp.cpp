
#include <iostream>

struct point
{
	double x;
	double y;
	double z;
};

double distanceFromCenter(double x, double y, double z)
{
	double distance = sqrt(x * x + y * y + z * z);
	return distance;
}
double distanceFromCenter(point p)
{
	double distance = sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
	return distance;
}

int main()
{
	double x, y, z;
	std::cout << "podaj x\n";
	std::cin >> x;
	std::cout << "podaj y\n";
	std::cin >> y;
	std::cout << "podaj z\n";
	std::cin >> z;

	std::cout << "dystans od œrodka wynosi " << distanceFromCenter(x, y, z);

	point myPoint;
	myPoint.x = 2;
	myPoint.y = 6;
	myPoint.z = 5;
	std::cout << "dystans od œrodka wynosi " << distanceFromCenter(myPoint.x, myPoint.y, myPoint.z);
	std::cout << "dystans od œrodka wynosi " << distanceFromCenter(myPoint);

	point points[10];
	points[7].x = 99;

}

