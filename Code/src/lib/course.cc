#include "course.h"

// New Course
course::course(){

    std::cout << "Enter the name of the new course: ";
    std::cin >> name;

    std::system("clear");

};

// Destructor to clear the dynamic memory 

course::~course(){

    // clear all the assignment objects for the course  
    for(auto a : assignments){

        auto as = a.second;
        delete as;
        as = NULL;
    }

    // clear all the student objects for teh course 
    for(auto s : studentData){

        auto stu = s.second;
        delete stu;
        stu = NULL;
    }


}

// The course Menu 
int course::courseMenu(){

    while(1){

        //std::system("clear");

        std::cout << "The following operations are available under course:: " << name << std::endl << std::endl;

        std::cout << "1 --> Access / Edit the student list.\n";
        std::cout << "2 --> Access / Edit Assignments.\n";
        std::cout << "3 --> Show Grade Statistics for this course.\n";
        std::cout << "4 --> Back to the List of Available Courses.\n";
        std::cout << "5 --> Back to the Main Menu\n\n";

        std::cout << "Enter the option:: ";

        int op = -1;

        std::cin >> op;
        int status = courseMenuOptions(op);   // based on the chosen option we can go further 

        if(status == 4 || status == 5) return status;

        if(status == -1) continue;

        if(status == 1){

            studentList();   // List the students and do further operations 
            std::system("clear");
            continue;
        }

        if(status == 2){

            assignmentList();  // List the assignments and do further operations
            std::system("clear");
            continue;
        }

        if(status == 3){  // calculate the stats for the course : mean, median etc 

            courseStats();
            continue;
        }

        return 1;
    }

    return 1;

}


// Option 3 ---> course statistics 
void course::courseStats(){

    if(assignments.size() == 0){

        std::cout << "NOTE::The course does not have any assignments for statistics..\n\n";
        return;
    }

    float overallTotal = 0;
    std::vector<float> allMeans;
    float mean = 0;
    float median = 0;

    for(auto a : assignments){  // calculate the mean and medians of each assignment using the functions described in assigment class

        int i = a.first;
        auto as = a.second;

        auto x = assignmentStats(i); // get stats of an assignment 

        overallTotal += (as->max_credit * as->percent / 100);
        allMeans.push_back(x.first * as->percent / 100);
        mean+= (x.first * as->percent / 100);  // keep updating the mean 
        median+= (x.second * as->percent / 100); // keep updating the median 
    }

    std::cout << "Overall Course creits completd: " << overallTotal <<  std::endl;
    std::cout << "Overall Mean: " << mean << std::endl;
    std::cout << "Overall Median: " << median << std::endl << std::endl;

    std::cout << "Press any key to go back!\n";
    char c;
    std::cin >> c;
    std::system("clear");

    return;
}


// Get stats of a particular assignment 
std::pair<float, float> course::assignmentStats(int i){

    auto as = assignments[i];

    std::cout << "Assignment ID: " << i << "\t\t\tAssignment Name: " << as->name << std::endl;

    float mean = as->calcMean(); // mean of the assignment 
    std::cout << "Maximum Credit: " << as->max_credit << std::endl;
    std::cout << "Overall weightage for the final score: " << as->percent << std::endl;
    std::cout << "Mean Score of the class: " << mean << std::endl;
    float median = as->calcMedian(); // mediuan of the assignment 
    std::cout << "Median of the class is: " << median << std::endl << std::endl;

    return {mean, median};
}


// Option chosen from the course menu 
int course::courseMenuOptions(const int op){

    std::system("clear");

    if(op == 4 || op == 5) {  // exit statuses (course menu or the main menu)
        return op;
    }

    if(op <= 0 || op > 5){  // ERROR 
        std::cout << "ERROR:: Pleae choose a valid option from the menu below..\n\n";
        return -1;
    }

    return op;
}

// Print the list of students and choose further options 
void course::studentList(){

    while(1){
 
        printStudentOptions();  // print the student operations 

        std::cout << "\nEnter a Student ID for further information or Choose other options:: ";
        long int op = -1;
        std::cin >> op;

        int status = studentListOperations(op);  // cased on the option chose, do further operations 

        if(status == -1) continue;
        if(status == 1) break;

    }
    return;



}

// print the student list and other available options 
void course::printStudentOptions(){

    if(studentData.size() == 0){  // no students on the database 

        std::cout << "The student list is empty!\n";
    }

    else{

        std::cout << "Student ID\t\t\t\tStudent Name\n\n";

        for(auto m : studentData){

            auto id = m.first;
            auto stu = m.second;

            std::cout << id << "\t\t\t\t\t" << stu->name << std::endl;

        }

    }

    std::cout << "\nOther operations:\n\n";
    std::cout << "1 --> Add a new student\n";
    std::cout << "2 --> Remove a student\n";
    std::cout << "3 --> Go back to the course home!\n";
    return;

}

