
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Клас опису квартири
class Apartment {
public:
    string address;
    int square;             // площа (м²)
    double price;           // ціна ($)
    int floor;              // поверх (число)
    string repair;          // ремонт
    bool hasBalcony;        // балкон
    double distanceToMetro; // відстань до метро
    char buildingType;      // тип будинку (A - новобудова, B - старий фонд)
    bool hasKindergarten;   // поруч садочок

    // Конструктор
    Apartment(string addr, int sq, double pr, int fl, string rep, bool balc,
              double dist, char bType, bool kinder)
        : address(addr), square(sq), price(pr), floor(fl), repair(rep),
          hasBalcony(balc), distanceToMetro(dist),
          buildingType(bType), hasKindergarten(kinder) {}

    // Метод для виводу інформації про квартиру
    void showInfo() const {
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
    // Введення критеріїв клієнта
    int desiredSquare;
    double desiredPrice;
    int desiredFloor;
    string desiredRepair;
    bool wantsBalcony;

    cout << "Введіть бажану площу квартири (м²): ";
    cin >> desiredSquare;
    cout << "Введіть бажану ціну (в $): ";
    cin >> desiredPrice;
    cout << "Введіть бажаний поверх (ціле число): ";
    cin >> desiredFloor;
    cout << "Введіть бажаний тип ремонту (наприклад, Євроремонт або Косметичний): ";
cin.ignore();  // Для коректного зчитування після символів
    getline(cin, desiredRepair);
    cout << "Чи потрібен балкон? (1 - так, 0 - ні): ";
    cin >> wantsBalcony;

    cout << "\n=== Критерії клієнта ===" << endl;
    cout << "Квадратура: " << desiredSquare << " м²" << endl;
    cout << "Бюджет: $" << desiredPrice << endl;
    cout << "Поверх: " << desiredFloor << endl;
    cout << "Ремонт: " << desiredRepair << endl;
    cout << "Балкон: " << (wantsBalcony ? "Так" : "Ні") << endl;
    cout << "=============================" << endl;

    // Список квартир
    vector<Apartment> apartments = {
        Apartment("вул. Шевченка, 25", 67, 75000, 5, "Євроремонт", true, 0.8, 'A', true),
        Apartment("просп. Свободи, 10", 55, 68000, 3, "Косметичний", false, 1.2, 'B', true),
        Apartment("вул. Франка, 99", 72, 82000, 7, "Євроремонт", true, 0.5, 'A', false),
        Apartment("вул. Миколайчука, 12", 60, 70000, 2, "Косметичний", true, 1.0, 'B', true),
        Apartment("вул. Карпенка, 8", 80, 85000, 6, "Євроремонт", false, 0.7, 'A', false)
    };

    // Перевірка та виведення найбільш підходящих квартир
    cout << "\n=== Підходящі квартири ===" << endl;
    bool found = false;
    for (const auto& flat : apartments) {
        // Перевірка за критеріями (спрощене порівняння ремонту)
        if (flat.square >= desiredSquare && flat.price <= desiredPrice &&
            flat.floor == desiredFloor && flat.repair.find(desiredRepair) != string::npos &&
            flat.hasBalcony == wantsBalcony) {
            flat.showInfo();
            found = true;
        }
    }

    if (!found) {
        cout << "Не знайдено жодної квартири, яка відповідає вашим критеріям." << endl;
    }

    return 0;
}