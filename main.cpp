#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <ctime>
#include <Windows.h>
#include <map>

#include "./cls/address.hpp"
#include "./cls/real-estate.hpp"
#include "./cls/Apartment.hpp"
#include "./cls/Garage.hpp"
#include "./cls/house.hpp"
#include "./cls/Room.hpp"
#include "./rnd-utils.hpp"

using namespace std;

// ==== Генерація даних ====
vector<RealEstate*> generateRealEstate() {
    vector<RealEstate*> objects;

    vector<string> cities = {
        "Вінниця", "Луцьк", "Дніпро", "Донецьк", "Житомир", "Ужгород",
        "Запоріжжя", "Івано-Франківськ", "Кропивницький", "Луганськ",
        "Львів", "Миколаїв", "Одеса", "Полтава", "Рівне", "Суми",
        "Тернопіль", "Харків", "Херсон", "Хмельницький", "Черкаси",
        "Чернівці", "Чернігів", "Київ"
    };

    map<string, vector<string>> districts = {
        {"Вінниця", {"Замостянський", "Вишенька", "Слов'янка"}},
        {"Луцьк", {"Гнідавський", "Старе місто", "Центральний"}},
        {"Дніпро", {"Чечелівський", "Інгулецький", "Шевченківський"}},
        {"Донецьк", {"Калінінський", "Київський", "Кіровський"}},
        {"Житомир", {"Центральний", "Першотравневий", "Корольовський"}},
        {"Ужгород", {"Центральний", "Підзамок", "Боздош"}},
        {"Запоріжжя", {"Вознесенівський", "Комунарський", "Хортицький"}},
        {"Івано-Франківськ", {"Франківський", "Садовий", "Бам"}},
        {"Кропивницький", {"Ковалівський", "Центральний", "Подільський"}},
        {"Луганськ", {"Жовтневий", "Ленінський", "Ворошиловський"}},
        {"Львів", {"Галицький", "Франківський", "Сихівський"}},
        {"Миколаїв", {"Центральний", "Інгульський", "Лівобережний"}},
        {"Одеса", {"Приморський", "Суворовський", "Малиновський"}},
        {"Полтава", {"Подільський", "Шевченківський", "Київський"}},
        {"Рівне", {"Центральний", "Малий", "Ювілейний"}},
        {"Суми", {"Ковпаківський", "Охтирський", "Зарічний"}},
        {"Тернопіль", {"Центральний", "Східний", "Західний"}},
        {"Харків", {"Основ'янський", "Шевченківський", "Комінтернівський"}},
        {"Херсон", {"Корабельний", "Дніпровський", "Суворовський"}},
        {"Хмельницький", {"Центральний", "Північний", "Озерний"}},
        {"Черкаси", {"Соснівський", "Придніпровський", "Митниця"}},
        {"Чернівці", {"Першотравневий", "Шевченківський", "Садгірський"}},
        {"Чернігів", {"Новозаводський", "Деснянський", "Міський"}},
        {"Київ", {"Печерський", "Шевченківський", "Подільський", "Дніпровський"}}
    };

    for (const auto& city : cities) {
        const auto& cityDistricts = districts[city];
        int districtsCount = rnd(2, min(5, (int)cityDistricts.size()));

        for (int d = 0; d < districtsCount; d++) {
            string district = cityDistricts[d];

            int streetsCount = rnd(2, 5);
            for (int s = 1; s <= streetsCount; s++) {
                string street = "Вулиця" + to_string(s);

                for (int h = 1; h <= 40; h++) {
                    string num = to_string(rnd(1, 100));
                    adress adr(city, district, street, num);

                    int type = rnd(1, 4);
                    if (type == 1) {
                        objects.push_back(new House(
                            rnd(50000, 500000),
                            rnd(1, 3),
                            rndDouble(60, 200),
                            rnd(0, 1),
                            adr,
                            rnd(1, 3),
                            rndDouble(100, 500)
                        ));
                    }
                    else if (type == 2) {
                        objects.push_back(new Apartment(
                            rnd(30000, 200000),
                            rnd(1, 20),
                            rndDouble(30, 120),
                            rnd(0, 1),
                            adr,
                            rnd(1, 5),
                            rnd(0, 1),
                            rnd(1, 20)
                        ));
                    }
                    else if (type == 3) {
                        objects.push_back(new Garage(
                            rnd(5000, 20000),
                            1,
                            rndDouble(15, 40),
                            rnd(0, 1),
                            adr,
                            rnd(0, 1)
                        ));
                    }
                    else {
                        objects.push_back(new Room(
                            rnd(10000, 50000),
                            rnd(1, 10),
                            rndDouble(10, 30),
                            rnd(0, 1),
                            adr,
                            rnd(0, 1),
                            rnd(0, 1)
                        ));
                    }
                }
            }
        }
    }
    return objects;
}

