#include <iostream>
#include <ctime>
#include <exception>
#include <vector>
#include <string>
using namespace std;

enum class Costs
{
    buyPet,
    buyPhone,
    Casino
};

enum class Works
{
    CallCentre,
    Taxi,
    Casino
};

enum class Animals
{
    cat,
    dog,
    hamster,
    rabbit
};

enum class Colors
{
    red,
    black,
    green,
    white,
    gold,
    silver
};

enum class Gender
{
    male,
    female
};

enum class Models
{
    Samsung,
    Iphone,
    Huawei,
    Nokia
};

class IRevenue
{
protected:
    float wage;
public:
    float virtual Work(short hours) = 0;
};

class Phone
{
private:
    Models model;
    Colors color;
    int ram;
public:
    Phone();

    void setColor(Colors color);

    void setModel(Models model);

    void setRam(int ram);

    string showColor();

    string showModel();

    int showRam();
};

class Pet;

class Shop
{
public:
    void chooseAnimal(Animals species, Gender gender, float& money, Pet& pet);

    Phone choosePhone(Colors color, Models model, float& money, Phone phone);
};

class Pet
{
    friend void Shop::chooseAnimal(Animals species, Gender gender, float& money, Pet& pet);
private:
    string name;
    Gender gender;
    Animals species;

public:

    void setName(string name);

    string showName();

    string showGender();

    string showSpecies();

};

class CallCentre : public IRevenue
{
private:
    float calls;
public:
    CallCentre();

    float Work(short hours) override;
};

class Taxi : public IRevenue
{
private:
    float distance, users;
public:
    Taxi();

    float Work(short hours) override;
};

class Casino
{
private:
    float win;
public:
    Casino();

    float Play(float bet, Colors colour);
};

struct Revenue
{
    Works work;
    float money;

    Revenue(Works work, float money);
};

struct Cost
{
    Costs kind;
    float money;

    Cost(Costs cost, float money);
};

class Account
{
private:
    float money;
    short id;
    static short tmpId;
    vector<Revenue> revenue;
    vector<Cost> cost;

public:
    Account();

    void putMoney(float money);

    void earnMoney(IRevenue& instanceWork, short hours, Works work);

    Pet buyPet(Shop shop, Animals species, Gender gender, Pet& pet);

    Phone buyPhone(Shop shop, Models model, Colors color);

    float currentRevenue(Works work);

    float currentCosts(Costs kind);

    float allRevenue();

    float allCosts();

    void withdraw_Money(float money);

    void tryLuck(Casino& casino, float bet, Colors colour);

    void transferMoney(float money, Account& otherAccount);

    float checkMoney();

    float checkId();

};

short Account::tmpId = 0;


class Budget
{
private:
    int size;
    Account* account;
    float generalMoney;
public:
    Budget(int size);

    float checkGeneralMoney();

    Account& operator[](int index);

};

class Interface
{
public:
    Interface();

    void Menu();

    void depositMoney(Account& account, float money);

    void withdrawMoney(Account& account, float money);

    void showAccountBalance(Account& account);

    void showBalance(Budget budget);

    void showInfo(Account& account);

    void showSpecificRevenue(Account& account, Works work);

    void showSpecificCosts(Account& account, Costs cost);

    void showWorks();

    void earnMoney(Account& account);

    void showCosts();

    Pet buyPet(Account& account);

    void petInfo(Pet& pet);

    void phoneInfo(Phone& phone);

    Phone buyPhone(Account& account);

    void transferMoney(Account& thisAccount, Account& otherAccount, float money);

};