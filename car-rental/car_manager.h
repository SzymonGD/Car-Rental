#ifndef CAR_MANAGER_H
#define CAR_MANAGER_H

class Car_manager {
public:
	void show_all_cars();	
	void remove_car_window();
	void remove_car(string registration_number);
	void change_availability_state(string registration);
	void change_availability_state_window();
	void add_car_form();
	void add_car(string name);	//najpewniej bedzie przyjmowala wiecej pol
};


#endif