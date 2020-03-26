#include <iostream>
#include <string>
#include "func.h"
using namespace std;

//class MyClass
//{
//private:
//    string line;
//public:
//    MyClass()
//    {
//        line = "";
//    }
//
//    MyClass(const MyClass& other)
//    {
//        this->line = other.line;
//    }
//
//    MyClass(string line)
//    {
//        this->line = line;
//    }
//
//    string GetLine()
//    {
//        return line;
//    }
//
//    int GetSize()
//    {
//        return line.size();
//    }
//
//    MyClass operator-(const char& symbol)
//    {
//        for (int i = 0; i < line.size(); i++)
//            if (line[i] == symbol)
//                line.erase(i, 1);
//        return line;
//    }
//
//    MyClass operator+(const MyClass& other)
//    {
//        int k = 1;
//        int a = 0, b=0, result;
//        for (int i = this->line.size() - 1;i >= 0; i--)
//        {
//            a += (int(this->line[i]) - 48) * k;
//            k *= 10;
//        }
//
//        k = 1;
//
//        for (int i = other.line.size() - 1; i >= 0; i--)
//        {
//            b += (int(other.line[i]) - 48) * k;
//            k *= 10;
//        }
//
//        result = a + b;
//        return to_string(result);
//    }
//
//};

int main()
{
    MyClass a("126"), b("154");
    MyClass c(a + b);
    b = b - '5';
    cout << "a: " << a.GetLine() << endl;
    cout << "b: " << b.GetLine() << endl;
    cout << "c: " << c.GetLine();
    return 0;
}

