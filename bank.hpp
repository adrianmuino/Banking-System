#ifndef bank_hpp
#define bank_hpp

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include "time.h"
#include "account.hpp"



class Bank{
private:
    std::map<unsigned int, Account*> users;
public:
    Bank();
    ~Bank();
    void Menu() throw (MenuException);
    void displayUsers();
    void addUser() throw (MenuException);
    void removeUser() throw (MenuException);
    void verifyUser(std::map<unsigned int, Account*>::iterator& i) throw (MenuException);
    void openUsersFile();
    Name& readName(Name& n) throw (MenuException);
    Date& readDob(Date& dob) throw (MenuException);
    int& readPin(int& pin) throw (MenuException);
    unsigned int& readAcctNum(unsigned int& acctNum) throw (MenuException);
    double& readAmount(double& amount) throw (MenuException);
    friend std::ofstream& operator<<(std::ofstream& ofs, Bank& b);
    friend std::ifstream& operator>>(std::ifstream& ifs, Bank& b);
};

#endif /* bank_hpp */
