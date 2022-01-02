#include <stdio.h>//this is the equivalent to imports in java
#include <stdlib.h>
#include <string.h>

#define false 0//define true and false methods and length
#define true !false
#define LENGTH 80

//readline method
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
//string reverse method
void revstr(char *string){

	//delare variables
	char str;

	int length, rightindex, leftindex, i;


	length = strlen(string);//find length of string

	leftindex = 0;//beginning of loop value
	rightindex = length - 1;//end of loop value

	for(i= leftindex; i<rightindex; i++){// loop for length of string
		str = string[i]; // make char equal to char at point i
		string[i] = string[rightindex];// make char equal to char on opp side of string
		string[rightindex] = str;
		rightindex--;//increment right index down 1 so goes back one char
	}

	printf("Rev: %s\n", string);
}

int main() {

	// print message
	printf("String reversal program; enter string to reverse, blank line to exit.\n");



	while(true){//loop until break is found

			char *input = readline();//variable input reads line


			if(strlen(input) == 0){//loop until empty line
				break;
			}

			//print forward
			printf("fwd: %s\n", input);
			//method to print backwards
			revstr(input);


	}

}











