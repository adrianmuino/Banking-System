# Banking-System
A command line application that replicates embedded software of ATMs at banks. 

The Banking System application allows users to perform the following operations with the bank:
  * register an account
  * close an account
  * check account balance
  * deposit into account
  * withdraw from account
  * show list of all users registered with the bank

The application interacts with a text file called "users.txt" to store user's information; hence simulating the database 
for a bank. Whenever the first account gets created in the system, the file "users.txt" will be created. After one account exists, every time that the program is executed, information from "users.txt" is retrieved and loaded into the program.

The underlying data structure used to store bank users in the banking system is a STL Map.

## NOTE: 
*If running this program of MacOs, you will need to run this program using the Xcode IDE and in the project settings, the Derived Data data must be set to the Banking-System project directory, otherwise, THIS PROGRAM WILL NOT COMPILE.
*If running this program in any other IDE, make sure that the Derived Data is set to the Banking-System project directory, otherwise, THIS PROGRAM WILL NOT COMPILE.
## THIS IS NECESSARY IN ORDER FOR THE "users.txt" FILE TO BE CREATED IN THE PROPER DIRECTORY.
