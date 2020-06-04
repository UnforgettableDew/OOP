#include <iostream>
#include <ctime>
#include <exception>
#include <vector>
#include <string>
#include "Classes.h"


Phone::Phone() {}

void Phone::setColor(Colors color)
{
    this->color = color;
}

void Phone::setModel(Models model)
{
    this->model = model;
}

void Phone::setRam(int ram)
{
    this->ram = ram;
}

string Phone::showColor()
{
    switch (color)
    {
    case Colors::red:
        return "Red";
        break;
    case Colors::black:
        return "Black";
        break;
    case Colors::green:
        return "Green";
        break;
    case Colors::white:
        return "White";
        break;
    case Colors::gold:
        return "Gold";
        break;
    case Colors::silver:
        return "Silver";
        break;
    default:
        break;
    }
}

string Phone::showModel()
{
    switch (model)
    {
    case Models::Samsung:
        return "Samsung";
        break;
    case Models::Iphone:
        return "Iphone";
        break;
    case Models::Huawei:
        return "Huawei";
        break;
    case Models::Nokia:
        return "Nokia";
        break;
    default:
        break;
    }
}

int Phone::showRam()
{
    return ram;
}

Phone Shop::choosePhone(Colors color, Models model, float& money, Phone phone)
{
    switch (model)
    {
    case Models::Samsung:
        phone.setColor(color);
        phone.setModel(model);
        phone.setRam(64);
        money -= 10500;
        return phone;
        break;
    case Models::Iphone:
        phone.setColor(color);
        phone.setModel(model);
        phone.setRam(32);
        money -= 12500;
        return phone;
        break;
    case Models::Huawei:
        phone.setColor(color);
        phone.setModel(model);
        phone.setRam(32);
        money -= 10300;
        return phone;
        break;
    case Models::Nokia:
        phone.setColor(color);
        phone.setModel(model);
        phone.setRam(16);
        money -= 7500;
        return phone;
        break;
    default:
        break;
    }
}

void Pet::setName(string name)
{
    this->name = name;
}

string Pet::showName()
{
    return name;
}

string Pet::showGender()
{
    switch (gender)
    {
    case Gender::male:
        return "Male";
        break;
    case Gender::female:
        return "Female";
        break;
    default:
        break;
    }
}

string Pet::showSpecies()
{
    switch (species)
    {
    case Animals::cat:
        return "Cat";
        break;
    case Animals::dog:
        return "Dog";
        break;
    case Animals::hamster:
        return "Hamster";
        break;
    case Animals::rabbit:
        return "Rabbit";
        break;
    default:
        break;
    }
}

void Shop::chooseAnimal(Animals species, Gender gender, float& money, Pet& pet)
{
    switch (species)
    {
    case Animals::cat:
        pet.gender = gender;
        pet.species = species;
        money -= 2500;
        break;
    case Animals::dog:
        pet.gender = gender;
        pet.species = species;
        money -= 3000;
        break;
    case Animals::hamster:
        pet.gender = gender;
        pet.species = species;
        money -= 1500;
        break;
    case Animals::rabbit:
        pet.gender = gender;
        pet.species = species;
        money -= 1300;
        break;
    default:
        break;
    }
}

CallCentre::CallCentre()
{
    calls = 0;
    wage = 0;
}

float CallCentre::Work(short hours) override
{
    calls = 0;
    for (int i = 0; i < hours; i++)
        calls += rand() % 10;
    if (hours > 480)
    {
        wage = hours * 37 + calls * 2.5 + 5000;
        return wage;
    }
    else
    {
        wage = hours * 37 + calls * 2.5;
        return wage;
    }
}

Taxi::Taxi()
{
    distance = 0;
    users = 0;
    wage = 0;
}

float Taxi::Work(short hours) override
{
    wage = 0;
    for (int i = 0; i < hours; i++)
    {
        users = rand() % 5;
        distance = rand() % 10 + 1;
        wage += users * distance * 10 - distance * 6;
    }
    return wage;
}

Casino::Casino()
{
    win = 0;
}

float Casino::Play(float bet, Colors colour)
{
    int currentValue = rand() % 15;
    Colors currentColour;
    if (currentValue != 0 && currentValue % 2 == 0)
        currentColour = Colors::red;
    else
    {
        if (currentValue % 2 == 1)
            currentColour = Colors::black;
        else
            currentColour = Colors::green;
    }

    if (currentColour == colour && currentColour == Colors::black)
        win = bet * 2;
    else
    {
        if (currentColour == colour && currentColour == Colors::red)
            win = bet * 2;
        else
            if (currentColour == colour && currentColour == Colors::green)
                win = bet * 14;
    }
    return win;
}

