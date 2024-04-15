#ifndef CAR_MANAGER_H
#define CAR_MANAGER_H

#define CAR_DATA_PATH "C:\\Users\\gdans\\projects\\car-rental-project\\car_data.txt"

class Car_manager {
public:
	int remove_car(std::string registration_number);
	void change_availability_state(std::string registration);
	int add_car(std::string registration_number, std::string brand, std::string model, std::string production_year, std::string fuel_consumption, std::string power, std::string cost_per_day, std::string deposit);
};


#endif