
#include <iostream>

class Point
{
private:
	double x, y, z;

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
	~Point()
	{
		std::cout << "antystruktor";
	}
};


class Rectangle {
private:
	double a, b;
public:
	Rectangle(double aa, double bb)
	{
		a = aa;
		b = bb;
	}

	double Circumference()
	{
		return a + a + b + b;
	}
	double Field()
	{
		return a * b;
	}
	void Info()
	{
		std::cout << " a = " << a << "\n b = " << b << "\n Obwód = " << Circumference() << "\n Pole  = " << Field();
	}

};

class Account
{
private:
	double balance;
	std::string password;
public:
	Account(double money, std::string userPassword)
	{
		balance = floor(money);
		password = userPassword;

	}

	void AddMoney(double money)
	{
		 balance += floor(money);
	}

	void TakeMoney(double money, std::string userPassword)
	{
		money = floor(money);
		if (userPassword == password && money >= balance)
		{
				balance -= money;
		}
	}
	void Info()
	{
		std::cout << balance;
	}

	void Transfer(double money, std::string userPassword, Account target)
	{
		money = floor(money);
		if (userPassword == password && money <= balance)
		{
			balance -= money;
			target.AddMoney(money);
		}
	}
};

int main()
{
	//Point myPoint(1, 2, 3);
	//std::cout << "dystans od środka wynosi " << myPoint.distanceFromCenter();

	//Rectangle a(5, 4);
	//a.Info();

	Account b(10, "b"), c(1, "c");

	b.Transfer(3, "b", c);
	b.Info();
	c.Info();
}

