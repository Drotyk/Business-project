
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

class adress {
public:
    adress(string city, string district, string street, string num) : city(city), district(district), street(street), num(num) {}

    string getAdress() const {
        return city + ", " + district + ", " + street + " " + num;
    }

private:
    string city; // місто
    string district; // район
    string street; // вулиця
    string num; // Номер будинка
};

class RealEstate { //клас нерухомості
public:
    RealEstate(int bud, int floor, double s, bool repair, const adress &X ) : bud(bud), floor(floor), s(s), repair(repair), X(X) {}

protected:
    int bud; // Бюджет
    int floor; // Поверхи
    double s; // Квадратура
    bool repair; // Ремонт
    adress X; // Адрес
};

class House : public RealEstate {
public:
    House(int bud, int floor, double s, bool repair, const adress& X, int QualFloor, double TotalArea) : RealEstate(bud, floor, s, repair, X),QualFloor(QualFloor), TotalArea(TotalArea), Dilyanka(true) {}   
      
    bool OutSideArea() {   
        if (s == TotalArea) {
           return this->Dilyanka = false;
        }
    }    

private:
    int QualFloor; // Кількість поверхів
    double TotalArea; // Розмір ділянки разом з домом
    bool Dilyanka; // Чи є ділянка в наявності
};

class Apartment : public RealEstate {
public:
    Apartment(int bud, int floor, double s, bool repair, const adress& X, int rooms, bool balcony, int poverh) : RealEstate(bud, floor, s, repair, X), rooms(rooms), balcony(balcony), poverh(poverh){}
       
private:
    int poverh; // на якому поверху знаходиться
    int rooms;   // кількість кімнат
    bool balcony; // чи є балкон
};

class Garage : public RealEstate {
public:
    Garage(int bud, int floor, double s, bool repair, const adress& X, bool pit): RealEstate(bud, floor, s, repair, X), pit(pit) {}
       
private:
    bool pit;  // чи є оглядова яма
};

class Room : public RealEstate {
public:
    Room(int bud, int floor, double s, bool repair, const adress& X, bool kitchen, bool bath) : RealEstate(bud, floor, s, repair, X), kitchen(kitchen), bath(bath) {}
       
private:
    bool kitchen; // чи є кухня
    bool bath; // чи є ванна
};
