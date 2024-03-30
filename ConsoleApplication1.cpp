#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include "lib/sale_announcements.h"

using namespace std;


int main()
{
	SaleAnnouncement saleAnnouncements;
	User user;
	int selection;
	while(!user.getLoggedInState()) {
		string login, password;
		cout << "Prosze sie zalogowac, badz zarejestrowac." << endl;
		cout << "1. Logowanie" << endl;
		cout << "2. Rejestracja" << endl;
		cin>>selection;
		switch (selection) {
		case 1:
			cout << "Podaj login." << endl;
			cin >> login;
			cout << "\nPodaj haslo." << endl;
			cin>> password;
			if (!user.loginUser(login, password)) {
				cout << "Niepoprawne dane. Koncze program.";
				return 0;
			};
			cout << "Zalogowano pomyslnie!" << endl;
			break;
		case 2:
			cout << "Podaj nazwe uzytkownika" << endl;
			cin >> login;
			cout << "Podaj haslo" << endl;
			cin >> password;
			if (user.userExists(login, password)) {
				cout << "Uzytkownik " << login << " juz istnieje." << endl;
				return 1;
			}
			else {
				user.registerUser(login, password);
				
			}
			break;
		}
	}
	cout << "Witaj w programie! Wybierz akcje:" << endl;
	while (true) {

		cout << "1. Tworzenie ogloszenia." << endl;
		cout << "2. Szukanie ogloszenia." << endl;
		cout << "3. Konczenie programu." << endl;

		cin >> selection;
		cout << endl;
		switch (selection) 
		{
		case 1:
		{
			saleAnnouncements.createSaleAnnouncement(user.getLoggedUsername());
			break;
		}
		case 2:
		{
			string criteria;
			cout << "Podaj jedno kryterium po jakim szukac samochod (np. SUV)." << endl;
			cout << "Wstaw - jesli chcesz wyszukac wszystkie ogloszenia." << endl;
			cin >> criteria;
			saleAnnouncements.searchSaleAnnouncements(criteria);
			break;
		}
		case 3:
		{
			cout << "Konczenie programu.";
			return 0;
		}
		default:
		{
			cout << "Wybrales zla liczbe!";
		
		}
		}
		cout << endl << "Przenosze w menu wyboru..." << endl;
	}
	return 0;
}
