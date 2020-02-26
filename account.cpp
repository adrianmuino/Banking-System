#include "account.hpp"

unsigned int Account::count = 0;

Account::Account(Name& name, Date& dob, int& pinNumber){
    Account::count++;
    accNumber = Account::count;
    balance = 0;
    this->name = name;
    this->dob = dob;
    this->pinNumber = pinNumber;
}

void Account::deposit(double& amount){
    balance += amount;
    std::cout << "$" << amount << " Successfully deposited.\n";
}

void Account::withdraw(double& amount){
    if((balance - amount) < 0){
        std::cout << "Cannot withdraw $" << amount << " because of insufficient funds.\n";
    }else{
        balance -= amount;
        std::cout << "$" << amount << " Successfully withdrawn.\n";
    }
}

unsigned int Account::getAccNum(){
    return accNumber;
}

double Account::getBalance(){
    return balance;
}


std::ostream& operator<<(std::ostream& os, Date& d){
    if(d.month < 10){
        os << "0" << d.month;
    }else{
        os << d.month;
    }
        
    if(d.day < 10){
        os << "/0" << d.day;
    }else{
        os << "/" << d.day;
    }
    
    os << "/" << d.year;
    return os;
}

std::istream& operator>>(std::istream& is, Date& d) throw (MenuException){
    if(is >> d.month && (d.month < 13) && (d.month > 0)){
        //continue;
    }else{
        throw MenuException("Invalid Month Entered!");
    }
    if( is >> d.day && (d.day < 31) && (d.day > 0)){
        //continue;
    }else{
        throw MenuException("Invalid Day Entered!");
    }
    if( is >> d.year && (d.year < 2020) && (d.year > 1900)){
        //continue;
    }else{
        throw MenuException("Invalid Year Entered!");
    }
    return is;
}

Name Account::getName(){
    return name;
}

Date Account::getDOB(){
    return dob;
}

int Account::getCount(){
    return Account::count;
}

bool operator!=(Date& d1, Date& d2){
    bool notSameDate;
    
    if(d1.day != d2.day || d1.year != d2.year || d1.month != d2.month)
        notSameDate = true;
    else
        notSameDate = false;
    
    return notSameDate;
}

std::ostream& operator<<(std::ostream& os, Account& a){
    os << "Acct#: " << a.accNumber << " \tName: " << a.name << " \tDOB: " << a.dob;
    return os;
}

std::ostream& operator<<(std::ostream& os, Name& n){
    os << n.firstName << " " << n.lastName;
    return os;
}
std::istream& operator>>(std::istream& is, Name& n){
    is >> n.firstName >> n.lastName;
    return is;
}
bool operator!=(Name& n1, Name& n2){
    if((n1.firstName != n2.firstName) || (n1.lastName != n2.lastName)){
        return true;
    }else{
        return false;
    }
}

int Account::getPin(){
    return pinNumber;
}

std::ofstream& operator<<(std::ofstream& ofs, Date& d){
    ofs << d.month << " " << d.day << " " << d.year;
    return ofs;
}
std::ifstream& operator>>(std::ifstream& ifs, Date& d){
    ifs >> d.month >> d.day >> d.year;
    return ifs;
}

std::ofstream& operator<<(std::ofstream& ofs, Name& n){
    ofs << n.firstName << " " << n.lastName;
    return ofs;
}
std::ifstream& operator>>(std::ifstream& ifs, Name& n){
    ifs >> n.firstName >> n.lastName;
    return ifs;
}

std::ofstream& operator<<(std::ofstream& ofs, Account& a){
    ofs << a.name << " ";
    ofs << a.dob << " ";
    if(a.pinNumber < 10){
        ofs << "000" << a.pinNumber;
    }else if(a.pinNumber < 100){
        ofs << "00" << a.pinNumber;
    }else if(a.pinNumber < 1000){
        ofs << "0" << a.pinNumber;
    }else{
        ofs << a.pinNumber;
    }
    
    ofs << " " << a.balance;
    return ofs;
}
std::ifstream& operator>>(std::ifstream& ifs, Account& a){
    ifs >> a.name;
    ifs >> a.dob;
    ifs >> a.pinNumber;
    ifs >> a.balance;
    return ifs;
}
