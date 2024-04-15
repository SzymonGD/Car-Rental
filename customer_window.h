#ifndef CUSTOMER_WINDOW_H
#define CUSTOMER_WINDOW_H

#define RENT_HISTORY_PATH "C:\\Users\\gdans\\projects\\car-rental-project\\rent_history.txt"

#include <vector>

class Customer_window {
public:
	void draw_customer_window();
	void show_rent_history();
	void show_customer_history(std::string id);
	int customer_window_option();
	void rent_car_form(std::vector<std::string> result);
};


#endif