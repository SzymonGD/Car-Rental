#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include "car_manager_window.h"
#include "car_manager.h"

using namespace std;

void Car_manager_window::remove_car_window() {
	cout << "Type in registration number of the car you want to remove: ";
	string registration_number = "";
	cin >> registration_number;
	Car_manager car_manager;
	int executed_correctly = car_manager.remove_car(registration_number);
	if (executed_correctly) {
		system("CLS");
		cout << "Car with registration number: " << registration_number << " has been removed successfully." << endl << endl;
	}
	else {
		system("CLS");
		cout << "Car with registration number: " << registration_number << " cannot be removed." << endl;
		cout << "You entered wrong registration number or the car does not exist in register." << endl << endl;
	}
}

void Car_manager_window::change_availabillity_state_window() {
	cout << "Type in registration number of which car's availability state you want to change: ";
	string registration_number = "";
	cin >> registration_number;
	Car_manager car_manager;
	car_manager.change_availability_state(registration_number);
	system("CLS");
}

void Car_manager_window::add_car_form() {
	cout << "Type registration number of new car: ";
	string registration_number;
	while (1) {
		cin >> registration_number;
		if (registration_number.length() >= 5 && registration_number.length() <= 8) {
			break;
		}
		else {
			cout << "Wrong registration number, try again: ";
		}
	}
	cout << "Type brand of the car: ";
	string brand;
	cin >> brand;
	cout << "Type model of the car: ";
	string model;
	cin >> model;
	cout << "Type year of production: ";
	string production_year;
	while (1) {
		cin >> production_year;
		if (stoi(production_year) >= 1900 && stoi(production_year) <= 2024) {
			break;
		}
		else {
			cout << "The car couldn't have been produced in this year, try again: ";
		}
	}
	cout << "Type fuel consumption of the car: ";
	string fuel_consumption;
	while (1) {
		cin >> fuel_consumption;
		if (fuel_consumption.find(",") == string::npos) {
			break;
		}
		else {
			cout << "Wrong input, try \'.\' instead of \',\': ";
		}
	}
	cout << "Type power of the car: ";
	string power;
	while (1) {
		cin >> power;
		if (stoi(power) > 0 && stoi(power) < 1500) {
			break;
		}
		else {
			cout << "Wrong input, try again: ";
		}
	}
	cout << "Type the cost of rent per day: ";
	string cost_per_day;
	while (1) {
		cin >> cost_per_day;
		if (stoi(cost_per_day) > 0 && cost_per_day.find(",") == string::npos) {
			break;
		}
		else {
			cout << "Wrong input, try again: ";
		}
	}
	cout << "Type deposit for the car: ";
	string deposit;
	while (1) {
		cin >> deposit;
		if (stoi(deposit) > 0) {
			break;
		}
		else {
			cout << "Wrong input, try again: ";
		}
	}
	Car_manager car_manager;
	int result = car_manager.add_car(registration_number, brand, model, production_year, fuel_consumption, power, cost_per_day, deposit);
	if (result == 1) {
		system("CLS");
		cout << "Car added successfully." << endl;
	}
	else if (result == 0) {
		system("CLS");
		cout << "Car with the same registration number already exists." << endl;
	}
}

void Car_manager_window::show_all_cars() {
	cout << "Registration number, Brand, Model, Production year, Fuel consumption, Power, Cost per day, Deposit, Availability: " << endl << endl;
	fstream car_data(CAR_DATA_PATH);
	string line = "";
	getline(car_data, line);
	while (!car_data.eof()) {
		getline(car_data, line);
		cout << line << endl;
	}
	cout << endl;
	car_data.close();
}

void Car_manager_window::show_available_cars() {
	fstream car_data(CAR_DATA_PATH);
	string line = "";
	getline(car_data, line);
	while (!car_data.eof()) {
		getline(car_data, line);
		if (line.length() > 3) {
			if (line[line.length() - 1] == '1') {
				cout << line << endl;
			}
		}
	}
	cout << endl;
	car_data.close();
}