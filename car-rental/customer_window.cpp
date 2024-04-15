#include <iostream>
#include "customer_window.h"
#include "car_manager.h"
#include "rent.h"

using namespace std;

void Customer_window::draw_customer_window() {
	cout << "you are in Customer window." << endl;
	cout << "1. Rent a car." << endl;
	cout << "2. View your rent history." << endl;	// pozniej sie moze to zrobi, na razie malo wazne
	int option = 0;
	cin >> option;
	customer_window_option(option);
}

void Customer_window::show_customer_history() {

}

void Customer_window::customer_window_option(int option) {//po wybraniu jednej z opcji wywoluje sie funkcja wyœwietlaj¹ca wszystkie samochody z "car_management"
	while (1) {
		if (option == 1) {
			//wyswietlenie wszystkich samochodow
			//wybranie samochodu przez wpisanie rejestracji
			Car_manager car_manager;
			car_manager.show_all_cars();
			Rent rent;
			rent.choose_car_by_registration_number();
			rent.rent_form();
			rent.show_rent_invoice();
		}
		else if(option == 2){
			cout << "historia klienta" << endl;
		}
		else {
			cout << "there is not such option, try again: " << endl;
			cin >> option;
		}
	}
}