int main()
{
    setlocale(LC_ALL, "RU");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    auto estates = generateRealEstate();
    cout << "У базі " << estates.size() << " об'єктів нерухомості.\n\n";

    int typeChoice;
    cout << "Оберіть тип нерухомості:\n";
    cout << "1 - Будинок\n2 - Квартира\n3 - Гараж\n4 - Кімната\n5 - Будь-який\nВаш вибір: ";
    cin >> typeChoice;

    int roomsChoice = -1;
    int balconyChoice = 2;
    int pitChoice = 2;
    int kitchenChoice = 2;
    int bathChoice = 2;

    if (typeChoice == 2) {
        cout << "Кількість кімнат (0 - байдуже): ";
        cin >> roomsChoice;
        cout << "Балкон? (1 - так, 0 - ні, 2 - байдуже): ";
        cin >> balconyChoice;
    }
    else if (typeChoice == 3) {
        cout << "Оглядова яма? (1 - так, 0 - ні, 2 - байдуже): ";
        cin >> pitChoice;
    }
    else if (typeChoice == 4) {
        cout << "Кухня? (1 - так, 0 - ні, 2 - байдуже): ";
        cin >> kitchenChoice;
        cout << "Ванна? (1 - так, 0 - ні, 2 - байдуже): ";
        cin >> bathChoice;
    }

    string city, district;
    int minBudget = 0, maxBudget = 0;
    double minArea = 0, maxArea = 0;
    int repairChoice = 2;

    cout << "Введіть місто (натисніть 0 якщо байдуже): ";
    cin >> city;

    if (city == "0") {
        district = "0";
    }
    else {
        cout << "Введіть район (натисніть 0 якщо байдуже): ";
        cin >> district;
    }
    cout << "Мінімальний бюджет (натисніть 0 якщо байдуже): ";
    cin >> minBudget;
    cout << "Максимальний бюджет (натисніть 0 якщо байдуже): ";
    cin >> maxBudget;
    cout << "Мінімальна площа (натисніть 0 якщо байдуже): ";
    cin >> minArea;
    cout << "Максимальна площа (натисніть 0 якщо байдуже): ";
    cin >> maxArea;
    cout << "Ремонт? (1 - так, 0 - ні, 2 - неважливо): ";
    cin >> repairChoice;

    cout << "\n===== Результати пошуку =====\n";

    int count = 0;
    for (auto e : estates) {
        if (city != "0" && e->getCity() != city) continue;
        if (district != "0" && e->getDistrict() != district) continue;
        if (minBudget > 0 && e->getBudget() < minBudget) continue;
        if (maxBudget > 0 && e->getBudget() > maxBudget) continue;
        if (minArea > 0 && e->getArea() < minArea) continue;
        if (maxArea > 0 && e->getArea() > maxArea) continue;
        if (repairChoice != 2 && e->hasRepair() != (repairChoice == 1)) continue;

        if (typeChoice == 1 && dynamic_cast<House*>(e) == nullptr) continue;
        if (typeChoice == 2 && dynamic_cast<Apartment*>(e) == nullptr) continue;
        if (typeChoice == 3 && dynamic_cast<Garage*>(e) == nullptr) continue;
        if (typeChoice == 4 && dynamic_cast<Room*>(e) == nullptr) continue;

        if (auto* a = dynamic_cast<Apartment*>(e)) {
            if (roomsChoice > 0 && a->getRooms() != roomsChoice) continue;
            if (balconyChoice != 2 && a->hasBalcony() != (balconyChoice == 1)) continue;
        }
        if (auto* g = dynamic_cast<Garage*>(e)) {
            if (pitChoice != 2 && g->hasPit() != (pitChoice == 1)) continue;
        }
        if (auto* r = dynamic_cast<Room*>(e)) {
            if (kitchenChoice != 2 && r->hasKitchen() != (kitchenChoice == 1)) continue;
            if (bathChoice != 2 && r->hasBath() != (bathChoice == 1)) continue;
        }

        e->printInfo();
        cout << "---------------------------------\n";
        count++;
    }

    if (count == 0) {
        cout << "Нічого не знайдено за заданими критеріями.\n";
    }

    for (auto e : estates) delete e;
    return 0;
}
