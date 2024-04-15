#include <iostream>
#include "rent.h"

using namespace std;

bool Rent::registration_nr_is_correct(string registration_number) {
	//sprawdzanie czy rejestracja znajudje sie w pliku z pojazdami
	return 1;
}

void Rent::choose_car_by_registration_number() {
	cout << "type registration number of car you want to rent:";
	string registration_number = "";
	cin >> registration_number;
	while (1) {
		if (registration_nr_is_correct(registration_number)) {
			rent_form(registration_number);
		}
		else {
			cout << "registration number is not correct or the car is not available try again:";
			cin >> registration_number;
		}
	}
}

void Rent::rent_form(string registration_number) {
	cout << "How many days you'd like use the car: ";
	int days = 0;
	cin >> days;
	cout << "are you sure?[y/n] ";
	char ans;
	cin >> ans;
	if (ans == 'y') {
		//dodaæ tu funkcjê zdejmuj¹c¹ samochód ze stanu na okreslony czas
		show_rent_invoice();
	}else if(ans == 'n') {

	}
}

void Rent::show_rent_invoice() {
	cout << "wyswietlenie faktury " << endl;
}