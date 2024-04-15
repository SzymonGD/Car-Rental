#ifndef RENT_H
#define RENT_H

class Rent {
public:
	bool registration_nr_is_correct(string registration_number);
	void choose_car_by_registration_number();
	void rent_form(string registration_number);//po prawid³owym wype³nieniu formularza zmienia w pliku wybrany samochod na niedostepny
	void show_rent_invoice();
};


#endif
