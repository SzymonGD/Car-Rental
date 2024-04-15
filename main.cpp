#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <vector>
#include "start_window.h"
#include "admin_window.h"
#include "customer_window.h"
#include "car_manager_window.h"
using namespace std;

Start_window start;

int main() {

	start.draw_start_window();
	while(1){	//sign in loop
		vector<string> result = start.sign_in();
		if(result.size() == 1){
			while (1) {	//admin window loop
				Admin_window admin_window;
				admin_window.draw_admin_window();
				int admin_type = admin_window.admin_window_option();
				if (admin_type == 1) {
					Car_manager_window car_manager_window;
					car_manager_window.show_all_cars();
					car_manager_window.remove_car_window();
				}
				else if (admin_type == 2) {
					Car_manager_window car_manager_window;
					car_manager_window.add_car_form();
				}
				else if (admin_type == 3) {
					Car_manager_window car_manager_window;
					car_manager_window.show_all_cars();
					car_manager_window.change_availabillity_state_window();
				}
				else if (admin_type == 4) {
					Customer_window customer_window;
					customer_window.show_rent_history();
				}
				else if (admin_type == 5) {
					break;
				}
			}
		}else if(result.size() == 4) {
			while (1) {	//customer window loop
				Customer_window customer_window;
				customer_window.draw_customer_window();
				int customer_type = customer_window.customer_window_option();
				if (customer_type == 1) {
					Car_manager_window car_manager_window;
					car_manager_window.show_available_cars();
					customer_window.rent_car_form(result);
				}
				else if (customer_type == 2) {
					Customer_window customer_window;
					customer_window.show_customer_history(result[3]);
				}
				else if (customer_type == 3) {
					break;
				}
			}
		}
		else if (result.size() == 0) {
			break;
		}
	}
}