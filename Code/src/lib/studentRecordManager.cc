#include "studentRecordManager.h"

studentRecordManager::studentRecordManager(){}

void studentRecordManager::start(){

  prof = new instructor();

  int option; 

  while(1){

    // PRINT THE MAIN MENU
      menu();

    // READ THE USER INPUT
      std::cin >> option;

      int status = optionManager(option);

      if(status) break;

    }

    return;
}

int studentRecordManager::optionManager(const int option){

  if(option == 4) return 1;    // EXIT THE PROGRAM 

  if(option != 1 && option != 2 && option != 3){   //WRONG ENTRY

    std::system("clear");
    std::cout << "The entered option does not exist! Please choose a valid option from the menu.." << std::endl << std::endl;
    return 0;
  }

 // OPERATIONS BASED ON THE SELECTED OPTION
  if(option == 1){
    
    std::system("clear");
    prof->operations();
  }

  else if(option == 2){

    std::system("clear");
    course* newCourse = new course();
    prof->addCourse(newCourse);
  }

  else if(option == 3){

    std::system("clear");
    prof->courseOperations();
  }

  return 0;
}

