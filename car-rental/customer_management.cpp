#include <iostream>
#include "customer_management.h"
#include "start_window.h"

using namespace std;

void Customer_management::add_new_customer() {
	cout << "You've been redirected to registration window." << endl;
	cout << "Type your new password:";
	string password;
	cin >> password;
	cout << "Type your name:";
	string name;
	cin >> name;
	cout << "Type your ID:";
	string id;
	cin >> id;
	//uzupe�ni� o wpisywanie do pliku customer_data.txt,
	//przej�cie z powrotem do logowania
	Start_window start;
	start.sign_in();
}

void Customer_management::show_all_customers() {

}