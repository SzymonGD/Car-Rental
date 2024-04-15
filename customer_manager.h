#ifndef CUSTOMER_MANAGER_H
#define CUSTOMER_MANAGER_H

#include <vector>

#define CUSTOMER_DATA_PATH "C:\\Users\\gdans\\projects\\car-rental-project\\customer_data.txt"

class Customer_manager {
public:
	std::vector<std::string> take_customer_data(std::string password);
	void save_in_customer_data(std::string password_to_save, std::string name_to_save, std::string surname_to_save, std::string id_to_save);
};

#endif