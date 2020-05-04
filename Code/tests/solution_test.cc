#include "src/lib/instructor.h"
#include "src/lib/student.h"
#include "src/lib/course.h"
#include "src/lib/assignment.h"
#include "src/lib/studentRecordManager.h"
#include "src/lib/menu.h"
#include "gtest/gtest.h"
#include <vector>

TEST(AllTests, ReturnNoErrors) {

  //menu m;
  std::string actual = menu();
  std::string expected = "**** Hello World ****";
  EXPECT_EQ(expected, actual);
}