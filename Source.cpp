#include <iostream>
#include <string>
#include "func.h"
using namespace std;


    MyClass::MyClass()
    {
        line = "";
    }

    MyClass::MyClass(const MyClass& other)
    {
        this->line = other.line;
    }

    MyClass::MyClass(string line)
    {
        this->line = line;
    }

    string MyClass::GetLine()
    {
        return line;
    }

    int MyClass::GetSize()
    {
        return line.size();
    }

    int MyClass::Converter(const MyClass obj)
    {
        int p = 1;
        int result = 0;
        for (int i = obj.line.size() - 1; i >= 0; i--)
        {
            result += (int(obj.line[i]) - 48) * p;
            p *= 10;
        }
        return result;
    }

    MyClass MyClass::operator-(const char& symbol)
    {
        for (int i = 0; i < line.size(); i++)
            if (line[i] == symbol)
                line.erase(i, 1);
        return line;
    }

    MyClass operator+(MyClass obj1, MyClass obj2)
    {
        MyClass result;
        int sum = obj1.Converter(obj1) + obj2.Converter(obj2);
        result.line = to_string(sum);
        return result;
    }
