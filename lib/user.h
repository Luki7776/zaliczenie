#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>

class User {
	friend class SaleAnnouncement;
protected:
	bool isLoggedIn;
	string loggedUsername;
public:
	bool loginUser(const string _username, const string _password) {
		fstream file;
		file.open("users.txt", ios::in);
		if (!file.is_open()) {
			cerr << "Blad otwarcia pliku!" << endl;
			return "";
		}

		//Funkcja, ktora wyszukuje dany tekst, nastepnie zapisuje to jako oddzielne zmienne i sprawdza, czy dane z pliku
		//sie zgadzaja z danymi ktore podal uzytkownik.
		string line;
		while (getline(file, line)) {
			istringstream iss(line);
			string username, password;
			if (iss >> username >> password) {
				if (username == _username && password == _password) {
					cout << "Zalogowano pomyslnie jako: " << username << endl;
					file.close();
					loggedUsername = username;
					isLoggedIn = true;
					return true;
				}
			}
		}
		file.close();
		cout << "Nieprawid³owy login lub haslo!" << endl;
		isLoggedIn = false;
		return false;
	}

	bool registerUser(string _username, string _password) {

		ofstream file("users.txt", ios::app);
		if (!file.is_open()) {
			cerr << "Blad otwarcia pliku." << endl;
			return 1;
		}
		file << _username << " " << _password << endl;
		file.close();
		cout << "Uzytkownik " << _username << " zostal pomyslnie zarejestrowany." << endl;
	}
	
	bool userExists(const string username, const string fileName) {
		string line;
		fstream file;
		file.open("users.txt", ios::in);
		if (!file.is_open()) {
			cerr << "Blad otwarcia pliku!" << endl;
			return 1;
		}
		//Sprawdzenie, czy dany uzytkownik istnieje
		while (getline(file, line)) {
			istringstream iss(line);
			string storedUsername;
			if (iss >> storedUsername) {
				if (storedUsername == username) {
					file.close();
					return true;
				}
			}
		}
		file.close();
		return false;
	}


	bool getLoggedInState() {
		return isLoggedIn;
	}
	string getLoggedUsername() {
		return loggedUsername;
	}
public:
	User();
};
User::User() : isLoggedIn(false), loggedUsername("") {};
