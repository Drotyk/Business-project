# Business-project
Business project - описується консольна програму для прототипу бізнес проект з продащу квартир 
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Клас опису квартири
class Apartment {
public:
    // --- Властивості ---
    string address;
    int square;             // площа (м²)
    double price;           // ціна ($)
    char floor;             // поверх (символ)
    string repair;          // ремонт
    bool hasBalcony;        // балкон
    double distanceToMetro; // відстань до метро
    char buildingType;      // тип будинку (A - новобудова, B - старий фонд)
    bool hasKindergarten;   // поруч садочок

    // --- Конструктор ---
    Apartment(string addr, int sq, double pr, char fl, string rep, bool balc,
              double dist, char bType, bool kinder)
        : address(addr), square(sq), price(pr), floor(fl), repair(rep),
          hasBalcony(balc), distanceToMetro(dist),
          buildingType(bType), hasKindergarten(kinder) {}

    // --- Метод для виводу інформації ---
    void showInfo() {
        cout << "Адреса: " << address << endl;
        cout << "Площа: " << square << " м²" << endl;
        cout << "Ціна: $" << price << endl;
        cout << "Поверх: " << floor << endl;
        cout << "Ремонт: " << repair << endl;
        cout << "Балкон: " << (hasBalcony ? "Так" : "Ні") << endl;
        cout << "Відстань до метро: " << distanceToMetro << " км" << endl;
        cout << "Тип будинку: " << buildingType << endl;
        cout << "Поруч садочок: " << (hasKindergarten ? "Так" : "Ні") << endl;
        cout << "-----------------------------" << endl;
    }
};

int main() {
    // --- Критерії клієнта ---
    int desiredSquare = 65;
    double desiredPrice = 80000.0;
    char desiredFloor = '5';
    string desiredRepair = "Євроремонт";
    bool wantsBalcony = true;

    cout << "=== Критерії клієнта ===" << endl;
    cout << "Квадратура: " << desiredSquare << " м²" << endl;
    cout << "Бюджет: $" << desiredPrice << endl;
    cout << "Поверх: " << desiredFloor << endl;
    cout << "Ремонт: " << desiredRepair << endl;
    cout << "Балкон: " << (wantsBalcony ? "Так" : "Ні") << endl;
    cout << "=============================" << endl << endl;

    // --- Список квартир ---
    vector<Apartment> apartments = {
        Apartment("вул. Шевченка, 25", 67, 75000, '5', "Євроремонт", true, 0.8, 'A', true),
        Apartment("просп. Свободи, 10", 55, 68000, '3', "Косметичний", false, 1.2, 'B', true),
        Apartment("вул. Франка, 99", 72, 82000, '7', "Євроремонт", true, 0.5, 'A', false)
    };

    cout << "=== Інформація про квартири ===" << endl;
    for (auto &flat : apartments) {
        flat.showInfo();
    }

    return 0;
}
