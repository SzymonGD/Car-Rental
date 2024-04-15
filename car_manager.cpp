#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "car_manager.h"

using namespace std;

int Car_manager::remove_car(string registration_number) {
	vector<string> line_container;
	bool close_file_flag = 0;
	fstream car_data(CAR_DATA_PATH);
	if (car_data.is_open()) {
		string line = "";
		string registration_number_container = "";
		int i = 1;
		getline(car_data, line);
		while (1) {
			if (close_file_flag == 1)
			{
				car_data.close();
				break;
			}
			if (car_data.eof()) {
				car_data.close();
				break;
			}
			getline(car_data, line);
			i++;
			for (char sign : line) {
				if (sign == ',') {
					if (registration_number_container == registration_number) {
						car_data.clear();
						car_data.seekg(0);
						int ii = 1;
						while (!car_data.eof()) {
							line = "";
							getline(car_data, line);
							if (i != ii) {
								line_container.push_back(line);
							}
							ii++;
						}
						registration_number_container = "";
						close_file_flag = 1;
						break;
					}
					else {
						registration_number_container = "";
						break;
					}
				}
				registration_number_container += sign;
			}
		}
	}
	if (close_file_flag == 1) {
		ofstream car_data_again;
		car_data_again.open(CAR_DATA_PATH, ofstream::out | ofstream::trunc);
		int iii = 0;
		for (int iii = 0; iii < line_container.size(); iii++) {
			car_data_again << line_container[iii] << "\n";
		}
		car_data_again.close();
		return 1;
	}
	else {
		return 0;
	}
}

void Car_manager::change_availability_state(string registration) {
	fstream car_data(CAR_DATA_PATH);
	vector<string> line_container;
	string line;
	int i = 0;
	bool change_flag = 0;
	if (car_data.is_open()) {
		while (!car_data.eof()) {
			getline(car_data, line);
			i++;
			if (line.find(registration) != string::npos) {
				car_data.clear();
				car_data.seekg(0);
				int j = 0;
				while (!car_data.eof()) {
					getline(car_data, line);
					j++;
					if (j == i) {
						if (line[line.size() - 1] == '0') {
							line[line.size() - 1] = '1';
							change_flag = 1;
						}
						else if (line[line.size() - 1] == '1') {
							line[line.size() - 1] = '0';
							change_flag = 1;
						}
					}
					line_container.push_back(line);
				}
				break;
			}
		}
	}
	car_data.close();
	if (change_flag == 1) {
		ofstream car_data_again;
		car_data_again.open(CAR_DATA_PATH, ofstream::out | ofstream::trunc);
		for (int ii = 0; ii < line_container.size(); ii++) {
			car_data_again << line_container[ii] << "\n";
		}
		car_data_again.close();
	}
}

int Car_manager::add_car(string registration_number, string brand, string model, string production_year, string fuel_consumption, string power, string cost_per_day, string deposit) {
	bool car_exists = 0;

	fstream car_data_check(CAR_DATA_PATH);
	if (car_data_check.is_open()) {
		string line = "";
		while (!car_data_check.eof()) {
			getline(car_data_check, line);
			if (line.find(registration_number) != string::npos) {
				car_exists = 1;
			}
		}
	}
	car_data_check.close();
	if (car_exists == 0) {
		ofstream car_data;
		car_data.open(CAR_DATA_PATH, ios::app);
		car_data << registration_number << "," << brand << "," << model << "," << production_year << "," << fuel_consumption << "," << power << "," << cost_per_day << "," << deposit << "," << "1\n";
		car_data.close();
		return 1;
	}
	else {
		return 0;
	}
}