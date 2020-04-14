#include <iostream>
#include <cmath>
using namespace std;
class Figure
{
public:
    float virtual getSquare() = 0;

    float virtual getLength() = 0;
};

class Circle : public Figure
{
private:
    float radius;
public:
    Circle(float radius)
    {
        this->radius = radius;
    }

    float getLength() override
    {
        return 2 * 3.14 * radius;
    }

    float getSquare() override
    {
        return 3.14 * pow(radius, 2);
    }
};

class Ellipse : public Figure
{
private:
    float a, b;
public:
    Ellipse(float a, float b)
    {
        this->a = a;
        this->b = b;
    }

    float getLength() override
    {
        return 3.14 * (a + b);
    }

    float getSquare() override
    {
        return 3.14 * a * b;
    }

};

int main()
{
    Circle a(5);
    Ellipse b(3, 5);
    cout << a.getLength() << endl;
    cout << a.getSquare() << endl;
    cout << b.getLength() << endl;
    cout << b.getSquare() << endl;
    return 0;
}


