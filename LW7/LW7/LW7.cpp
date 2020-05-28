#include <iostream>
using namespace std;

class List
{
public:
    List()
    {
        size = 0;
        head = nullptr;
    }

    int getSize()
    {
        return size;
    }
    
    void push_back(double data)
    {
        if (head == nullptr)
        {
            head = new Node(data);
        }
        else
        {
            Node *current = this->head;
            while (current->NextPointer != nullptr)
            {
                current = current->NextPointer;
            }
            current->NextPointer = new Node(data);
        }

        size++;
    }

    void erase(int index)
    {
        if (index == 0)
        {
            Node* tmp = head;
            head = head->NextPointer;
            delete tmp;
            size--;
        }
        else
        {
            Node* previous = this->head;
            for (int i = 0; i < index - 1; i++)
                previous = previous->NextPointer;

            Node* toDelete = previous->NextPointer;
            previous->NextPointer = toDelete->NextPointer;
            delete toDelete;
            size--;
        }
    }

    double& operator[](const int index)
    {
        int counter = 0;
        Node* current = this->head;
        while (current != nullptr)
        {
            if (counter == index)
                return current->data;
            current = current->NextPointer;
            counter++;
        }
    }

private:
    class Node
    {   
    public:
        Node* NextPointer;
        double data;
        Node(double data, Node *NextPointer = nullptr)
        {
            this->data = data;
            this->NextPointer = NextPointer;
        }
    };

    Node* head;
    int size;

};

double searchAvgValue(List list)
{
    double avgValue = 0;
    for (int i = 0; i < list.getSize(); i++)
        avgValue += list[i];

    avgValue /= list.getSize();
    return avgValue;
}

int main()
{
    List list;
    list.push_back(5);
    list.push_back(10);
    list.push_back(15);
    list.push_back(20);

    for (int i = 0; i < list.getSize(); i++)
        cout << list[i] << endl;

    cout << "AvgValue: " << searchAvgValue(list) << endl;
    
    for (int i = 0; i < list.getSize(); i += 2)
        list.erase(i);

    cout << "List after erasing:" << endl;

    for (int i = 0; i < list.getSize(); i++)
        cout << list[i] << " ";
    return 0;
}


