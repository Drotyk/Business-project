#ifndef REAL_ESTATE_H
#define REAL_ESTATE_H

#include <string>
#include <iostream>

#include "real-estate.hpp"
#include "address.hpp"
#include "house.hpp"



class Apartment : public RealEstate {
public:
    Apartment(int bud, int floor, double s, bool repair, const adress& X, int rooms, bool balcony, int poverh) : RealEstate(bud, floor, s, repair, X), rooms(rooms), balcony(balcony), poverh(poverh){}

    void printInfo() const override {
        RealEstate::printInfo();
        cout << "  [Квартира] Кімнат: " << rooms << ", Балкон: " << (balcony ? "Так" : "Ні") << endl;
    }
       
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
#endif