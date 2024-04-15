#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include "start_window.h"
using namespace std;

/*
					WYPOZYCZALNIA SAMOCHODOW:
-> w systemie istnieja uzytkownikcy admin i customer			x
	Zakres odpowiedzialnosci admina:
		- sprawdza historie najmów								x
		- dodaje / usuwa pojazdy z floty						x
		- wy³¹cza funkcjonujace pojazdy z uzytku do odwolania	x

	Zakres odpowiedzialnosci uzytkownika Customer:
		-
		- wyswietla liste wszystkich samochodow razem z ich stanem dostepnosci
		- wyswietla liste swojej historii najmow w tym systemie		x

	Zakes odpowiedzialnosci systemu:
		-system pzawala na wprowadzanie nowych uzytkownikow		x
		-system wystawia faktury dla Customer po zarezerwowaniu pojazdu	x
*/
Start_window start;

int main() {

	start.draw_start_window();
	//start.sign_in();

}