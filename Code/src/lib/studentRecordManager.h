#ifndef TEMPLATE_STUDENTRECORDMANAGER_H
#define TEMPLATE_STUDENTRECORDMANAGER_H

//#include <cstdlib.h>
#include <ncurses.h>
#include "src/lib/menu.h"
#include "src/lib/instructor.h"
#include <iostream>
#include <vector>

class studentRecordManager {

  public:
    
    studentRecordManager();   // CONSTRUCTOR
    void start();             // START THE OPERATION

    instructor* prof;         // POINTER TO AN INSTRUCTOR OBJECT

  private: 

    int optionManager(const int option);
};

#endif