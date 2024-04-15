#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <windows.h>
#include "customer_window.h"
#include "rent.h"
#include "car_manager.h"

using namespace std;

void Customer_window::draw_customer_window() {
	cout << "You are in Customer window." << endl << endl;
	cout << "1. Rent a car." << endl;
	cout << "2. View your rent history." << endl;
	cout << "3. Log out. " << endl << endl;
}

void Customer_window::show_rent_history() {
	fstream rent_history(RENT_HISTORY_PATH);
	string line = "";
	while (!rent_history.eof()) {
		getline(rent_history, line);
		cout << line << endl;
	}
	rent_history.close();
}

void Customer_window::show_customer_history(string id) {
	system("CLS");
	fstream rent_history(RENT_HISTORY_PATH);
	string line = "";
	while (!rent_history.eof()) {
		getline(rent_history, line);
		if (line.find(id) != string::npos) {
			cout << line << endl;
		}
	}
	cout << endl;
	rent_history.close();
}

int Customer_window::customer_window_option() {
	cout << "Type which option you want to choose: ";
	int option = 0;
	cin >> option;
	while (1) {
		if (option == 1){
			system("CLS");//rent a car
			return 1;
		}
		else if (option == 2) {
			//show rent history
			return 2;
		}
		else if (option == 3) {
			system("CLS");
			cout << "Logged out." << endl << endl;
			return 3; //log out
		}
		else{
			cout << "there is not such option, try again:";
			cin >> option;
		}
	}
}

void Customer_window::rent_car_form(vector<string> result) { //password, name, surname, id
	cout << "Type registration number of a car you are interested in: ";
	string registration_number = "";
	cin >> registration_number;
	Rent rent;
	if (rent.check_if_registration_exists(registration_number)) {
		cout << "Type for how many days you want to use the car: ";
		int days = 0;
		cin >> days;
		int sum = rent.calculate_whole_rent(registration_number, days);
		cout << "Whole cost of rent is equal: " << sum << endl;
		cout << "Are you sure about your choice? [y/n]" << endl;
		string choice = "";
		cin >> choice;
		if (choice == "y" || choice == "Y") {
			Car_manager car_manager;
			car_manager.change_availability_state(registration_number);
			rent.save_in_rent_history(registration_number, result[1], days);
			string brand = rent.get_brand_name(registration_number);
			string model = rent.get_model_name(registration_number);
			system("CLS");
			cout << endl << "=========================================================" << endl;
			cout << "                         INVOICE" << endl;
			cout << "Rented car: " << brand << " " << model << " (registration number: " << registration_number << ")." << endl;
			cout << "Period of rent: " << days << " days." << endl;
			cout << "Total amount: " << sum << " (including deposit)." << endl;
			cout << "=========================================================" << endl << endl;
			return;
		}
		else if (choice == "n" || choice == "N") {
			system("CLS");
			cout << "Operation cancelled." << endl << endl;
			return;
		}
	}
	else {
		cout << "There is not such registration number." << endl;
		return;
	}
}