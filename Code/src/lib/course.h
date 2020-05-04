#ifndef TEMPLATE_COURSE_H
#define TEMPLATE_COURSE_H

#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>
#include <numeric>
#include "student.h"
#include "assignment.h"

class course{

    public:

    course();

    std::string name;
    std::map<int, assignment*> assignments;
    std::map <long int, student*> studentData;

    ~course();

    int courseMenu();   

    private:

    int courseMenuOptions(const int op);
    void studentList();
    int studentListOperations(long int op);
    void printStudentOptions();
    void removeStudent(long int id);
    void assignmentList();
    void printAssignments();
    int assignmentListOperations(int op);
    void removeAssignment(int i);
    void courseStats();
    std::pair<float, float> assignmentStats(int i);
    
};

#endif