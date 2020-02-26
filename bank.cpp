#include "bank.hpp"

Bank::Bank(){
    openUsersFile();
}

Bank::~Bank(){
    std::map<unsigned int, Account*>::iterator i;
    for(i = users.begin(); i != users.end(); i++){
        delete (i->second);
    }
}

void Bank::Menu() throw (MenuException){
    std::cout << "Please choose an option:\n";
    std::cout << "Press '1' to Open an Account\n";
    std::cout << "Press '2' to Close an Account\n";
    std::cout << "Press '3' to Check Balance\n";
    std::cout << "Press '4' to Deposit\n";
    std::cout << "Press '5' to Withdraw\n";
    std::cout << "Press '6' to Show All Users\n";
    std::string input;
    std::getline(std::cin, input);
    if(input.length() == 1){
        switch(input[0]){
            case '1':
                addUser();
                break;
            case '2':
                {
                removeUser();
                std::map<unsigned int, Account*>::iterator i;
                std::ofstream ofs("users.txt", std::ios::trunc);
                for(i = users.begin(); i != users.end(); i++){
                    ofs << i->first << " ";
                    ofs << *(i->second);
                    ofs << std::endl;
                }
                ofs.close();
            }
                break;
            case '3':
            {
                std::map<unsigned int, Account*>::iterator i;
                verifyUser(i);
                std::cout << "Your balance is: \n$" << ((i->second)->getBalance()) << std::endl;
            }
                break;
            case '4':
            {
                std::map<unsigned int, Account*>::iterator i;
                verifyUser(i);
                std::cout << "Enter amount to deposit: \n$";
                double amount;
                try{
                    amount = readAmount(amount);
                }catch(std::exception& e){
                    throw MenuException(e.what());
                }
                
                (i->second)->deposit(amount);
                std::ofstream ofs("users.txt", std::ios::trunc);
                for(i = users.begin(); i != users.end(); i++){
                    ofs << i->first << " ";
                    ofs << *(i->second);
                    ofs << std::endl;
                }
                ofs.close();
            }
                break;
            case '5':
            {
               std::map<unsigned int, Account*>::iterator i;
               verifyUser(i);
               std::cout << "Enter amount to withdraw: \n$";
               double amount;
               try{
                   amount = readAmount(amount);
               }catch(std::exception& e){
                   throw MenuException(e.what());
               }
                
               (i->second)->withdraw(amount);
                std::ofstream ofs("users.txt", std::ios::trunc);
                for(i = users.begin(); i != users.end(); i++){
                    ofs << i->first << " ";
                    ofs << *(i->second);
                    ofs << std::endl;
                }
                ofs.close();
            }
               break;
            case '6':
                displayUsers();
                break;
            default:{
            
                throw MenuException("Invalid Key Pressed!");
            }
                break;
        }
    }else{
        
        throw MenuException("Invalid Key Pressed!");
    }
    
}

void Bank::displayUsers(){
    std::map<unsigned int, Account*>::iterator i;
    if(users.begin() != users.end()){
        for(i = users.begin(); i != users.end(); i++){
            std::cout << (*(i->second)) << std::endl;
        }
    }else{
        std::cout << "No Users in the system!\n";
    }
}

void Bank::addUser() throw (MenuException){
    std::cout << "Enter your name: (first last)\n";
    Name name;
    try{
        name = readName(name);
    }catch(std::exception& e){
        throw MenuException(e.what());
    }
    
    std::cout << "Enter your Date Of Birth: (month day year)\n";
    Date dob;
    try{
        dob = readDob(dob);
    }catch(std::exception& e){
        throw MenuException(e.what());
    }
    
    std::cout << "Enter a PIN Number:\n";
    int pin;
    try{
        pin = readPin(pin);
    }catch(std::exception& e){
        throw MenuException(e.what());
    }
    
    Account* a = new Account(name, dob, pin);
    int key = (a->getCount());
    users.insert(std::pair<unsigned int, Account*>(key,a));
    
    std::ofstream ofs("users.txt", std::ios::app);
    ofs << key << " ";
    ofs << *a << std::endl;
    ofs.close();
    std::cout << "User has been successfully created\n";
}

