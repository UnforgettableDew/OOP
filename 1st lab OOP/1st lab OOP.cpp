#include <iostream>
#include <vector>
using namespace std;

class Line
{
private: 
    vector<char> line;
public:

    Line(char *str)
    {
        for (int i = 0; i < strlen(str); i++)
            line.push_back(str[i]);
        line.push_back('\n'); 
    }

    void Clear()
    {
        while (line.size() != 0)
            line.pop_back();
    }

    unsigned short CountSpace()
    {
        unsigned short count = 0;
        for (int i = 0; i < line.size(); i++)
            if (line[i] == ' ')
                count++;
        return count;
    }

    unsigned short GetSize()
    {
        unsigned short size = 0;
        for (int i = 0; i < line.size(); i++)
            size++;
        return size;
    }

    int GetCount()
    {
        int count = 0;
        for (int i = 0; i < line.size(); i++)
            count++;
        return count - 1;
    }

    int GetNumberCount()
    {
        int count = 0;
        for (int i = 0; i < line.size(); i++)
            if (int(line[i]) - 48 >= 0 && int(line[i]) - 48 <= 9)
                count++;
        return count;
    }

    void Print()
    {
        for (int i = 0; i < line.size(); i++)
            cout << line[i];
    }
};

class Text
{
private:
    vector<Line> text;
public:
    void Init(vector<Line>& text)
    {
        this->text = text;
    }

    void AddLine(Line str)
    {   
        text.push_back(str);
    }

    void Clear()
    {
        for (int i = 0; i < text.size(); i++)
            text[i].Clear();
    }

    void DeleteLine(unsigned short number)
    {
        text[number].Clear();
    }

    void SearchLongLine()
    {
        unsigned short max = text[0].GetSize();
        unsigned short index = 0;

        for (int i = 1; i < text.size(); i++)
        {
            if (text[i].GetSize() > max)
            {
                max = text[i].GetSize();
                index = i;
            }
        }
        cout << "The longest row #" << index + 1 << ": ";
        text[index].Print();

    }

    int GetCount()
    {
        int count = 0;
        for (int i = 0; i < text.size(); i++)
            count += text[i].GetCount() - text[i].CountSpace();
        return count;
    }

    int GetNumberCount()
    {
        int count = 0;
            for (int i = 0; i < text.size(); i++)
                count += text[i].GetNumberCount();
        return count;
    }

    float GetPercent(Text text)
    {
        float percent = (100*text.GetNumberCount())/ float(text.GetCount());
        return percent;
    }

    void Print()
    {
        for (int i = 0; i < text.size(); i++)
            text[i].Print();
    }
};

int main()
{
    char** tmp = new char* [255];
    for (int i = 0; i < 255; i++)
        tmp[i] = new char[255];

    int k = 0;
    vector<Line> str;
    cout << "Enter text: \n";
    Text text;
    while (true)
    {
        cin.getline(tmp[k], 255);
        if (tmp[k][0] == '.')
                break;
        str.push_back(tmp[k]);
        k++;
    }
    text.Init(str);

    for (int i = 0; i < 255; i++)
        delete[] tmp[i];

    cout << "Search count of all characters #1\n";
    cout << "Count of all characters: " << text.GetCount() << endl;

    cout << "\nSearch percent of number #2\n";
    cout << "Percent of numbers: " << text.GetPercent(text) << "%" << endl;

    cout << "\nSearch the longest row #3\n";
    text.SearchLongLine();


    char* ch = new char[255];
    cout << "\nAdding the line #4\n";
    cout << "Enter the row: ";
    cin.getline(ch, 255);
    Line line(ch);
    delete[] ch;
    text.AddLine(line);
    cout << "Text with new row:\n";
    text.Print();

    cout << "\nDelete the line #5\n";
    unsigned short number;
    cout << "\nEnter row's number: ";
    cin >> number;
    text.DeleteLine(number - 1);
    text.Print();

    cout << "\nClear text #6\n";
    text.Clear();
    cout << "The text is cleared\n";
    text.Print();
   
    return 0;
}