Revenue::Revenue(Works work, float money)
{
    this->money = money;
    this->work = work;
}

Cost::Cost(Costs cost, float money)
{
    this->kind = cost;
    this->money = money;
}

Account::Account()
{
    this->money = 0;
    tmpId++;
    id = tmpId;
}

void Account::putMoney(float money)
{
    if (money <= 0)
        throw exception("You can't put a negative value");
    this->money += money;
}

void Account::earnMoney(IRevenue& instanceWork, short hours, Works work)
{
    float wage = instanceWork.Work(hours);
    this->money += wage;
    Revenue tmpRevenue(work, wage);
    revenue.push_back(tmpRevenue);
}

Pet Account::buyPet(Shop shop, Animals species, Gender gender, Pet& pet)
{
    float tmpMoney = this->money;
    shop.chooseAnimal(species, gender, this->money, pet);
    Cost tmpCost(Costs::buyPet, tmpMoney - this->money);
    cost.push_back(tmpCost);
    return pet;
}

Phone Account::buyPhone(Shop shop, Models model, Colors color)
{
    Phone newPhone;
    float tmpMoney = this->money;
    newPhone = shop.choosePhone(color, model, this->money, newPhone);
    Cost tmpCost(Costs::buyPhone, tmpMoney - this->money);
    cost.push_back(tmpCost);
    return newPhone;
}

float Account::currentRevenue(Works work)
{
    float income = 0;
    for (int i = 0; i < revenue.size(); i++)
        if (work == revenue[i].work)
            income += revenue[i].money;
    return income;
}

float Account::currentCosts(Costs kind)
{
    float outlay = 0;
    for (int i = 0; i < cost.size(); i++)
        if (kind == cost[i].kind)
            outlay += cost[i].money;
    return outlay;
}

float Account::allRevenue()
{
    float income = 0;
    for (int i = 0; i < revenue.size(); i++)
        income += revenue[i].money;
    return income;
}

float Account::allCosts()
{
    float outlay = 0;
    for (int i = 0; i < cost.size(); i++)
        outlay += cost[i].money;
    return outlay;
}

void Account::withdraw_Money(float money)
{
    if (money <= 0)
        throw new exception("You can't withdraw a negative value");
    if (this->money < money)
        throw new exception("Not enough money to withdraw ");
    this->money -= money;
}

void Account::tryLuck(Casino& casino, float bet, Colors colour)
{
    if (bet <= 0)
        throw new exception("You can't bet a negative value");
    this->money -= bet;
    float win = casino.Play(bet, colour);
    this->money += win;
    if (win > 0)
    {
        Revenue tmpRevenue(Works::Casino, win);
        revenue.push_back(tmpRevenue);
    }
    else
    {
        Cost tmpCost(Costs::Casino, win);
        cost.push_back(tmpCost);
    }

}

void Account::transferMoney(float money, Account& otherAccount)
{
    if (money <= 0)
        throw new exception("You can't transfer a negative value");
    if (this->money < money)
        throw new exception("Not enough money on this account to transfer ");
    this->money -= money;
    otherAccount.money += money;
}

float Account::checkMoney()
{
    return money;
}

float Account::checkId()
{
    return id;
}

Budget::Budget(int size)
{
    generalMoney = 0;
    this->size = size;
    account = new Account[size];
}

float Budget::checkGeneralMoney()
{
    generalMoney = 0;
    for (int i = 0; i < size; i++)
        generalMoney += account[i].checkMoney();
    return generalMoney;
}

Account& Budget::operator[](int index)
{
    if (index < 0)
        throw range_error("You can't enter negative value");
    else
        return account[index];
}

Interface::Interface()
{
    std::cout << "Hello!\n";
}

void Interface::Menu()
{
    std::cout << "========================================\n";
    std::cout << "1) Deposit money\n";
    std::cout << "2) Withdraw money\n";
    std::cout << "3) Earn money\n";
    std::cout << "4) Spend money\n";
    std::cout << "5) Transfer money\n";
    std::cout << "6) Show balance on current account\n";
    std::cout << "7) Show all balance\n";
    std::cout << "8) Show current revenue on current account\n";
    std::cout << "9) Show current costs on current account\n";
    std::cout << "10) Show info about account\n";
    std::cout << "Press any key to exit\n";
    std::cout << "========================================\n";
}

void Interface::depositMoney(Account& account, float money)
{
    account.putMoney(money);
    std::cout << money << " was deposited on #" << account.checkId() << " account\n";
}