// perform operations depending on the option chosen 
int course::studentListOperations(long int op){

    std::system("clear");

    if(op == 1){  // new student 

        long int id;
        std::string name;

        std::cout << "Enter the student ID: ";
        std::cin >> id;

        if(studentData.find(id) != studentData.end()){

            std::system("clear");
            std::cout << "The student ID entered already exists!\n\n";
            return -1;
        }

        if(id == 1 || id == 2 || id == 3){

            std::system("clear");
            std::cout << "ERROR: This ID is not permitted to be used as an ID\n";
            return -1;           
        }

        std::cout << "Enter the student Name: ";
        std::cin >> name;

        
        student* newStudent = new student(id, name, assignments);  // new student 

        studentData[id] = newStudent; // update the data structure  

        std::system("clear");
        std::cout << "SUCCESS: A new student has been added successfully!\n\n";
        return -1;

    }

    if(op == 2){ // delete a student 

        long int id;
        std::cout << "Enter the student ID of the student you want to remove: ";
        std::cin >> id;

        if(studentData.find(id) == studentData.end()){

            std::system("clear");
            std::cout << "ERROR: The entere student ID does not exist in the database!\n";
            return -1;
        }

        removeStudent(id);  // remove the student from the data structure 
        std::system("clear");
        std::cout << "SUCCESS: Stduent removed successfully!\n";
        return -1;
    }

    if(op == 3) return 1; // EXIT 

    if(studentData.find(op) != studentData.end()){ // If a student ID is entered, then we need to go inside student operations 

        auto stu = studentData[op];
        stu->insideStuOps();
    }

    else{

        std::cout << "ERROR:: INVALID ENTRY!\n";
    }

    return -1;

}

//Remove a student from the database when someone drops the course
void course::removeStudent(long int id){

    student* stu = studentData[id];
    studentData.erase(id);

    for(auto a : assignments){

        auto as = a.second;

        as->removeStudents(id); // remove student from all associated data structures 
    }

    delete stu;  // clear the memory
    stu = NULL;
    return;
}

//List the assignments and do further options 
void course::assignmentList(){

    while(1){

        printAssignments();

        std::cout << "\nEnter an assignment ID for further information or Choose other options:: ";
        int op = -1;
        std::cin >> op;

        int status = assignmentListOperations(op); // further actions based on the input option 

        if(status == -1) continue;
        if(status == 1) break;

    }

    return;
}

// Print the assignments list and check for more options 
void course::printAssignments(){

    if(assignments.size() == 0){  // if the assignment list is empty

        std::cout << "The assignment list is empty.\n\n";
    }

    else{  // print the list of available assignments 

        std::cout << "The following assignments are available:\n\n";
        std::cout << "Assignment ID\t\t\tAssignment Name\n";

        for(auto a : assignments){

            auto i = a.first;
            auto as = a.second;

            std::cout << i << "\t\t\t\t" << as->name << std::endl;

        }
    }

    std::cout << "\nOther operations:\n\n";
    std::cout << "1 --> Add a new Assignment\n";
    std::cout << "2 --> Remove an assignment\n";
    std::cout << "3 --> Go back to the course home!\n";

    return;
}

// Operations based on the assignment list printed 
int course::assignmentListOperations(int op){

    std::system("clear");

    if(op == 1){  // new assignment 

        int id;
        std::string name;

        std::cout << "Enter the assignment ID: ";
        std::cin >> id;

        if(assignments.find(id) != assignments.end()){ // If the assignment already exists 

            std::system("clear");
            std::cout << "ERROR: The assignment ID entered already exists!\n\n";
            return -1;
        }
        
        if(id == 1 || id == 2 || id == 3){  // ERROR 

            std::system("clear");
            std::cout << "ERROR: This ID is not permitted to be used as an assignment ID\n";
            return -1;           
        }


        std::cout << "Enter the assignment Name: ";
        std::cin >> name;

        assignment* newAssignment = new assignment(id, name, studentData);  // new assignment 

        assignments[id] = newAssignment;

        std::system("clear");
        std::cout << "SUCCESS: A new assignment has been created successfully!\n\n";
        return -1;

    }

    if(op == 2){  // delete an assignment 

        long int id;
        std::cout << "Enter the ID of the assignment you want to remove: ";
        std::cin >> id;


        if(assignments.find(id) != assignments.end()){

            removeAssignment(id);   // do the deletion process 

            std::system("clear");
            std::cout << "SUCCESS: Assesment removed successfully!\n";
            return -1;
        }

        

        std::system("clear");
        std::cout << "ERROR: The entered assesment ID does not exist in the database!\n";
        return -1;

    }

    if(op == 3) return 1; // EXIT 

    if(assignments.find(op) != assignments.end()){ // if an assignment ID is chosen 

        auto x = assignmentStats(op);  // print the stats 
        std::cout << "\nPress any key to go back::";
        char c;
        std::cin >> c;
        std::system("clear");
    }

    return -1;

}

// Remove an assignment form the course
void course::removeAssignment(int i){


    auto as = assignments[i];
    assignments.erase(i);

    // remove the assignment from all the data structures 
    for(auto s : studentData){

        auto stu = s.second;
        stu->removeAssignment(i);
    }

    delete as;
    as = NULL;
    return;
}

