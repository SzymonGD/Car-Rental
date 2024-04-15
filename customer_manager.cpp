#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "customer_manager.h"
#include "password_authenticator.h"

using namespace std;

void Customer_manager::save_in_customer_data(string password_to_save, string name_to_save, string surname_to_save, string id_to_save) {
	fstream customer_data;
	customer_data.open(CUSTOMER_DATA_PATH, ios::app);
	customer_data << password_to_save <<","<<name_to_save<<","<<surname_to_save<<","<<id_to_save<<"\n";
	customer_data.close();
}

vector<string> Customer_manager::take_customer_data(string password) {
	fstream customer_data(CUSTOMER_DATA_PATH);
	vector<string> result;
	string line = "";
	while (!customer_data.eof()) {
		getline(customer_data, line);
		if (line.find(password) != string::npos) {
			size_t coma1 = line.find(",");
			size_t coma2 = line.find(",", coma1 + 1);
			size_t coma3 = line.find(",", coma2 + 1);
			size_t name_len = coma2 - (coma1 + 1);
			size_t surname_len = coma3 - (coma2 + 1);
			size_t id_len = line.size() - (coma3 + 1);
			string temp = line.substr(0, coma1);
			result.push_back(temp);	//password
			temp = line.substr(coma1 + 1, name_len);
			result.push_back(temp);	//name
			temp = line.substr(coma2 + 1, surname_len);
			result.push_back(temp);	//surname
			temp = line.substr(coma3 + 1, id_len);
			result.push_back(temp);	//id
		}
	}
	customer_data.close();
	return result;
}