#include "instructor.h"

// Constructor
instructor::instructor(){

    name = "";
    id = "";
}

// Destructor to avoid memeory leaks.
instructor::~instructor(){

    //Delete all the courses created 
    for(auto c : courses){
        delete c;
        c = NULL;
    }
}

// OPTION 1 from main menu --> View/Add instructor
void instructor::operations(){

    int op = -1;

    while(1){

        printMenu();

        std::cin >> op;

        int status = furtherActions(op);    // Take further actions based on the input 
        if(status) break;
    }
    
    return;
}

// PRINTING THE MENU of Instructor
void instructor::printMenu(){

    if(name == ""){

        std::cout << "There is currently no instructor!" << std::endl << std::endl;

    }

    else{

        std::cout << "Instructor's name: " << name << std::endl;
        std::cout << "Instructor's ID: " << id << std::endl << std::endl;
        std::cout << "The courses taken by the instructor are:: ";

        if(courses.size() == 0){  // No courses to print 

            std::cout << "{The course List is Empty}" << std::endl << std::endl;
        }
        else{  // print the courses 

            std::cout << "{\t";

            for(auto x : courses){

                std::cout << x->name << "\t";

            }

            std::cout << "}\n\n";
        }
    }

    std::cout << "Choose further operations if required::" << std::endl;
    std::cout << "1--> Edit/Add Instrctor" << std::endl;
    std::cout << "2--> Return to the Main Menu" << std::endl;
    std::cout << "Enter the option:: ";
}

// BAsed on the option chosen, we take further actions!
int instructor::furtherActions(const int op){

    std::system("clear");

    if(op == 2) { //EXIT

        std::system("clear");
        return 1;
    }

    if(op != 1){  // INVALID ENTRY

        std::system("clear");
        std::cout << "Invalid option. Please choose a valid option.." << std::endl <<std::endl;
        return 0;
    }

    addInstructor(); // OPTION == 1
    return 0;

}

// Add an new instructor
void instructor::addInstructor(){

    eraseData();  //ERASE EXISTING PROF
    std::system("clear");

    while(1){

        std::cout << "Enter the instructor Name: ";
        std::cin >> name;

        if(name == ""){   // if the entered name is an empty string 

            std::system("clear");

            std::cout << "Please enter some text!\n" << std::endl;
        }

        else break;
    }

    while(1){

        std::cout << "Enter the instructor ID: ";
        std::cin >> id;

        if(id == ""){  // if the entered Id is empty 

            std::cout << "Please enter a valid ID!\n" << std::endl;
        }

        else break;
    }

    std::system("clear");
    return;
}

//Erase the exisiting instructor 
void instructor::eraseData(){   // Just make them empty strings 

    name = "";
    id = "";
    return;
}

// Add a new course
void instructor::addCourse(course* newCourse){

    courses.push_back(newCourse);
}

// If the view courses option is chosen 
void instructor::courseOperations(){

    int i;

    while(1){

        std::cout << "The available courses are::\n " << std::endl;

        i = 1;
        for(auto x : courses){

            std::cout << i << ": " << x->name << std::endl;
            i++;

        }

        std::cout << i << ": " "Return to the main menu.\n" << std::endl;

        std::cout << "Enter the option:: ";

        int op = -1;
        std::cin >> op;

        if(op == i){

            std::system("clear");
            return;
        }

        int status = courseOperationsHelper(op, i);  // based on the option chosen we can take further actions 
 
        i = op;
        if(status) {

            std::system("clear");
            int ret_val = courses[i-1]->courseMenu();

            if(ret_val == 4)
            continue;

            if(ret_val == 5)
            break;
        }

    }

    return; 

}

// If a course option is chosen then a helper function

int instructor::courseOperationsHelper(const int op, const int i){

    if(op > i || op <= 0){  // Invalid option 

        std::system("clear");
        std::cout << "\nPlease enter a valid option.\n";
        return 0;
    }        
    
    return 1;    
}