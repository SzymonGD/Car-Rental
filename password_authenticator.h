#ifndef PASSWORD_AUTHENTICATOR_H
#define PASSWORD_AUTHENTICATOR_H

#define CUSTOMER_DATA_PATH "C:\\Users\\gdans\\projects\\car-rental-project\\customer_data.txt"

class Password_authenticator {
public:
	bool check_if_password_exists(std::string check_password);
	int authenticate(std::string password);
};


#endif