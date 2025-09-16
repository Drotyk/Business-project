#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <ctime>
#include <Windows.h>
#include <map>

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
    string city; // місто
    string district; // район
    string street; // вулиця
    string num; // Номер будинка
};

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

class House : public RealEstate {
public:
    House(int bud, int floor, double s, bool repair, const adress& X, int QualFloor, double TotalArea) : RealEstate(bud, floor, s, repair, X),QualFloor(QualFloor), TotalArea(TotalArea), Dilyanka(true) {}   
      
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

class Room : public RealEstate {
public:
    Room(int bud, int floor, double s, bool repair, const adress& X, bool kitchen, bool bath) : RealEstate(bud, floor, s, repair, X), kitchen(kitchen), bath(bath) {}
       
private:
    bool kitchen; // чи є кухня
    bool bath; // чи є ванна
};

// ==== Генератор випадкових чисел ====
int rnd(int a, int b) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dist(a, b);
    return dist(gen);
}

double rndDouble(double a, double b) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_real_distribution<> dist(a, b);
    return dist(gen);
}

// ==== Генерація даних ====
vector<RealEstate*> generateRealEstate() {
    vector<RealEstate*> objects;

    // Міста України
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
        int districtsCount = rnd(2, min(5, (int)cityDistricts.size())); // беремо кілька районів

        for (int d = 0; d < districtsCount; d++) {
            string district = cityDistricts[d];

            int streetsCount = rnd(2, 10);
            for (int s = 1; s <= streetsCount; s++) {
                string street = "Вулиця" + to_string(s);

                for (int h = 1; h <= 10; h++) {
                    string num = to_string(rnd(1, 100));
                    adress adr(city, district, street, num);

                    int type = rnd(1, 2);
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
                    else {
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

    // ==== Ввід критеріїв ====

    string city, district;
    int minBudget = 0, maxBudget = 0;
    double minArea = 0, maxArea = 0;
    int repairChoice = 2; // 2 = неважливо

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
