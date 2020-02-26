#include <iostream>
#include <unistd.h>
#include "bank.hpp"



/* Banking System App */

/*
 Classes:
 
 * Date
 * Name
 * Account
 * Bank
 * MenuException
 
 
*/

int main(int argc, const char * argv[]) {
    
    Bank* wellsFargo = new Bank();
    
    while(1){
        try{
            wellsFargo->Menu();
            sleep(3);
            std::cout << "\n\n";
        }catch(std::exception& e){
            std::cout << "\n\n";
            std::cout << e.what() << std::endl;
            sleep(3);
            std::cout << "\n\n";
        }
    }
    return 0;
}


