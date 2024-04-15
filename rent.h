#ifndef RENT_H
#define RENT_H

#define CAR_DATA_PATH "C:\\Users\\gdans\\projects\\car-rental-project\\car_data.txt"
#define CUSTOMER_DATA_PATH "C:\\Users\\gdans\\projects\\car-rental-project\\customer_data.txt"
#define RENT_HISTORY_PATH "C:\\Users\\gdans\\projects\\car-rental-project\\rent_history.txt"

class Rent {
public:
	int calculate_whole_rent(std::string registration_number, int days);
	void save_in_rent_history(std::string registration_number, std::string password, int days);
	bool check_if_registration_exists(std::string registration_number);
	std::string get_brand_name(std::string registration_number);
	std::string get_model_name(std::string registration_number);
};


#endif