void Interface::withdrawMoney(Account& account, float money)
{
    account.withdraw_Money(money);
    std::cout << money << " was withdrawn from #" << account.checkId() << " account\n";
}

void Interface::showAccountBalance(Account& account)
{
    std::cout << "Your balance on #" << account.checkId() << " account " << " = " << account.checkMoney() << endl;
}

void Interface::showBalance(Budget budget)
{
    std::cout << "Your general balance = " << budget.checkGeneralMoney() << endl;
}

void Interface::showInfo(Account& account)
{
    std::cout << "===============================\n";
    std::cout << "Account #" << account.checkId() << endl;
    std::cout << "Balance = " << account.checkMoney() << endl;
    std::cout << "All revenues =  " << account.allRevenue() << endl;
    std::cout << "All costs = " << account.allCosts() << endl;
    std::cout << "===============================\n";
}

void Interface::showSpecificRevenue(Account& account, Works work)
{
    if (work == Works::CallCentre)
        std::cout << "Your income while working in a call centre = " << account.currentRevenue(work) << endl;
    else
        std::cout << "Your income while working in a taxi = " << account.currentRevenue(work) << endl;
}

void Interface::showSpecificCosts(Account& account, Costs cost)
{
    std::cout << "Account #" << account.checkId() << endl;
    if (cost == Costs::buyPet)
        std::cout << "Your costs while buying pet = " << account.currentCosts(cost) << endl;
    else
        std::cout << "Your costs while buying phone = " << account.currentCosts(cost) << endl;
}

void Interface::showWorks()
{
    std::cout << "1) Call centre\n";
    std::cout << "2) Taxi\n";
}

void Interface::earnMoney(Account& account)
{
    int w;
    int hours;
    CallCentre callCentre;
    Taxi taxi;

    std::cout << "Choose your work:\n";
    showWorks();
    std::cin >> w;
    w--;
    Works work = static_cast<Works>(w);
    std::cout << "How much hours would you like to work?:  ";
    std::cin >> hours;

    account.earnMoney(callCentre, hours, work);
    showSpecificRevenue(account, work);
}

void Interface::showCosts()
{
    std::cout << "1) Buy pet\n";
    std::cout << "2) Buy phone\n";
}

Pet Interface::buyPet(Account& account)
{
    Shop shop;
    Pet pet;
    string name;
    int s;
    int g;

    std::cout << "Choose species of your animal:\n";
    std::cout << "1) Cat\n";
    std::cout << "2) Dog\n";
    std::cout << "3) Hamster\n";
    std::cout << "4) Rabbit\n";

    std::cin >> s;
    s--;
    Animals species = static_cast<Animals>(s);

    std::cout << "Choose gender of your animal:\n";
    std::cout << "1) Male\n";
    std::cout << "2) Female\n";

    std::cin >> g;
    g--;
    Gender gender = static_cast<Gender>(g);


    pet = account.buyPet(shop, species, gender, pet);
    std::cout << "Choose name of your animal: ";
    std::cin >> name;
    pet.setName(name);
    return pet;
}

void Interface::petInfo(Pet& pet)
{
    std::cout << "Name: " << pet.showName() << endl;
    std::cout << "Gender: " << pet.showGender() << endl;
    std::cout << "Species: " << pet.showSpecies() << endl;
}

void Interface::phoneInfo(Phone& phone)
{
    std::cout << "Model: " << phone.showModel() << endl;
    std::cout << "Color: " << phone.showColor() << endl;
    std::cout << "Ram: " << phone.showRam() << endl;
}

Phone Interface::buyPhone(Account& account)
{
    Shop shop;
    int c;
    int m;

    std::cout << "Choose model of your phone:\n";
    std::cout << "1) Samsung\n";
    std::cout << "2) Iphone\n";
    std::cout << "3) Huawei\n";
    std::cout << "4) Nokia\n";
    std::cin >> m;
    m--;
    Models model = static_cast<Models>(m);

    std::cout << "Choose color of your phone:\n";
    std::cout << "1) Red\n";
    std::cout << "2) Black\n";
    std::cout << "3) Green\n";
    std::cout << "4) White\n";
    std::cout << "5) Gold\n";
    std::cout << "6) Silver\n";

    std::cin >> c;
    c--;

    Colors color = static_cast<Colors>(c);
    return account.buyPhone(shop, model, color);
}

void Interface::transferMoney(Account& thisAccount, Account& otherAccount, float money)
{
    thisAccount.transferMoney(money, otherAccount);
    std::cout << "Succesful transaction\n";
    showAccountBalance(thisAccount);
    showAccountBalance(otherAccount);
}