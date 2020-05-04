#include "src/lib/instructor.h"
#include "src/lib/student.h"
#include "src/lib/course.h"
#include "src/lib/assignment.h"
#include "src/lib/studentRecordManager.h"
#include "src/lib/menu.h"
#include "gtest/gtest.h"
#include <vector>

TEST(AllTests, ReturnNoErrors) {

// Most of the functions need inout from the user to navigate. 
// I am writing tests for only those functions which do not have a user inout associated
  
  //Testing some course functionalities
  course c;

  // Reply based on user input 
  int actual = c.courseMenuOptions(4);
  int expected = 4;

  EXPECT_EQ(expected, actual);

  int actual1 = c.courseMenuOptions(5);
  int expected1 = 5;

  EXPECT_EQ(expected1, actual1);

  int actual2 = c.courseMenuOptions(0);
  int expected2 = -1;

  EXPECT_EQ(expected2, actual2);

  int actual3 = c.courseMenuOptions(100);
  int expected3 = -1;

  EXPECT_EQ(expected3, actual3);


  // Some assignment functions
  assignment a;

  // Map of student marks
  a.studentCredits = {
    {123, 100},
    {1234, 90}, 
    {12345, 90},
  };

  // Lets check if the mean and median are correct
  float actual4 = a.calcMean();
  float expected4 = (float)280/3;
  
  EXPECT_EQ(expected4, actual4);

  float actual5 = a.calcMedian();
  float expected5 = 90;

  EXPECT_EQ(expected5, actual5);

  // erase an element and check again
  a.studentCredits.erase(12345);

  float actual6 = a.calcMean();
  float expected6 = (float)190/2;
  
  EXPECT_EQ(expected6, actual6);

  float actual7 = a.calcMedian();
  float expected7 = 95;

  EXPECT_EQ(expected7, actual7);

// Most of the functions are private and can not be accessed from here. 
// I have includede the tests for few options and calculating the math with custom data structures. 
// Other data structures need the creation of dynamic memory and allocating all the data structures inside the memory.

}