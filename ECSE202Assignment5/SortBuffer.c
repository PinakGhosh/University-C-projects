/*
 * SortBuffer.c
 *
 *
 *Created on: April 15th 2021
 *Created Author: Pinak Ghosh
 *
 */

/*
 *
 * This reads the user inputs and gets the appropriate tools from the bTree.c
 * class to sort and display the inputs in alphabetical order
 *
 */



#include <stdio.h>//this is the equivalent to imports in java
#include <stdlib.h>
#include <string.h>
#include "bTree.h"

#define false 0//define true and false methods and length
#define true !false
#define LENGTH 80

/*
 *
 * creates a readline method similar to javas readline method
 *
 *
 * @return buffer
 */

char *readline() {

	char *buffer = malloc(LENGTH);//allocate space


				if(buffer==NULL){//if no space allocated display this message

					printf("can't allocate buffer. \n");
					return NULL;


				}

				fgets(buffer, LENGTH, stdin);//get the value from the line
				buffer[strlen(buffer)-1] = '\0';





		return buffer;

	}



/**
	 *
	 * gives instructions to code,creates binary tree and reads inputs that will be
	 * inputed in binary tree and then reads them according to the code in
	 *
	 */



int main () {


char** outputArray;
int index;


// print instructions

	printf("Text Sorting Program: (ECSE 202 - Assignment 5)\n");
	printf("Enter text to be sorted, line by line. A blank line terminates.\n");
	printf("You can cut and paste text into this window:\n");


// initialize tree

	initTree();

	while (true){//loop until input is nothing on the line

		// make character array equal to readline method
		char *input = readline();

		if(strlen(input) == 0){// if the length of the string of a line is 0
			printf("\n");
			printf("Text Sort in Order:\n");//print message
			printf("\n");
			outputArray = makeSortIndex('a');//make array equal to names sorted in alphabetical
			for (index=0; index<getNumNodes(); index++){//loop until all names printed
			printf("%s\n" , outputArray[index]);
				}
			free(outputArray);//free array of memory
			printf("\n");
			printf("Text sort in Reverse Order:\n");//print message
			printf("\n");
			outputArray = makeSortIndex('d');//make array equal to names sorted in alphabetical
			for (index=0; index<getNumNodes(); index++){//loop until all names printed
					printf("%s\n" , outputArray[index]);
				}
			free(outputArray);//free array of memory
			break;

		}
		addNode(input);//adds node to be put into bTree

	}

	deleteTree();//delete tree
	printf("\n");
	printf("Program Terminated.\n");//display message




}

