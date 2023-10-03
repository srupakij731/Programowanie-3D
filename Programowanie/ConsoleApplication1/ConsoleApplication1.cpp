#define _USE_MATH_DEFINES
#include <iostream>

//1.Program obliczaj¹cy sredni¹ artmetyczn¹

void task1()
{
	double firstNumberFromUser, secondNumberFromUser;
	std::cout << "Podaj 1 liczbe\n";
	std::cin >> firstNumberFromUser;
	std::cout << "Podaj 2 liczbe\n";
	std::cin >> secondNumberFromUser;

	std::cout << "Œrednia artmetyczna tych 2 liczb wynosi: " << (firstNumberFromUser + secondNumberFromUser) / 2.0;
}
//2. Program obliczaj¹cy pole prostok¹ta.
void task2()
{
	double firstSideFromUser, secondSideFromUser;
	std::cout << "Podaj a\n";
	std::cin >> firstSideFromUser;
	std::cout << "Podaj b\n";
	std::cin >> secondSideFromUser;

	std::cout << "Pole prostok¹ta wynosi " << (firstSideFromUser * secondSideFromUser);
}
//3. Program obliczaj¹cy objêtoœæ sto¿ka.
void task3()
{
	double coneHeightFromUser, coneRadiusFromUser;
	std::cout << "Podaj wysokoœæ\n";
	std::cin >> coneHeightFromUser;
	std::cout << "Podaj promieñ\n";
	std::cin >> coneRadiusFromUser;

	std::cout << "Objêtoœæ sto¿ka wynosi " << (1.0 / 3.0 * M_PI) * pow(coneRadiusFromUser, 2) * coneHeightFromUser;
}
//4. Program obliczaj¹cy pole ko³a.
void task4()
{
	double circleRadiusFromUser;
	std::cout << "Podaj promieñ ko³a\n";
	std::cin >> circleRadiusFromUser;

	std::cout << "Pole ko³a wynosi " << M_PI * pow(circleRadiusFromUser, 2);
}
//5. Program obliczaj¹cy wartoœæ wyra¿enia a ^ 2 + b ^ 2
void task5()
{
	double firstNumberFromUser, secondNumberFromUser;
	std::cout << "Podaj 1 liczbe\n";
	std::cin >> firstNumberFromUser;
	std::cout << "Podaj 2 liczbe\n";
	std::cin >> secondNumberFromUser;

	std::cout << "a^2+b^2 wynosi " << pow(firstNumberFromUser, 2) + pow(secondNumberFromUser, 2);
}
//6. Program obliczaj¹cy pole trójk¹ta o podstawie b i wysokoœci h
void task6()
{
	double triangleBaseFromUser, triangleHeightFromUser;
	std::cout << "Podaj podstawe trójk¹ta\n";
	std::cin >> triangleBaseFromUser;
	std::cout << "Podaj wysokoœæ trójk¹ta\n";
	std::cin >> triangleHeightFromUser;

	std::cout << "Pole trójk¹ta wynosi " << (triangleBaseFromUser * triangleHeightFromUser) / 2.0;
}
//7. Program obliczaj¹cy objêtoœæ kuli o promieniu r
void task7()
{
	double sphereRadiusFromUser;
	std::cout << "Podaj promieñ kuli\n";
	std::cin >> sphereRadiusFromUser;

	std::cout << "Objêtoœæ kuli wynosi " << (4.0 / 3.0 * M_PI) * (pow(sphereRadiusFromUser, 3));
}
//8. Program obliczaj¹cy pole trapezu o podstawach a i b oraz wysokoœci h
void task8()
{
	double firstTrapezeBaseFromUser, secondTrapezeBaseFromUser, trapezeHeightFromUser;
	std::cout << "Podaj 1 podstawe trapezu\n";
	std::cin >> firstTrapezeBaseFromUser;
	std::cout << "Podaj 2 podstawe trapezu\n";
	std::cin >> secondTrapezeBaseFromUser;
	std::cout << "Podaj wysokoœæ trapezu\n";
	std::cin >> trapezeHeightFromUser;


	std::cout << "Pole trapezu wynosi " << ((firstTrapezeBaseFromUser + secondTrapezeBaseFromUser) * trapezeHeightFromUser) / 2;
}
//9. Program obliczaj¹cy œredni¹ wa¿on¹ trzech liczb z podanymi odpowiednimi wagami w1, w2 i w3.
void task9()
{
	double firstNumberFromUser, secondNumberFromUser, thirdNumberFromUser,
		firstNumberWeightFromUser, secondNumberWeightFromUser, thirdNumberWeightFromUser;
	std::cout << "Podaj 1 liczbe\n";
	std::cin >> firstNumberFromUser;
	std::cout << "Podaj wage 1 liczby\n";
	std::cin >> firstNumberWeightFromUser;
	std::cout << "Podaj 2 liczbe\n";
	std::cin >> secondNumberFromUser;
	std::cout << "Podaj wage 2 liczby\n";
	std::cin >> secondNumberWeightFromUser;
	std::cout << "Podaj 3 liczbe\n";
	std::cin >> thirdNumberFromUser;
	std::cout << "Podaj wage 3 liczby\n";
	std::cin >> thirdNumberWeightFromUser;

	double amountOfNumbers = (firstNumberFromUser * firstNumberWeightFromUser) +
		(secondNumberFromUser * secondNumberWeightFromUser) +
		(thirdNumberFromUser * thirdNumberWeightFromUser);
	double amountOfWeight = ((firstNumberWeightFromUser + secondNumberWeightFromUser + thirdNumberWeightFromUser));

	double WeightedAverage = amountOfNumbers / amountOfWeight ;

	std::cout << "Œrednia wa¿ona tych liczb wynosi " << WeightedAverage;
}
int main()
{
	setlocale(LC_CTYPE, "Polish");

	task9();


}


