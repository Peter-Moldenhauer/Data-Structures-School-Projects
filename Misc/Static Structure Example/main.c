#include <stdio.h>   // for printf() function 
#include <string.h>  // for string functions 


struct student {  // struct declaration 
	int id;
	char name[40];  // an array of 40 characters used to store the name of the student (as a string of characters) 
};

int c = 8; /* global variable because its of global scope (not declared in any particular function) */


// this funciton elminates the need to dublicate code (now with this function we can comment out the duplicated code below in main) 
void printStudent(struct student s)
{
	int c = 10; /* This is a local variable named c */
	printf("Name of student is %s\n", s.name);
	printf("Id of student is %d\n", s.id);
	printf("Inside printStudent, c = %d\n\n", c); // loval scope overrides global scope so c == 10 here not 8 
	
}


int main (int argc, const char * argv[]) {  // Note the singnature for the main program int argc...

	struct student joe;  // static declare joe as of type struct student 
	joe.id = 25;
	strcpy(joe.name, "Joe");  // Note the strcpy() function with the target in the struct and the string to copy into the struct 
	
	//printf("Name of student is %s\n", joe.name);
	//printf("Id of student is %d\n\n", joe.id);
	printStudent(joe);
	
	struct student mary;  // static declare mary as of type struct student 
	strcpy(mary.name,"Mary");
	mary.id = 65;
	//printf("Name of student is %s\n", mary.name);
	//printf("Id of student is %d\n\n", mary.id);
	printStudent(mary);


	struct student kate;   // static declare kate as of type struct student 
	strcpy(kate.name,"Kate");
	kate.id = 73;
	//printf("Name of student is %s\n", kate.name);
	//printf("Id of student is %d\n\n", kate.id);
	printStudent(kate);

	printf("In main, the value of c = %d\n",c);  // this just demonstrates and prints the global value of c (defined at top of program as global) 
	
    return 0;
}
