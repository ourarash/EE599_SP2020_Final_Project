#include "src/lib/menu.h"

// THIS IS TO PRINT THE WELCOME MENU
// USING A DIFFERENT FILE TO KEEP THE CODE CLEAN!
void menu(){

    std::cout << "************WELCOME TO THE STUDENT RECORD MANAGER****************" << std::endl;

    std::cout << "\nPlease choose one of the following operations\n" << std::endl;
    
    std::cout << "1 --> View / Edit instructor's details" << std::endl;

    std::cout << "2 --> Create a new course" << std::endl;

    std::cout << "3 --> Select an existing course" << std::endl;

    std::cout << "4 --> Exit the program\n" << std::endl;

    std::cout << "Enter the option:: ";
}