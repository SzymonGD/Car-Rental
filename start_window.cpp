#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <vector>
#include "start_window.h"
#include "password_authenticator.h"
#include "customer_manager.h"

using namespace std;

void Start_window::draw_start_window() {
	fstream start_page(START_PAGE_PATH);
	string line = "";
	if (start_page.is_open()) {
		while (1) {
			if (start_page.eof()) {
				break;
			}
			getline(start_page, line);
			cout << line << endl;
		}
		cout << "Loading the programm";
		Sleep(700);
		cout << ". ";
		Sleep(700);
		cout << ". ";
		Sleep(700);
		cout << ". ";
		Sleep(700);
	}
	start_page.close();
	system("CLS");
}

vector<string> Start_window::sign_in() {
	string password;
	cout << "Type in your password (to exit the programm type \"exit\"): ";
	cin >> password;
	system("CLS");
	Password_authenticator password_authenticator;
	while (1) {
		if (password == "exit") {
			vector<string> result;
			return result;
		}
		if (password_authenticator.authenticate(password) == 0) {
			vector<string> result;
			result.push_back("admin");
			return result;
		}
		else if (password_authenticator.authenticate(password) == 1) {
			Customer_manager customer_manager;
			vector<string> result = customer_manager.take_customer_data(password);
			return result;
		}
		else if (password_authenticator.authenticate(password) == 2) {
			cout << "Password is not correct, do you want to sign_up? [y/n] ";
			char ans;
			cin >> ans;
			if (ans == 'y' || ans == 'Y') {
				system("CLS");
				Customer_manager customer_manager;
				cout << "You've been redirected to registration window." << endl;
				cout << "Type in your new password:";
				string new_password;
				cin >> new_password;
				Password_authenticator check_password;
				while (1) {
					if (new_password == "exit" || new_password == "admin" || check_password.check_if_password_exists(new_password)) {
						cout << "Password rejected, type another one: ";
						cin >> new_password;
					}
					else {
						cout << "Password accepted." << endl;
						break;
					}
				}
				cout << "Plaese, pay attention while entering your personal data: " << endl;
				cout << "Type your name: ";
				string name;
				cin >> name;
				cout << "Type your surname: ";
				string surname;
				cin >> surname;
				cout << "Type your ID: ";
				string id;
				while (1) {
					cin >> id;
					if (id.length() >= 0 && id.length() <= 9) {
						break;
					}
					else {
						cout << "Wrong id, try again: ";
					}
				}
				customer_manager.save_in_customer_data(new_password, name, surname, id);
				system("CLS");
				cout << "Your account has been created successfully." << endl;
				cout << "Type in your password: ";
				cin >> password;
			}
			else {
				system("CLS");
				cout << "Try another password: ";
				cin >> password;
			}
		}
	}
}