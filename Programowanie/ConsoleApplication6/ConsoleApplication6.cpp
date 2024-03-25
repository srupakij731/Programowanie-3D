
#include <iostream>
class C
{
protected:
    int fieldA;
    std::string name;
public:
    C()
    {
        fieldA = 0;
        name = "C";
    }

    C(int a, std::string x)
    {
        fieldA = a;
        name = x;
    }

    int getA()
    {
        return fieldA;
    }

    void ShowInfo()
    {
        std::cout << "info dla klasy" << name;
        std::cout << fieldA;

    }
};
class A : public C
{
public:
    A(int field): C(1, "a")
    {
        name = "A";
    }

    A(int a, std::string x)
    {
        fieldA = a;
        name = x;
    }

};
class B : public C
{
private:
    int fieldB;

public:
    B(int field)
    {
        fieldB = field;
    }

    int getB()
    {
        return fieldB;
    }


};
int main()
{
    std::cout << "Hello World!\n";
}