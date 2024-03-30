#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <fstream>
#include "lib/cars.h"
#include "lib/user.h"

using namespace std;



// Klasa która bêdzie skupia³a wszystkie metody do zarz¹dzania og³oszniami.
class SaleAnnouncement : public Car, public User {

public:

	// Z pozyskanych danych tworzy og³oszenie
	void createSaleAnnouncement(string _username) {
		Car cars;
		cars.setBrand();
		cars.setCategory();
		cars.setPrice();
		fstream file;
		file.open("sale_announcements.txt", ios::out | ios::app);

		if (!file.is_open()) {
			cout << "Blad otwarcia pliku!";
			return;
		}

		vector<string> _data;
		_data = cars.getCarDetails();
		if (_username == "") {
			cout << "Blad: Brak nazwy uzytkownika.";
			return;
		}

		file << _username << " ";
		for (string data : _data) {
			file << data << " ";
		}
		file << endl;
		file.close();

		cout << "Ogloszenie utworzone pomyslnie!";
	}

	void searchSaleAnnouncements(string criteria) {
		ifstream file("sale_announcements.txt");
		if (!file.is_open()) {
			cerr << "B³¹d otwarcia pliku." << endl;
			return;
		}

		string line;
		unsigned int currentLine = 0;
		while (getline(file, line)) {
			currentLine++;
			istringstream iss(line);
			string token;
			while (iss >> token) {
				if (token.find(criteria) != string::npos || criteria == "-") {
					cout << line << endl;
					break;
				}
			}
		}

		file.close();
	}

};