#include <iostream>
#include <fstream>
#include <string>
#include "password_authenticator.h"
#include "admin_window.h"
#include "customer_window.h"
#include "customer_management.h"

using namespace std;

void Password_authenticator::password_authenticator(string password) {
	if (password == "admin") {
		Admin_window admin_window;
		admin_window.draw_admin_window();
	}
	else {
		fstream customer_data("C:\\Users\\gdans\\projects\\car-rental-project\\customer_data.txt");
		string line = "";
		string look_for_passwd = "";
		bool sign_up_flag = 0;
		if (customer_data.is_open()) {
			getline(customer_data, line);	//pominiêcie pierwszej linii z customer_data.txt
			while (1) {
				if (customer_data.eof()) {
					sign_up_flag = 1;
					break;
				}
				getline(customer_data, line);
				for (char sign : line) {
					if (sign == ',') {
						break;
					}
					look_for_passwd += sign;
				}
				if (password == look_for_passwd) {
					Customer_window customer; //pewnie trzeba bedzie zrobiæ konstruktor przyjmuj¹cy has³o
					customer.draw_customer_window();
					break;
				}
			}
			if (sign_up_flag) {
				Customer_management customer_management;
				customer_management.add_new_customer();
			}
		}
	}
}