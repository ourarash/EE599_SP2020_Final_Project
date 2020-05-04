#ifndef TEMPLATE_STUDENT_H
#define TEMPLATE_STUDENT_H

#include <string>
#include <vector>
#include <map>
#include "assignment.h"
#include <iostream>

class assignment;

class student{

    public: 

        student(long int i, std::string s, std::map<int, assignment*> &assign);

        void removeAssignment(int a);
        void insideStuOps();

        long int id;    // Stident ID
        std::string name;   // Student Name
        std::map<int, assignment*> assignmentsVec;    // Map from Assignment ID to ---> Assignment Object
        std::map<int, std::pair<int, int>> assignmentScore;   // Map:: Assignment Id--> {score, max Credit}

    private:

        void newStudentGrades();
        int editGrades(int op);

};


#endif