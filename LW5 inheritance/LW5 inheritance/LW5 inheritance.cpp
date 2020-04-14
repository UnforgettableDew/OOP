#include <iostream>
#include <exception>
using namespace std;
class Line
{
protected:
    char* string;
public:
    Line() {}

    Line(const char* string)
    {
        this->string = new char[strlen(string) + 1];
        memcpy(this->string, string, strlen(string) + 1);
    }

    const char* getLine()
    {
        if (string == NULL)
            return "There is nothing to get";
        else
            return string;
    }

    int getLength()
    {
        if (string == NULL)
            return 0;
        else
            return strlen(string);
    }
};

class LettersLine : public Line
{
private:
    bool isNumber = false;
public:
    LettersLine(const char* string):Line()
    {
        try
        {
            for (int i = 0; i < strlen(string); i++)
                if (string[i] <= 97 || string[i] >= 122)
                {
                    isNumber = true;
                    throw exception("There are numbers in the line\n");
                }
            this->string = new char[strlen(string) + 1];
            memcpy(this->string, string, strlen(string) + 1);
        }
        catch (const exception & ex)
        {
            cout << ex.what() << endl;
        }
        
    }

    const char* sortLine()
    {   
        if (isNumber == false)
        {
            for (int i = 0; i < strlen(string) - 1; i++)
                for (int j = 0; j < strlen(string) - i - 1; j++)
                {

                    if (string[j] > string[j + 1] && string[j] != ' ')
                    {
                        char tmp;
                        tmp = string[j];
                        string[j] = string[j + 1];
                        string[j + 1] = tmp;
                    }
                }
            return string;
        }
        else
            return "Can't sort the line with number\n";
    }

};

int main()
{
    LettersLine str("fffuiii");

    cout << str.getLine() << endl;
    cout << str.sortLine() << endl;
    cout << str.getLength() << endl;
    
    return 0;
}


