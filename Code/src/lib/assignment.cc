#include "assignment.h"


// Constructor when you create a new assignment 

assignment::assignment(){

    // We will use this for the G-Tests.
}

assignment::assignment(int i, std::string s, std::map<long int, student*> &students){

    id = i;
    name = s;

    std::cout << "Please enter the maximum credit for this assignment: ";
    std::cin >> max_credit;
    std::cout << "Please enter the percentage of this course for the final grade: ";
    std::cin >> percent;

    updateStudentCredits(students);   // To update the student cores 

}

// Update student marks when a new assignment is created 
void assignment::updateStudentCredits(std::map<long int, student*> &students){

    if(students.size() != 0){

        std::cout << "\nEnter the grades of the following students out of:: " << max_credit << std::endl << std::endl;

        for(auto s : students){  // we access all the students in a for loop and add scores 

            auto i = s.first;
            auto stu = s.second;
            int score;

            std::cout << "Student ID:" << i << "\t\tStudent Name: " << stu->name << "\t\tScore: ";
            std::cin >> score;

            studentCredits[i] = score;

            stu->assignmentsVec[id] = this;
            stu->assignmentScore[id] = {score, max_credit};
        }
    }

    return;
}


// Remove a student from the assignment data strucures when a student drops the course
void assignment::removeStudents(long int i){

    studentCredits.erase(i);
    return;
}

// Calculate the mean of the assignment 
float assignment::calcMean(){

    int sum = 0;

    for(auto g : studentCredits){

        int marks = g.second;
        sum+= marks;
    }

    return (float)sum/studentCredits.size();
}

// calculate the median for the assignment 
float assignment::calcMedian(){

    std::vector<int> scores;

    for(auto g : studentCredits){

        scores.push_back(g.second);
    }

    std::sort(scores.begin(), scores.end());

    int n = scores.size();

    if(n % 2 == 0){

        return (scores[(n/2)-1] + scores[n/2]) / 2;
    }

    else return scores[(n-1)/2];

}

// Change score of a student in the assignment 
void assignment::changeScore(long int i, int score){

    studentCredits.erase(i);
    studentCredits[i] = score;
}