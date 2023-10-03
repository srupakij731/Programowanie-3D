

#include <iostream>
#include <string>






//Program sprawdzaj¹cy czy podana liczba jest parzysta czy nieparzysta
 void task1()
{
     int numberFromUser;
     std::cout << "podaj liczbe";
     std::cin >> numberFromUser;

     if (numberFromUser % 2 == 0)
         std::cout << "liczba jest parzysta";
     else
         std::cout << "liczba jest nieparzysta";
}

 //2. Program sprawdzaj¹cy czy podana liczba jest dodatnia, ujemna czy równa zero
 void task2()
 {
     int numberFromUser;
     std::cout << "podaj liczbe";
     std::cin >> numberFromUser;

     if(numberFromUser > 0)
         std::cout << "liczba dodatnia";
     else if(numberFromUser < 0)
         std::cout << "liczba ujemna";
     else
         std::cout << "liczba wynosi 0";

 }

 //3. Program sprawdzaj¹cy czy podany rok jest rokiem przestêpnym

 void task3()
 {
     int yearFromUser;
     std::cout << "podaj rok";
     std::cin >> yearFromUser;

     if (yearFromUser % 4  == 0 && yearFromUser %100 != 0 || yearFromUser % 400 == 0)
         std::cout << "rok przestêpny";
     else
         std::cout << "rok nie jest przestêpny";


 }

 //4. Program wyœwietlaj¹cy odpowiedni komunikat w zale¿noœci od podanej oceny (np. "bardzo dobry" dla oceny 5, "dobry" dla oceny 4 itd.)
 void task4()
 {
     int gradeFromUser;
     std::cout << "podaj ocene";
     std::cin >> gradeFromUser;

     if (gradeFromUser == 6)
         std::cout << "celuj¹cy";
     else if (gradeFromUser == 5)
         std::cout << "bardzo dobry";
     else if (gradeFromUser == 4)
         std::cout << "dobry";
     else if (gradeFromUser == 3)
         std::cout << "dostateczny";
     else if (gradeFromUser == 2)
         std::cout << "dopuszczaj¹cy";
     else if (gradeFromUser == 1)
         std::cout << "niedostateczny";
     else
         std::cout << "nie ma takiej oceny";

 }

 //5. Program sprawdzaj¹cy czy podane has³o jest poprawne (np. jeœli has³o jest "abc123", program powinien wyœwietliæ "has³o poprawne", jeœli jest inne, powinien wyœwietliæ "has³o niepoprawne").
 void task5()
 {
     std::string passwordSetted, passwordLogin;
     passwordSetted = "abc123";

     std::cout << "podaj has³o (logowanie)";
     std::cin >> passwordLogin;

     if(passwordSetted == passwordLogin )
         std::cout << "zalogowano";
     else
         std::cout << "logowanie nieudane";

 }

 //6. Program sprawdzaj¹cy czy podana data jest poprawna (np. sprawdzaj¹c, czy dzieñ jest z zakresu od 1 do 31, miesi¹c od 1 do 12 itd.)
 bool task6_1(int day, int month, int year)
 {
     if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12 && day <= 31 && day > 0)
         return true;
     else if (month == 4 || month == 6 || month == 9 || month == 11 && day <= 30 && day > 0)
         return true;
     else if (month == 2)
     {

         if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
         {
             if (day > 0 && day <= 28)
                 return true;
         }
         else
             if (day > 0 && day <= 29)
                 return true;
     }
     else
         return false;
 }
 void task6()
 {
     int dayFromUser, monthFromUser, yearFromUser;
     std::cout << "podaj dzieñ ";
     std::cin >> dayFromUser;
     std::cout << "podaj miesi¹c ";
     std::cin >> monthFromUser;
     std::cout << "podaj rok ";
     std::cin >> yearFromUser;

     if (task6_1(dayFromUser, monthFromUser, yearFromUser))
         std::cout << "poprawna data";
     else
         std::cout << "data niepoprawna";
 }

 //7. Program wyœwietlaj¹cy odpowiedni komunikat w zale¿noœci od podanej temperatury (np. "ciep³o" dla temperatury powy¿ej 20 stopni Celsjusza, "ch³odno" dla temperatury poni¿ej 10 stopni Celsjusza itd.)
 void task7()
 {
     int temperatureFromUser;
     std::cout << "podaj temperature";
     std::cin >> temperatureFromUser;
     if(temperatureFromUser > 20)
         std::cout << "ciep³o";
     else if (temperatureFromUser < 10)
         std::cout << "zimno";
     else
         std::cout << "optymalnie";

 }
int main()
{
    setlocale(LC_CTYPE, "polish");
    

    task6();
}

