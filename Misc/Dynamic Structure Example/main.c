#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student {
	int id;
	char name[40];
};

void printStudent(struct student s)  // pass by value - this is ok because we dont want to change anything, just print info about it 
{
	printf("Student name is %s\n", s.name);
	printf("Student id is %d\n\n", s.id);
}

void initStudent(int id, char *name, struct student *s)  // pass by reference (using pointer) so that we can change it and initialize it 
{
	s->id = id;  // could also do this to dereference s and initialize the id field: (*s).id = id; 
	strcpy(s->name, name); /* string function from string.h */
}

int main (int argc, const char * argv[]) {
	
	int numStudents = 3;

	struct student *myStudents = malloc(numStudents * sizeof(struct student)); //Allocate enough bytes to store 3 struct students 
	
	/* assert that malloc is successfull  ... assert(myStudents != 0);  Remember to include the assert.h header file for this */

	// call the initStudent() function to initialize all of the students 
	initStudent(25, "Joe",  &myStudents[0]);  // the first struct student of the "array" of struct students created with malloc, use an & symbol to pass by reference to initStudent function 
	initStudent(65, "Mary", &myStudents[1]);  // the second struct student 
	initStudent(36, "Kate", &myStudents[2]);  // the third struct student 
	
	printStudent(myStudents[0]);  // pass by value 
	printStudent(myStudents[1]);
	printStudent(myStudents[2]);
		
	free(myStudents);  // Whenever you have a malloc you need to have a corresponding free() function to deallocate memory 
}
