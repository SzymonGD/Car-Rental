#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include "start_window.h"
#include "password_authorisation.h"

using namespace std;

void Start_window::draw_start_window() {
	fstream start_page("C:\\Users\\gdans\\projects\\car-rental-project\\start_page.txt");
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

void Start_window::sign_in() {
	string password;
	cout << "Type in your password: ";
	Password_authorisation authorisation;
	authorisation.password_authorisation(password);
}