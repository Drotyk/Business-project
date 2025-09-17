#ifndef REAL_ESTATE_H
#define REAL_ESTATE_H

#include <string>
#include <iostream>

#include "./address.hpp"

using namespace std;


class RealEstate { //клас нерухомості
public:
    RealEstate(int bud, int floor, double s, bool repair, const adress &X ) : bud(bud), floor(floor), s(s), repair(repair), X(X) {}

    virtual void printInfo() const {
        cout << "Бюджет: " << bud << "$, Поверх: " << floor  << ", Площа: " << s<< ", Ремонт: " << (repair ? "Так" : "Ні") << ", Адреса: " << X.getAdress() << endl;
    }

    int getBudget() const { return bud; }
    double getArea() const { return s; }
    bool hasRepair() const { return repair; }
    string getCity() const { return X.getCity(); }
    string getDistrict() const { return X.getDistrict(); }

    virtual ~RealEstate() {}

protected:
    int bud; // Бюджет
    int floor; // Поверхи
    double s; // Квадратура
    bool repair; // Ремонт
    adress X; // Адрес
};
#endif