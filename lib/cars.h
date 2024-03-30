#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

// Abstrakcyjna klasa bazowa dla marki samochodów
class CarBrand {
protected:
    string brand;
public:
    virtual void setBrand() = 0; 
};

class CarCategory {
protected:
    string category;
public:
    virtual void setCategory() = 0; 
};

class CarPrice {
protected:
    double price;
public:
    virtual void setPrice() = 0; 
};

// Klasa reprezentuj¹ca samochód
class Car : public CarBrand, public CarCategory, public CarPrice {
public:
    // Implementacja interfejsu z klasy bazowej CarBrand
    virtual void setBrand() override {
        cout << "Wprowadz marke samochodu: ";
        cin >> brand;
    }

    virtual void setCategory() override {
        cout << "\nWprowadz kategorie samochodu: ";
        cin >> category;
    }

    virtual void setPrice() override {
        cout << "\nWprowadz cene samochodu: ";
        cin >> price;
    }

    // Metoda zwracaj¹ca szczegó³y samochodu
    vector<string> getCarDetails() {
        vector<string> data;
        data.push_back(brand);
        data.push_back(category);
        data.push_back(to_string(price));
        return data;
    }
};
