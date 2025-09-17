#ifndef REAL_ESTATE_H
#define REAL_ESTATE_H

#include <string>
#include <iostream>

#include "real-estate.hpp"
#include "address.hpp"
#include "house.hpp"
#include "Apartment.hpp"

class Garage : public RealEstate {
public:
    Garage(int bud, int floor, double s, bool repair, const adress& X, bool pit)
        : RealEstate(bud, floor, s, repair, X), pit(pit) {
    }

    bool hasPit() const { return pit; }

    void printInfo() const override {
        RealEstate::printInfo();
        cout << "  [Гараж] Оглядова яма: " << (pit ? "Так" : "Ні") << endl;
    }

private:
    bool pit;
};
#endif