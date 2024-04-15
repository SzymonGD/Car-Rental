#include <iostream>
#include <fstream>
#include <string>
#include "rent.h"

using namespace std;

int Rent::calculate_whole_rent(string registration_number, int days) {
	fstream car_data(CAR_DATA_PATH);
	string line = "";
	string found_line = "";
	int coma_count = 0;
	size_t start_position = 0;
	size_t middle_position = 0;
	size_t end_position = 0;
	while (!car_data.eof()) {
		getline(car_data, line);
		if (line.find(registration_number) != string::npos) {
			found_line = line;
			for (size_t i = 0; i < line.length(); ++i) {
				if (line[i] == ',') {
					coma_count++;
					if (coma_count == 6) {
						start_position = i;
					}
					else if (coma_count == 7) {
						middle_position = i;
					}
					else if (coma_count == 8) {
						end_position = i;
						break;
					}
				}
			}
		}
	}
	string cost_per_day = found_line.substr(start_position+1, (middle_position - start_position - 1));
	string deposit = found_line.substr(middle_position+1, (end_position - middle_position - 1));
	car_data.close();
	return (stoi(cost_per_day)*days + stoi(deposit));
}

void Rent::save_in_rent_history(string registration_number, string password, int days) {
	fstream car_data(CAR_DATA_PATH);
	string line = "";
	string brand = "";
	string model = "";
	if (car_data.is_open()) {
		while (!car_data.eof()) {
			getline(car_data, line);
			if (line.find(registration_number) != string::npos) {
				int coma_count = 0;
				size_t first_position = 0;
				size_t second_position = 0;
				size_t third_position = 0;
				for (size_t i = 0; i < line.length(); ++i) {
					if (line[i] == ',') {
						coma_count++;
						if (coma_count == 1) {
							first_position = i;
						}
						else if (coma_count == 2) {
							second_position = i;
						}
						else if(coma_count == 3){
							third_position = i;
							break;
						}
					}
				}
				brand = line.substr(first_position + 1, (second_position - first_position-1));
				model = line.substr(second_position + 1, (third_position - second_position-1));
			}
		}
	}
	car_data.close();

	fstream customer_data(CUSTOMER_DATA_PATH);
	line = "";
	string name = "";
	string surname = "";
	string id = "";
	if (customer_data.is_open()) {
		while (!customer_data.eof()) {
			getline(customer_data, line);
			if (line.find(password) != string::npos) {
				int coma_count = 0;
				size_t first_position = 0;
				size_t second_position = 0;
				size_t third_position = 0;
				for (size_t i = 0; i < line.length(); ++i) {
					if (line[i] == ',') {
						coma_count++;
						if (coma_count == 1) {
							first_position = i;
						}
						else if (coma_count == 2) {
							second_position = i;
						}
						else if (coma_count == 3) {
							third_position = i;
						}
					}
				}
				name = line.substr(first_position+1, (second_position - first_position-1));
				surname = line.substr(second_position+1, (third_position - second_position-1));
				id = line.substr(third_position+1, (string::npos - third_position));
			}
		}
	}
	customer_data.close();

	ofstream rent_history;
	rent_history.open(RENT_HISTORY_PATH, ios::app);
	if (rent_history.is_open()) {
		rent_history << name << " " << surname << " id: " << id << " ,has rented: " << brand << " " << model << " " << registration_number << " for " << days << " days.\n";
	}
	rent_history.close();
}

bool Rent::check_if_registration_exists(string registration_number) {
	fstream car_data(CAR_DATA_PATH);
	string line = "";
	while (!car_data.eof()) {
		getline(car_data, line);
		if (line.find(registration_number) != string::npos) {
			car_data.close();
			return true;
		}
	}
	car_data.close();
	return false;
}

string Rent::get_brand_name(string registration_number) {
	fstream car_data(CAR_DATA_PATH);
	string line = "";
	while (!car_data.eof()) {
		getline(car_data, line);
		if (line.find(registration_number) != string::npos) {
			size_t first_comma = 0;
			size_t second_comma = 0;
			int comma_count = 0;
			for (size_t i = 0; i < line.length(); ++i) {
				if (line[i] == ',') {
					comma_count++;
					if (comma_count == 1) {
						first_comma = i;
					}
					else if (comma_count == 2) {
						second_comma = i;
					}
				}
			}
			car_data.close();
			return line.substr(first_comma + 1, (second_comma - first_comma - 1));
		}
	}
	car_data.close();
}

string Rent::get_model_name(string registration_number) {
	fstream car_data(CAR_DATA_PATH);
	string line = "";
	while (!car_data.eof()) {
		getline(car_data, line);
		if (line.find(registration_number) != string::npos) {
			size_t second_comma = 0;
			size_t third_comma = 0;
			int comma_count = 0;
			for (size_t i = 0; i < line.length(); ++i) {
				if (line[i] == ',') {
					comma_count++;
					if (comma_count == 2) {
						second_comma = i;
					}
					else if (comma_count == 3) {
						third_comma = i;
					}
				}
			}
			car_data.close();
			return line.substr(second_comma + 1, (third_comma - second_comma - 1));
		}
	}
	car_data.close();
}