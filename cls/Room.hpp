#ifndef REAL_ESTATE_H
#define REAL_ESTATE_H

#include <string>
#include <iostream>

#include "real-estate.hpp"
#include "address.hpp"
#include "house.hpp"
#include "Apartment.hpp"
#include "Garage.hpp"


class Room : public RealEstate {
public:
    Room(int bud, int floor, double s, bool repair, const adress& X, bool kitchen, bool bath)
        : RealEstate(bud, floor, s, repair, X), kitchen(kitchen), bath(bath) {
    }

    bool hasKitchen() const { return kitchen; }
    bool hasBath() const { return bath; }

    void printInfo() const override {
        RealEstate::printInfo();
        cout << "  [Кімната] Кухня: " << (kitchen ? "Так" : "Ні")
            << ", Ванна: " << (bath ? "Так" : "Ні") << endl;
    }

private:
    bool kitchen;
    bool bath;
};
#endif