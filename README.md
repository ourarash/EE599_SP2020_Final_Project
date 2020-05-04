

Name : Krishna Sai Tarun (kpasupul@usc.edu/ USC ID: 3006073420)

Welcome to the Student Record Management System.

Short Description: 

This is an application interface for the instructor to maintain student records. 

The interface will have options for the instructor to enter his/her details, enter the courses they are teaching. They can create an assessment and a student database and enter the students’ grades and marks for each assessment.
They Can add/ remove students from the list whenever required. 
Can edit student scores after regrading and re-evaluation. 
They can add/ remove assignments and give the weightage of each assignment to the final grade as per their wish.
They Can calculate class averages, and give out grades.
 

Features: 

	Program Flow is clean and easy to understand
	Classes are well defined
	Initial interface is easy to operate from
	Implemented student database part and the assignment entry part with quick time complexity data structures
	Implemented the calculations and the math behind the grades using efficient algorithms. 
	
	Back-end: C++
	Front-end: Linux Terminal
	
	
Overview of the implementation: 

	Main(){
		Here we call the student record manager object to start the process...
	}

	Class Student Record Manager {
	
		Creates an instructor object who can perform further actions..
	}

	Class Instructor{
	
		Vector of Courses he/she is in charge of{ course 1, course 2......}
	}

	Class Course {
	
		All the details of the course (basics like ID and Name)—
			map to assignments: {Assignment ID  ---> pointer to Assignment Object}
			map to students: {Student ID --->  pointer to Student Object}
	}
	
	Class assignment{
	
		Every assignment object has a student list and their scores. 
			map {student ID  ---> Score in the Assignment}
		It has other details for calculating the weighted averages as well.
	}
	
	Class Student{
	
		Every Student has a map to the assignments and has a record of scores for each assignment. 
		map {Assignment ID  ---> pointer to Assignment Object}
		map {Assignment ID  ---> {Score in the Assignment, max Credit}}
	}

Link to the video demonstration: https://youtu.be/HfpnjfPqqt0

Link to more details and working screenshots: 
https://docs.google.com/document/d/1FxoE18mXDih5avZgmIjBe2T8RTuJtVkW2x0ou8Fo7ik/edit
	

Initial Interface:  


			************WELCOME TO THE STUDENT RECORD MANAGER****************

		Please choose one of the following operations

		1 --> View / Edit instructor's details
		2 --> Create a new course
		3 --> Select an existing course
		4 --> Exit the program
		Enter the option::

	And the navigation happens from this menu. 


Compilation and running: BAZEL ---> bazel run main:main (from the main folder in src)


TODO/Further Development: 

	Create a better front-end for the user. 
	Add more error checking mechanisms for the data entered by the user
