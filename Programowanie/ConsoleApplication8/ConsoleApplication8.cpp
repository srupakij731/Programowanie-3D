#include <iostream>

//zad 1

class Count
{
private:
	double number;
public:
	void Add(double number)
	{
		this->number += number;
	}
	void Subtract(double number)
	{
		this->number -= number;
	}
	Count()
	{
		number = 0;
	}
	Count(double number)
	{
		this->number = number;
	}
};

//zad2

class Adder
{
private:
	static const int SIZE_OF_ARRAY = 10;
	int numbers[SIZE_OF_ARRAY];
public:
	Adder()
	{
		for (int i = 0; i < SIZE_OF_ARRAY; i++)
		{
			numbers[i] = 0;
		}
	}
	Adder(int number)
	{
		srand(NULL);
		for (int i = 0; i < SIZE_OF_ARRAY; i++)
		{
			numbers[i] = rand() % number + 1;
		}
	}
	int Amount()
	{
		int sum = 0;
		for (int i = 0; i < SIZE_OF_ARRAY; i++)
		{
			sum += numbers[i];
		}
		return sum;
	}
	int AmountDevideBy3()
	{
		int sum = 0;
		for (int i = 0; i < SIZE_OF_ARRAY; i++)
		{
			if (sum % 3 == 0)
				sum += numbers[i];
		}
		return sum;
	}
	void ShowNumbers()
	{
		for (int i = 0; i < SIZE_OF_ARRAY; i++)
		{
			std::cout << numbers[i] << "\n";
		}
	}
	void ShowNumbers(int lowIndex, int highIndex)
	{
		std::cout << "\n";
		for (int i = lowIndex; i <= highIndex; i++)
		{
			std::cout << numbers[i] << "\n";
		}
	}
};


//zad 3

class Person
{
private:
	std::string name;
	std::string lastName;
	int age;
public:
	Person(std::string name, std::string lastName, int age)
	{
		this->name = name;
		this->lastName = lastName;
		this->age = age;
	}
	Person()
	{

	}
	void Show()
	{
		std::cout << name << "\n" << lastName << "\n" << age << "\n \n";
	}

};

class Book
{
private:
	std::string title, date;
	Person author;
public:
	Book(std::string title, Person author, std::string date)
	{
		this->title = title;
		this->author = author;
		this->date = date;
	}
	void Show()
	{
		std::cout << title << "\n" << date << "\n";
		author.Show();
	}
};

// zad 4
class Date
{

};
int main()
{

	//Count c1;
	//c1.Add(1);
	//c1.Subtract(2);
	//Count c2(10);
	//c2.Add(1);
	//c2.Subtract(2);

	//Adder a1;
	//std::cout << a1.Amount() << "\n";
	//std::cout << a1.AmountDevideBy3() << "\n";
	//a1.ShowNumbers();
	//std::cout << "\n";

	//Adder a2(20);
	//a2.Amount();
	//a2.AmountDevideBy3();
	//a2.ShowNumbers();

	Person KarolBakalarz("Karol", "Bakalarz", 15);
	KarolBakalarz.Show();

	Book b("Emil Rak i kamieñ nerkowy", KarolBakalarz, "11/09/2001");
	b.Show();




}
