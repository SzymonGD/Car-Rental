#include <iostream>
#include <fstream>
#include <string>
#include "password_authenticator.h"

using namespace std;

bool Password_authenticator::check_if_password_exists(string check_password) {
	fstream customer_data(CUSTOMER_DATA_PATH);
	string line = "";
	string look_for_passwd = "";
	bool sign_up_flag = 0;
	if (customer_data.is_open()) {
		getline(customer_data, line);
		while (1) {
			if (customer_data.eof()) {
				sign_up_flag = 1;
				break;
			}
			look_for_passwd = "";
			getline(customer_data, line);
			for (char sign : line) {
				if (sign == ',') {
					break;
				}
				look_for_passwd += sign;
			}
			if (check_password == look_for_passwd) {
				customer_data.close();
				return 1;
			}
		}
		if (sign_up_flag) {
			customer_data.close();
			return 0;
		}
	}
}

int Password_authenticator::authenticate(string password) {
	if (password == "admin") {
		return 0;
	}
	else {
		if (check_if_password_exists(password)) {
			return 1;
		}
		else {
			return 2;
		}
	}
}
