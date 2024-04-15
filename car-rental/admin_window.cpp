#include <iostream>
#include "admin_window.h"
#include "car_manager.h"

using namespace std;

void Admin_window::draw_admin_window() {
	cout << "You are in admin window." << endl << endl;
	cout << "1. Remove car." << endl;
	cout << "2. Add car." << endl;
	cout << "3. Change availability state of functioning car." << endl;
	int option = 0;
	cin >> option;
	admin_window_option(option);
}

void Admin_window::draw_rent_history() {

}





void Admin_window::admin_window_option(int option) {
	while (1) {
		if (option == 1)
		{
			//remove car
			Car_manager car_manager;
			car_manager.remove_car_window();
		}
		else if (option == 2) {
			//add car
			Car_manager car_manager;
			car_manager.add_car_form();
		}
		else if (option == 3) {
			//change state
			Car_manager car_manager;
			car_manager.change_availability_state_window();
		}
		else {
			cout << "there is not such option, try again:" << endl;
			cin >> option;
		}
	}
}