#ifndef CAR_MANAGER_WINDOW_H
#define CAR_MANAGER_WINDOW_H

#define CAR_DATA_PATH "C:\\Users\\gdans\\projects\\car-rental-project\\car_data.txt"

class Car_manager_window {
public:
	void show_all_cars();
	void show_available_cars();
	void remove_car_window();
	void change_availabillity_state_window();
	void add_car_form();
};

#endif