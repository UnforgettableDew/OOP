#include <iostream>
#include <ctime>
#include <exception>
#include <vector>
#include <string>
#include"Classes.h";
using namespace std;
//
//class Pet;
//
//enum class Costs
//{
//    buyPet,
//    buyPhone,
//    Casino
//};
//
//enum class Works
//{
//    CallCentre,
//    Taxi,
//    Casino
//};
//
//enum class Animals
//{
//    cat,
//    dog,
//    hamster,
//    rabbit
//};
//
//enum class Colors
//{
//    red,
//    black,
//    green,
//    white,
//    gold,
//    silver
//};
//
//enum class Gender
//{
//    male,
//    female
//};
//
//enum class Models
//{
//    Samsung,
//    Iphone,
//    Huawei,
//    Nokia
//};
//
//class IRevenue
//{
//protected:
//    float wage;
//public:
//    float virtual Work(short hours) = 0;
//};
//
////class Phone
////{
////private:
////    Models model;
////    Colors color;
////    int ram;
////public:
////    Phone() {}
////
////    void setColor(Colors color)
////    {
////        this->color = color;
////    }
////
////    void setModel(Models model)
////    {
////        this->model = model;
////    }
////
////    void setRam(int ram)
////    {
////        this->ram = ram;
////    }
////
////    string showColor()
////    {
////        switch (color)
////        {
////        case Colors::red:
////            return "Red";
////            break;
////        case Colors::black:
////            return "Black";
////            break;
////        case Colors::green:
////            return "Green";
////            break;
////        case Colors::white:
////            return "White";
////            break;
////        case Colors::gold:
////            return "Gold";
////            break;
////        case Colors::silver:
////            return "Silver";
////            break;
////        default:
////            break;
////        }
////    }
////
////    string showModel()
////    {
////        switch (model)
////        {
////        case Models::Samsung:
////            return "Samsung";
////            break;
////        case Models::Iphone:
////            return "Iphone";
////            break;
////        case Models::Huawei:
////            return "Huawei";
////            break;
////        case Models::Nokia:
////            return "Nokia";
////            break;
////        default:
////            break;
////        }
////    }
////
////    int showRam()
////    {
////        return ram;
////    }
////};
//
//class Shop
//{
//public:
//    void chooseAnimal(Animals species, Gender gender, float& money, Pet& pet);
//
//    Phone choosePhone(Colors color, Models model, float& money, Phone phone)
//    {
//        switch (model)
//        {
//        case Models::Samsung:
//            phone.setColor(color);
//            phone.setModel(model);
//            phone.setRam(64);
//            money -= 10500;
//            return phone;
//            break;
//        case Models::Iphone:
//            phone.setColor(color);
//            phone.setModel(model);
//            phone.setRam(32);
//            money -= 12500;
//            return phone;
//            break;
//        case Models::Huawei:
//            phone.setColor(color);
//            phone.setModel(model);
//            phone.setRam(32);
//            money -= 10300;
//            return phone;
//            break;
//        case Models::Nokia:
//            phone.setColor(color);
//            phone.setModel(model);
//            phone.setRam(16);
//            money -= 7500;
//            return phone;
//            break;
//        default:
//            break;
//        }
//    }
//};
//
//class Pet
//{
//    friend void Shop::chooseAnimal(Animals species, Gender gender, float& money, Pet& pet);
//private:
//    string name;
//    Gender gender;
//    Animals species;
//
//public:
//
//    void setName(string name)
//    {
//        this->name = name;
//    }
//
//    string showName()
//    {
//        return name;
//    }
//
//    string showGender()
//    {
//        switch (gender)
//        {
//        case Gender::male:
//            return "Male";
//            break;
//        case Gender::female:
//            return "Female";
//            break;
//        default:
//            break;
//        }
//    }
//
//    string showSpecies()
//    {
//        switch (species)
//        {
//        case Animals::cat:
//            return "Cat";
//            break;
//        case Animals::dog:
//            return "Dog";
//            break;
//        case Animals::hamster:
//            return "Hamster";
//            break;
//        case Animals::rabbit:
//            return "Rabbit";
//            break;
//        default:
//            break;
//        }
//    }
//
//};
//
//void Shop::chooseAnimal(Animals species, Gender gender, float& money, Pet& pet)
//{
//    switch (species)
//    {
//    case Animals::cat:
//        pet.gender = gender;
//        pet.species = species;
//        money -= 2500;
//        break;
//    case Animals::dog:
//        pet.gender = gender;
//        pet.species = species;
//        money -= 3000;
//        break;
//    case Animals::hamster:
//        pet.gender = gender;
//        pet.species = species;
//        money -= 1500;
//        break;
//    case Animals::rabbit:
//        pet.gender = gender;
//        pet.species = species;
//        money -= 1300;
//        break;
//    default:
//        break;
//    }
//
//}
//
//class CallCentre : public IRevenue
//{
//private:
//    float calls;
//public:
//    CallCentre()
//    {
//        calls = 0;
//        wage = 0;
//    }
//    float Work(short hours) override
//    {
//        calls = 0;
//        for (int i = 0; i < hours; i++)
//            calls += rand() % 10;
//        if (hours > 480)
//        {
//            wage = hours * 37 + calls * 2.5 + 5000;
//            return wage;
//        }
//        else
//        {
//            wage = hours * 37 + calls * 2.5;
//            return wage;
//        }
//    }
//};
//
//class Taxi : public IRevenue
//{
//private:
//    float distance, users;
//public:
//    Taxi()
//    {
//        distance = 0;
//        users = 0;
//        wage = 0;
//    }
//
//    float Work(short hours) override
//    {
//        wage = 0;
//        for (int i = 0; i < hours; i++)
//        {
//            users = rand() % 5;
//            distance = rand() % 10 + 1;
//            wage += users * distance * 10 - distance * 6;
//        }
//        return wage;
//    }
//};
//
//class Casino
//{
//private:
//    float win;
//public:
//    Casino()
//    {
//        win = 0;
//    }
//
//    float Play(float bet, Colors colour)
//    {
//        int currentValue = rand() % 15;
//        Colors currentColour;
//        if (currentValue != 0 && currentValue % 2 == 0)
//            currentColour = Colors::red;
//        else
//        {
//            if (currentValue % 2 == 1)
//                currentColour = Colors::black;
//            else
//                currentColour = Colors::green;
//        }
//
//        if (currentColour == colour && currentColour == Colors::black)
//            win = bet * 2;
//        else
//        {
//            if (currentColour == colour && currentColour == Colors::red)
//                win = bet * 2;
//            else
//                if (currentColour == colour && currentColour == Colors::green)
//                    win = bet * 14;
//        }
//        return win;
//    }
//};
//
//struct Revenue
//{
//    Works work;
//    float money;
//
//    Revenue(Works work, float money)
//    {
//        this->money = money;
//        this->work = work;
//    }
//};
//
//struct Cost
//{
//    Costs kind;
//    float money;
//    Cost(Costs cost, float money)
//    {
//        this->kind = cost;
//        this->money = money;
//    }
//};
//
//class Account
//{
//private:
//    float money;
//    short id;
//    static short tmpId;
//    vector<Revenue> revenue;
//    vector<Cost> cost;
//
//public:
//    Account()
//    {
//        this->money = 0;
//        tmpId++;
//        id = tmpId;
//    }
//
//    void putMoney(float money)
//    {
//        if (money <= 0)
//            throw exception("You can't put a negative value");
//        this->money += money;
//    }
//
//    void earnMoney(IRevenue& instanceWork, short hours, Works work)
//    {
//        float wage = instanceWork.Work(hours);
//        this->money += wage;
//        Revenue tmpRevenue(work, wage);
//        revenue.push_back(tmpRevenue);
//    }
//
//    Pet buyPet(Shop shop, Animals species, Gender gender, Pet& pet)
//    {
//        float tmpMoney = this->money;
//        shop.chooseAnimal(species, gender, this->money, pet);
//        Cost tmpCost(Costs::buyPet, tmpMoney - this->money);
//        cost.push_back(tmpCost);
//        return pet;
//    }
//
//    Phone buyPhone(Shop shop, Models model, Colors color)
//    {
//        Phone newPhone;
//        float tmpMoney = this->money;
//        newPhone = shop.choosePhone(color, model, this->money, newPhone);
//        Cost tmpCost(Costs::buyPhone, tmpMoney - this->money);
//        cost.push_back(tmpCost);
//        return newPhone;
//    }
//
//    float currentRevenue(Works work)
//    {
//        float income = 0;
//        for (int i = 0; i < revenue.size(); i++)
//            if (work == revenue[i].work)
//                income += revenue[i].money;
//        return income;
//    }
//
//    float currentCosts(Costs kind)
//    {
//        float outlay = 0;
//        for (int i = 0; i < cost.size(); i++)
//            if (kind == cost[i].kind)
//                outlay += cost[i].money;
//        return outlay;
//    }
//
//    float allRevenue()
//    {
//        float income = 0;
//        for (int i = 0; i < revenue.size(); i++)
//            income += revenue[i].money;
//        return income;
//    }
//
//    float allCosts()
//    {
//        float outlay = 0;
//        for (int i = 0; i < cost.size(); i++)
//            outlay += cost[i].money;
//        return outlay;
//    }
//
//    void withdraw_Money(float money)
//    {
//        if (money <= 0)
//            throw new exception("You can't withdraw a negative value");
//        if (this->money < money)
//            throw new exception("Not enough money to withdraw ");
//        this->money -= money;
//    }
//
//    void tryLuck(Casino& casino, float bet, Colors colour)
//    {
//        if (bet <= 0)
//            throw new exception("You can't bet a negative value");
//        this->money -= bet;
//        float win = casino.Play(bet, colour);
//        this->money += win;
//        if (win > 0)
//        {
//            Revenue tmpRevenue(Works::Casino, win);
//            revenue.push_back(tmpRevenue);
//        }
//        else
//        {
//            Cost tmpCost(Costs::Casino, win);
//            cost.push_back(tmpCost);
//        }
//
//    }
//
//    void transferMoney(float money, Account& otherAccount)
//    {
//        if (money <= 0)
//            throw new exception("You can't transfer a negative value");
//        if (this->money < money)
//            throw new exception("Not enough money on this account to transfer ");
//        this->money -= money;
//        otherAccount.money += money;
//    }
//
//    float checkMoney()
//    {
//        return money;
//    }
//
//    float checkId()
//    {
//        return id;
//    }
//
//};
//
//short Account::tmpId = 0;
//
//
//class Budget
//{
//private:
//    int size;
//    Account* account;
//    float generalMoney;
//public:
//    Budget(int size)
//    {
//        generalMoney = 0;
//        this->size = size;
//        account = new Account[size];
//    }
//
//    float checkGeneralMoney()
//    {
//        generalMoney = 0;
//        for (int i = 0; i < size; i++)
//            generalMoney += account[i].checkMoney();
//        return generalMoney;
//    }
//
//    Account& operator[](int index)
//    {
//        if (index < 0)
//            throw range_error("You can't enter negative value");
//        else
//            return account[index];
//    }
//
//};
//
//class Interface
//{
//public:
//    Interface()
//    {
//        cout << "Hello!\n";
//    }
//
//    void Menu()
//    {
//        cout << "========================================\n";
//        cout << "1) Deposit money\n";
//        cout << "2) Withdraw money\n";
//        cout << "3) Earn money\n";
//        cout << "4) Spend money\n";
//        cout << "5) Transfer money\n";
//        cout << "6) Show balance on current account\n";
//        cout << "7) Show all balance\n";
//        cout << "8) Show current revenue on current account\n";
//        cout << "9) Show current costs on current account\n";
//        cout << "10) Show info about account\n";
//        cout << "Press any key to exit\n";
//        cout << "========================================\n";
//    }
//
//    void depositMoney(Account& account, float money)
//    {
//        account.putMoney(money);
//        cout << money << " was deposited on #" << account.checkId() << " account\n";
//    }
//
//    void withdrawMoney(Account& account, float money)
//    {
//        account.withdraw_Money(money);
//        cout << money << " was withdrawn from #" << account.checkId() << " account\n";
//    }
//
//    void showAccountBalance(Account& account)
//    {
//        cout << "Your balance on #" << account.checkId() << " account " << " = " << account.checkMoney() << endl;
//    }
//
//    void showBalance(Budget budget)
//    {
//        cout << "Your general balance = " << budget.checkGeneralMoney() << endl;
//    }
//
//    void showInfo(Account& account)
//    {
//        cout << "===============================\n";
//        cout << "Account #" << account.checkId() << endl;
//        cout << "Balance = " << account.checkMoney() << endl;
//        cout << "All revenues =  " << account.allRevenue() << endl;
//        cout << "All costs = " << account.allCosts() << endl;
//        cout << "===============================\n";
//    }
//
//    void showSpecificRevenue(Account& account, Works work)
//    {
//        if (work == Works::CallCentre)
//            cout << "Your income while working in a call centre = " << account.currentRevenue(work) << endl;
//        else
//            cout << "Your income while working in a taxi = " << account.currentRevenue(work) << endl;
//    }
//
//    void showSpecificCosts(Account& account, Costs cost)
//    {
//        cout << "Account #" << account.checkId() << endl;
//        if (cost == Costs::buyPet)
//            cout << "Your costs while buying pet = " << account.currentCosts(cost) << endl;
//        else
//            cout << "Your costs while buying phone = " << account.currentCosts(cost) << endl;
//    }
//
//    void showWorks()
//    {
//        cout << "1) Call centre\n";
//        cout << "2) Taxi\n";
//    }
//
//    void earnMoney(Account& account)
//    {
//        int w;
//        int hours;
//        CallCentre callCentre;
//        Taxi taxi;
//
//        cout << "Choose your work:\n";
//        showWorks();
//        cin >> w;
//        w--;
//        Works work = static_cast<Works>(w);
//        cout << "How much hours would you like to work?:  ";
//        cin >> hours;
//
//        account.earnMoney(callCentre, hours, work);
//        showSpecificRevenue(account, work);
//    }
//
//    void showCosts()
//    {
//        cout << "1) Buy pet\n";
//        cout << "2) Buy phone\n";
//    }
//
//    Pet buyPet(Account& account)
//    {
//        Shop shop;
//        Pet pet;
//        string name;
//        int s;
//        int g;
//
//        cout << "Choose species of your animal:\n";
//        cout << "1) Cat\n";
//        cout << "2) Dog\n";
//        cout << "3) Hamster\n";
//        cout << "4) Rabbit\n";
//
//        cin >> s;
//        s--;
//        Animals species = static_cast<Animals>(s);
//
//        cout << "Choose gender of your animal:\n";
//        cout << "1) Male\n";
//        cout << "2) Female\n";
//
//        cin >> g;
//        g--;
//        Gender gender = static_cast<Gender>(g);
//
//
//        pet = account.buyPet(shop, species, gender, pet);
//        cout << "Choose name of your animal: ";
//        cin >> name;
//        pet.setName(name);
//        return pet;
//    }
//
//    void petInfo(Pet& pet)
//    {
//        cout << "Name: " << pet.showName() << endl;
//        cout << "Gender: " << pet.showGender() << endl;
//        cout << "Species: " << pet.showSpecies() << endl;
//    }
//
//    void phoneInfo(Phone& phone)
//    {
//        cout << "Model: " << phone.showModel() << endl;
//        cout << "Color: " << phone.showColor() << endl;
//        cout << "Ram: " << phone.showRam() << endl;
//    }
//
//    Phone buyPhone(Account& account)
//    {
//        Shop shop;
//        int c;
//        int m;
//
//        cout << "Choose model of your phone:\n";
//        cout << "1) Samsung\n";
//        cout << "2) Iphone\n";
//        cout << "3) Huawei\n";
//        cout << "4) Nokia\n";
//        cin >> m;
//        m--;
//        Models model = static_cast<Models>(m);
//
//        cout << "Choose color of your phone:\n";
//        cout << "1) Red\n";
//        cout << "2) Black\n";
//        cout << "3) Green\n";
//        cout << "4) White\n";
//        cout << "5) Gold\n";
//        cout << "6) Silver\n";
//
//        cin >> c;
//        c--;
//
//        Colors color = static_cast<Colors>(c);
//        return account.buyPhone(shop, model, color);
//    }
//
//    void transferMoney(Account& thisAccount, Account& otherAccount, float money)
//    {
//        thisAccount.transferMoney(money, otherAccount);
//        cout << "Succesful transaction\n";
//        showAccountBalance(thisAccount);
//        showAccountBalance(otherAccount);
//    }
//
//};

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