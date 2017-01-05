####################################################
#Name: Peter Moldenhauer
#Date: 1/5/17
#Description: This is a makefile that builds the 
#executable file "Assignment0" from the file main.c
#####################################################

default: Assignment0

main.0: main.c
	gcc -Wall -std=c99 -c main.c99
	
Assignment0: main.o
	gcc -Wall -std=c99 -o Assignment0 main.o
	
clean:
	rm main.o
	
cleanall: clean
	rm Assignment0