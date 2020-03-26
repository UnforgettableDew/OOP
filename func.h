#include <iostream>
#include <string>
using namespace std;

class MyClass
{
private:
    string line;
public:
    MyClass();

    MyClass(const MyClass& other);

    MyClass(string line);

    string GetLine();

    int GetSize();

    int Converter(const MyClass obj);

    MyClass operator-(const char& symbol);

    friend MyClass operator+(MyClass obj1, MyClass obj2);

}; 
MyClass operator+(MyClass obj1, MyClass obj2);
