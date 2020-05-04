#ifndef TEMPLATE_ASSIGNMENT_H
#define TEMPLATE_ASSIGNMENT_H

#include <map>
#include <string>
#include "src/lib/student.h"
#include <algorithm>

class student;

class assignment{

    public: 

        assignment();
        assignment(int i, std::string s, std::map<long int, student*> &students);

        int max_credit;
        float percent;
        std::map<long int, int> studentCredits;
        std::string name;
        int id;


        
        void removeStudents(long int i);
        void changeScore(long int i, int score);
        float calcMean();
        float calcMedian();
    
    private: 

        void updateStudentCredits(std::map<long int, student*> &students);

};

#endif