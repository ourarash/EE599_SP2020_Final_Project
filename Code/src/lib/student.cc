#include "student.h"

//Construcotr 
student::student(long int i, std::string s, std::map<int, assignment*> &assign){

    id = i;
    name = s;
    assignmentsVec = assign;  // copy all the assignments 
 
    newStudentGrades();  // Add the grades of the student for the existing assignment 

}

// Add grades to the new student 
void student::newStudentGrades(){

    if(assignmentsVec.size() != 0){  // if assignments are not emptyt 

        std::cout << "Please enter the gardes for this student for the following assignments:\n";

        for(auto a : assignmentsVec){

            auto i = a.first;
            auto as = a.second;

        int score = 0;

        std::cout << "\nAssignment: " << i << "\t\tAssignment Name: " << as->name << std::endl;
        std::cout << "Max Credit = " << as->max_credit << std::endl;
        std::cout << "Student score: ";
        std::cin >> score;

        std::pair<int, int> grade = {score, as->max_credit};

        assignmentScore[i] = grade;
        as->studentCredits[id] = score;
        
        } 

    }

    return;
}


// Student options for further actions 
void student::insideStuOps(){

// Calculate everything of the student, mean median and display his operations 
    while(1){

        std::cout << "These are the details of the student: " << name << "  (Student ID: " << id << ")\n\n";

        float sum = 0;
        float sum_max;
        float sum_w = 0;
        float sum_w_max = 0;

        for(auto a : assignmentsVec){

            auto i = a.first;
            auto as = a.second;

            std::cout << "Assignment ID: " << i << "\t\tAssignment Name: " << as->name << std::endl;
            std::cout << "Maximum Credit for the assignment: " << as->max_credit << std::endl;
            auto x = assignmentScore[i];
            auto score = x.first;
            auto max_cr = as->max_credit;
            std::cout << "Student score: " << score << " out of " << max_cr << std::endl << std::endl;
            sum+= score;
            sum_max+= max_cr;

            sum_w+= score * as->percent / 100;
            sum_w_max+= max_cr * as->percent / 100;

        }

        std::cout << "\nTotal Score: " << sum << " out of " << sum_max << std::endl;
        std::cout << "Total weighted score: " << sum_w << " out of " << sum_w_max << std::endl;

        std::cout << "\nEnter '1' to go back or Enter an assignment ID to change score: ";
        int op = -1;

        std::cin >> op;

        // based on the option we can change score of an assignment or we can go back 
        if(op == 1) {

            std::system("clear");
            break;
        }

        int status = editGrades(op);

        if(status == -1) continue;
    }

    return;

}


// To edit student grades
int student::editGrades(int op){

    std::system("clear");

    if(assignmentsVec.find(op) == assignmentsVec.end()){ // if the entered assignment does not exist 

        std::cout << "ERROR:: Invalid Entry!\n\n";
        return -1;
    }

    else{  // cahnge the assignment score by taking the new entry 

        auto as = assignmentsVec[op];

        std::cout << "Editing detials for assignment ID: " << op << "  (Assignment Name: " << as->name << ")\n";
        std::cout << "Student ID: " << id << "\t\tStudent Name: " << name << std::endl;
        std::cout << "Assignment Max Credit: " << as->max_credit << std::endl;
        std::cout << "Enter the new score of the student: ";
        int score;
        std::cin >> score;

        std::pair<int, int> update = {score, as->max_credit};
        assignmentScore[op] = update;

        as->changeScore(id, score);
        std::system("clear");
    }

    return -1;
}

// To remove an assignment from the student data structure. 

void student::removeAssignment(int a){

    assignmentsVec.erase(a);
    assignmentScore.erase(a);
}

