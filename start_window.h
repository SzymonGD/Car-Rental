#ifndef START_WINDOW_H
#define START_WINDOW_H

#define START_PAGE_PATH "C:\\Users\\gdans\\projects\\car-rental-project\\start_page.txt"
#define CUSTOMER_DATA_PATH "C:\\Users\\gdans\\projects\\car-rental-project\\customer_data.txt"

#include <vector>

class Start_window {
public:
	void draw_start_window();
	std::vector<std::string> sign_in();
};

#endif