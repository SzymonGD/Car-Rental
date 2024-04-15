#include <iostream>
#include "admin_window.h"

using namespace std;

void Admin_window::draw_admin_window() {
	cout << "You are in admin window." << endl << endl;
	cout << "1. Remove car." << endl;
	cout << "2. Add car." << endl;
	cout << "3. Change availability state of functioning car." << endl;
	cout << "4. Show rent history." << endl;
	cout << "5. Log out." << endl << endl;
}

int Admin_window::admin_window_option() {
	cout << "Type which option you want to choose: ";
	int option = 0;
	cin >> option;
	while (1) {
		if (option == 1)
		{
			system("CLS");
			return 1;	//remove car
		}
		else if (option == 2) {
			return 2;	//add car
		}
		else if (option == 3) {
			system("CLS");
			return 3;	//change state
		}
		else if (option == 4) {
			return 4;//show rent history
		}
		else if (option == 5) {
			system("CLS");
			cout << "Logged out." << endl << endl;
			return 5;//log out
		}
		else{
			cout << "there is not such option, try again:";
			cin >> option;
		}
	}
}