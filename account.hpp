#ifndef account_hpp
#define account_hpp

#include <iostream>
#include <fstream>
#include "exception.hpp"

struct Date {
    int month, day, year;
    friend std::ostream& operator<<(std::ostream& os, Date& d);
    friend std::istream& operator>>(std::istream& is, Date& d) throw (MenuException);
    friend std::ofstream& operator<<(std::ofstream& ofs, Date& d);
    friend std::ifstream& operator>>(std::ifstream& ifs, Date& d);
    friend bool operator!=(Date& d1, Date& d2);
};

struct Name {
    std::string firstName;
    std::string lastName;
    friend std::ostream& operator<<(std::ostream& os, Name& n);
    friend std::istream& operator>>(std::istream& is, Name& n);
    friend std::ofstream& operator<<(std::ofstream& ofs, Name& n);
    friend std::ifstream& operator>>(std::ifstream& ifs, Name& n);
    friend bool operator!=(Name& n1, Name& n2);
};

class Account{
private:
    Name name;
    Date dob;
    double balance;
    unsigned int accNumber;
    int pinNumber;
    static unsigned int count;
public:
    Account(Name& name, Date& dob, int& pinNumber);
    Name getName();
    unsigned int getAccNum();
    int getPin();
    double getBalance();
    Date getDOB();
    static int getCount();
    void deposit(double& amount);
    void withdraw(double& amount);
    friend std::ostream& operator<<(std::ostream& os, Account& a);
    friend std::ofstream& operator<<(std::ofstream& ofs, Account& a);
    friend std::ifstream& operator>>(std::ifstream& ifs, Account& a);
};


#endif /* account_hpp */
