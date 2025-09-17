#ifndef ADRESS_H
#define ADRESS_H
#include <string>

using namespace std;

class adress {
public:
    adress(string city, string district, string street, string num) : city(city), district(district), street(street), num(num) {}

    string getAdress() const {
        return city + ", " + district + ", " + street + " " + num;
    }

    string getCity() const { return city; }
    string getDistrict() const { return district; }

private:
    string city;
    string district;
    string street;
    string num;
};
#endif