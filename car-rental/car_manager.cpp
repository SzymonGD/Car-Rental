#include <iostream>
#include "car_manager.h"
#include "admin_window.h"

using namespace std;

void Car_manager::remove_car(string registration_number) {
	cout << "Usuniecie pojazdu z floty." << endl;
}

void Car_manager::remove_car_window() {
	cout << "program usuwajacy pojazd z floty" << endl;
	show_all_cars();
	cout << "Wpisz numer rejestracyjny samochodu ktory chcesz usunac:" << endl;
	string registration_number;
	cin >> registration_number;
	remove_car(registration_number);
}

void Car_manager::change_availability_state(string registration) {
	cout << "Zmiana stanu w pliku.";
}

void Car_manager::change_availability_state_window() {
	show_all_cars();
	cout << "Wpisz numer rejestracyjny samochodu, ktorego stan chcesz zmienic: ";
	string registration_number;
	change_availability_state(registration_number);
}

void Car_manager::add_car(string name) {
	cout << "Dodanie nowego pojazdu do floty" << endl;
}

void Car_manager::add_car_form() {
	cout << "Wypelnianie pol potrzebnych do wprowadzenia nowego samochodu: " << endl;
	cout << "Wpisz nazwe marki samochodu: ";
	string car_brand;
	cin >> car_brand;
	cout << "Wszystkie pola wprowadzone poprawnie." << endl;
	cout << "Czy decydujesz siê ostatecznie na dodanie nowego samochodu? [y/n]" << endl;
	char ans;
	cin >> ans;
	while (1) {
		if (ans == 'y') {
			add_car(car_brand);
		}
		else if (ans == 'n') {
			cout << "przejscie do okna admina" << endl;
			Admin_window admin_window;
			admin_window.draw_admin_window();
		}
		else {
			cout << "wpisano zla odpowiedz, sprobuj jeszcze raz:" << endl;
			cin >> ans;
		}
	}
}

void Car_manager::show_all_cars() {
	cout << "wyswietlenie wszystkich samochodow z pliku:" << endl;
}