void Bank::removeUser() throw (MenuException){
    std::cout << "Enter your Account Number:\n#";
    unsigned int accNum = 0;
    try{
        accNum = readAcctNum(accNum);
    }catch(std::exception& e){
        throw MenuException(e.what());
    }
    
    std::map<unsigned int, Account*>::iterator i;
    i = users.find(accNum);
    if(i == users.end()){
        throw MenuException("Invalid Account Number!");
        return;
    }
    std::cout << "Enter your name:\n";
    Name name;
    try{
        name = readName(name);
    }catch(std::exception& e){
        throw MenuException(e.what());
    }
    Name acctName = ((i->second)->getName());
    if( acctName != name){
     throw MenuException("Invalid Name!");
    }
    std::cout << "Enter your Date Of Birth: (month day year)\n";
    Date dob;
    try{
        dob = readDob(dob);
    }catch(std::exception& e){
        throw MenuException(e.what());
    }
    Date userDOB = ((i->second)->getDOB());
    if(userDOB != dob){
     throw MenuException("Invalid Date of Birth!");
        return;
    }
    std::cout << "Enter a PIN Number:\n";
    int pin;
    try{
        pin = readPin(pin);
    }catch(std::exception& e){
        throw MenuException(e.what());
    }
    int userPIN = (i->second)->getPin();
    if(userPIN != pin){
    throw MenuException("Invalid Pin!");
        return;
    }
    users.erase(i);
    delete (i->second);
    
    std::ofstream ofs("users.txt", std::ios::trunc);
    
    for(i = users.begin(); i != users.end(); i++){
        ofs << i->first << (*(i->second)) << std::endl;
    }
    ofs.close();
    
    std::cout << "Account successfully deleted!\n";
}

void Bank::verifyUser(std::map<unsigned int, Account*>::iterator& i) throw (MenuException){
    std::cout << "Enter your Account Number: \n#";
    unsigned int x = 0;
    try{
        x = readAcctNum(x);
    }catch(std::exception& e){
        throw MenuException(e.what());
    }
   
    i = users.find(x);
    if(i == users.end()){
     throw MenuException("Invalid Account Number!");
        return;
    }
    std::cout << "Enter your PIN: \n";
    try{
        x = readAcctNum(x);
    }catch(std::exception& e){
        throw MenuException(e.what());
    }
   
    unsigned int userPIN = (i->second)->getPin();
    if(x != userPIN){
      throw MenuException("Invalid Pin!");
        return;
    }
}

void Bank::openUsersFile(){
    std::ifstream ifs("users.txt");
    if(ifs.is_open()){
        unsigned int key;
        Name n;
        Date d;
        int pin;
        
        while(ifs >> key){
            Account* a = new Account(n,d,pin);
            ifs >> *a;
            users.insert(std::pair<unsigned int, Account*>(key, a));
        }
    }
    ifs.close();
}

Name& Bank::readName(Name& name) throw (MenuException){
    std::string input;
    std::getline(std::cin, input);
    std::locale loc;
    int spaceCount = 0;
    int spaceIndex;
    for(int i = 0; i < input.length(); i++){
        if((std::isalpha(input[i], loc)) || input[i] == ' ' || input[i] == '\'')
        {
            if(input[i] == ' ')
            {
                spaceIndex = i;
                spaceCount++;
            }
        }
        else{
            throw MenuException("Error reading name\n");
        }
        
    }
    if(spaceCount != 1)
         throw MenuException("Error reading name\n");
    else{
        std::stringstream s_input(input);
        s_input >> name.firstName >> name.lastName;
        return name;
    }
}

Date& Bank::readDob(Date& dob) throw (MenuException){
    
    std::string input;
    std::getline(std::cin, input);
    std::locale loc;
    int spaceCount = 0;
    for(int i = 0; i < input.length(); i++){
        if((std::isdigit(input[i], loc)) || input[i] == ' '){
            if(input[i] == ' ')
            {
                spaceCount++;
            }
        }else{
            throw MenuException("Error reading date of birth\n");
        }
    }
    if(spaceCount != 2)
         throw MenuException("Error reading date of birth\n");
    else{
        std::stringstream s_input(input);
        s_input >> dob;
        return dob;
    }
}

int& Bank::readPin(int& pin) throw (MenuException){
    
    std::string input;
    std::getline(std::cin, input);
    std::locale loc;
    
    if(input.length() != 4){
        throw MenuException("Pin must be a 4 digit number!");
    }
    for(int i = 0; i < input.length(); i++){
        if(!(std::isdigit(input[i], loc)))
            throw MenuException("Pin must be a 4 digit number!");
    }
    
    std::stringstream s_input(input);
    s_input >> pin;
    return pin;
    
}

unsigned int& Bank::readAcctNum(unsigned int& acctNum) throw (MenuException){
    std::string input;
    std::getline(std::cin, input);
    std::locale loc;

    for(int i = 0; i < input.length(); i++){
        if(!(std::isdigit(input[i], loc)))
            throw MenuException("Invalid Account number!");
    }
    
    std::stringstream s_input(input);
    s_input >> acctNum;
    return acctNum;
}

double& Bank::readAmount(double& amount) throw (MenuException){
    std::string input;
    std::getline(std::cin, input);
    std::locale loc;
    int dotCount = 0;

    for(int i = 0; i < input.length(); i++){
        if((std::isdigit(input[i], loc))){
            continue;
        }else if(input[i] == '.'){
            dotCount++;
        }else{
            throw MenuException("Invalid Amount Entered!");
        }
    }
    if(dotCount > 1){
        throw MenuException("Invalid Amount Entered!");
    }
        
    std::stringstream s_input(input);
    s_input >> amount;
    return amount;
}
