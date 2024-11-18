﻿using LinqConsoleApp;
void WritePersons(List<Person> people)
{
    foreach (Person p in people)
        Console.WriteLine($"Imię: {p.Name} Nazwisko: {p.Surname} Wiek: {p.Age}");
} 
List<Person> people = new List<Person>();

#region uzupełnienie kolekcji
Person person = new Person();
person.Name = "Ewa";
person.Age = 32;
person.Surname = "Kowalska";
people.Add(person);

person = new Person();
person.Name = "Jan";
person.Age = 12;
person.Surname = "Nowak";
people.Add(person);

person = new Person();
person.Name = "Karol";
person.Age = 52;
person.Surname = "Krawczyk";
people.Add(person);

person = new Person();
person.Name = "Paweł";
person.Age = 35;
person.Surname = "Nowakowski";
people.Add(person);

person = new Person();
person.Name = "Paweł";
person.Age = 5;
person.Surname = "Nowak";
people.Add(person);

person = new Person();
person.Name = "Karol";
person.Age = 23;
person.Surname = "Nowak";
people.Add(person);
#endregion
Console.WriteLine("Zawartoś głownej kolekcji: ");

WritePersons(people);

List<Person> sortedPeopleByAge = people.OrderBy(p => p.Age).ToList();
WritePersons(sortedPeopleByAge);

sortedPeopleByAge = people.OrderByDescending(p => p.Age).ToList();
WritePersons(sortedPeopleByAge);

Console.WriteLine($"Najstarsza osoba ma: {people.Max(p => p.Age)}");
Console.WriteLine($"Najmłodsza osoba ma: {people.Min(p => p.Age)}");
Console.WriteLine($"Średni wiek to: {people.Average(p => p.Age)}");



Console.Clear();

List<Person> sortedPeople = people.OrderBy(p => p.Surname).ThenBy( p=> p.Age).ToList();
WritePersons(sortedPeople);

List<Person> mixedPeople = people.OrderBy(p => new Random().Next()).ToList();

Person firstPerson = people.FirstOrDefault(p => p.Name.Length > 3);
// if(firstPerson != null) // jeżeli Person jest klasą
if(!firstPerson.Equals(default(Person)))
{
    Console.WriteLine($"osoba z imieniem więkrzym niź 3 litery {firstPerson}");
}


int x = 0, y = 2;






(x, y) = (y, x);

 
