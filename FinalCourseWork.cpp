#include <iostream>
#include <ctime>
#include <exception>
#include <vector>
#include <string>
#include"Classes.h";
using namespace std;

int main()
{

    srand(time(NULL));
    int count;
    short point;
    int id;
    int id2;
    float money;
    int cost;
    bool stop = true;
    int w;
    int c;

    cout << "How much accounts would you like to create?: ";
    cin >> count;
    Budget budget(count);
    Pet pet;
    Phone phone;
    Interface iface;
    //iface.Menu();
    typedef void(Interface::* funPointer)();
    funPointer fPointer;
    fPointer = &Interface::Menu;
    (iface.*fPointer)();

    while (stop)
    {
        cin >> point;
        switch (point)
        {
        case 1:
            try
            {
                cout << "On which account would you like to deposit money?: ";
                cin >> id;
                id--;
                cout << "How much money will be deposited?: ";
                cin >> money;
                iface.depositMoney(budget[id], money);
            }
            catch (exception & ex)
            {
                cout << ex.what();
            }
            catch (range_error & ex)
            {
                cout << ex.what();
            }
            break;
        case 2:
            try
            {
                cout << "From which account would you like to withdraw money?: ";
                cin >> id;
                id--;
                cout << "How much money will be withdrawn?: ";
                cin >> money;
                iface.withdrawMoney(budget[id], money);
            }
            catch (exception & ex)
            {
                cout << ex.what();
            }
            catch (range_error & ex)
            {
                cout << ex.what();
            }
            break;
        case 3:
            try
            {
                cout << "On which account would you like to earn money?: ";
                cin >> id;
                id--;
                iface.earnMoney(budget[id]);
            }
            catch (range_error & ex)
            {
                cout << ex.what();
            }
            break;
        case 4:
            try
            {
                cout << "On which account would you like to spend money?: ";
                cin >> id;
                id--;
                cout << "Choose how would you like to spend money?:\n";
                iface.showCosts();

                cin >> cost;
                switch (cost)
                {
                case 1:
                    pet = iface.buyPet(budget[id]);
                    iface.petInfo(pet);
                    break;
                case 2:
                    phone = iface.buyPhone(budget[id]);
                    iface.phoneInfo(phone);
                    break;
                default:
                    break;
                }
            }
            catch (range_error & ex)
            {
                cout << ex.what();
            }
            break;
        case 5:
            try
            {
                cout << "Enter on which account would you like to transfer money: ";
                cin >> id2;
                id2--;
                cout << "Enter from which account would you like to transfer money: ";
                cin >> id;
                id--;
                cout << "Enter how much money do you want to transfer: ";
                cin >> money;
                iface.transferMoney(budget[id], budget[id2], money);
            }
            catch (range_error & ex)
            {
                cout << ex.what();
            }
            break;
        case 6:
            try
            {
                cout << "On which account would you like to check balance?: ";
                cin >> id;
                id--;
                iface.showAccountBalance(budget[id]);
            }
            catch (range_error & ex)
            {
                cout << ex.what();
            }
            break;
        case 7:
            iface.showBalance(budget);
            break;
        case 8:
            try
            {
                cout << "Enter account id: ";
                cin >> id;
                id--;
                cout << "Choose work:\n";
                iface.showWorks();
                cin >> w;
                w--;
                Works work = static_cast<Works>(w);
                iface.showSpecificRevenue(budget[id], work);
            }
            catch (range_error & ex)
            {
                cout << ex.what();
            }
            break;
        case 9:
            try
            {
                cout << "Enter account id: ";
                cin >> id;
                id--;
                cout << "Choose :\n";
                iface.showCosts();
                cin >> c;
                c--;
                Costs cost = static_cast<Costs>(c);
                iface.showSpecificCosts(budget[id], cost);
            }
            catch (range_error & ex)
            {
                cout << ex.what();
            }
            break;
        case 10:
            try
            {
                cout << "Enter account id to get info about it: ";
                cin >> id;
                id--;
                iface.showInfo(budget[id]);
            }
            catch (range_error & ex)
            {
                cout << ex.what();
            }
            break;
        default:
            stop = false;
            break;
        }
    }
    return 0;
}
