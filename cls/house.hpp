#ifndef REAL_ESTATE_H
#define REAL_ESTATE_H

#include <string>
#include <iostream>

#include "real-estate.hpp"
#include "address.hpp"


class House : public RealEstate {
public:
    House(
        int bud, 
        int floor, 
        double s, 
        bool repair, 
        const adress& X, 
        int QualFloor, 
        double TotalArea,
    ) : RealEstate(
        bud, 
        floor, 
        s, 
        repair, 
        X
    ),
        QualFloor(QualFloor), 
        TotalArea(TotalArea), 
        Dilyanka(true) {

        }   
      
    bool OutSideArea() {   
        if (s == TotalArea) {
           return this->Dilyanka = false;
        }
    }    

    void printInfo() const override {
        RealEstate::printInfo();
        cout << "  [Будинок] Поверхів: " << QualFloor << ", Загальна площа з ділянкою: " << TotalArea << endl;
    }

    private:
    int QualFloor; // Кількість поверхів
    double TotalArea; // Розмір ділянки разом з домом
    bool Dilyanka; // Чи є ділянка в наявності
};

#endif 