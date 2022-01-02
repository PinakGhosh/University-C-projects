/*
 * bTree.c
 *
 *
 *Created on: April 15th 2021
 *Created Author: Pinak Ghosh
 *
 */

/*
 *
 * the following is a bTree class which will organize the inputed names into
 * alphabetical and reverse alphabetical order, and create a function to
 * delete the tree
 *
 */

#include <stdio.h>//this is the equivalent to imports in java
#include <stdlib.h>
#include "bTree.h"
#include <string.h>

#define false 0
#define true !false

bNode *root=NULL; //declare variables
int numNodes=0;
char **indexArray;
int recCount=0;



void initTree(){ //initialize tree method
	root = NULL;
	numNodes=0;

}



	/*
	 *
	 * adds node to the binary tree
	 *
	 * @param data is string that is inputed by user
	 *
	 */

void addNode(char *data){

	bNode *current;

	if(root== NULL){
		root = makeNode(data);
	}else{
		current = root;
		while(true){

			if(strcasecmp(data, current -> data) < 0){
				if(current -> left ==NULL){
					current -> left = makeNode(data);
					break;
				}else{
					current = current ->left;
				}
			}

			else{
				if(current -> right == NULL){
					current -> right = makeNode(data);
					break;
				}else{
					current = current -> right;
				}

			}

		}
	}
	numNodes++;
}



/**
	 *
	 * creates node for the binary tree
	 *
	 * @param data is string value
	 * @return node that is in binary tree
	 */


bNode *makeNode(char *data){

	bNode *node =(bNode *)malloc(sizeof(bNode));
	node -> data = data;
	node -> left = NULL;
	node -> right = NULL;

return node;

}


/**
	 *
	 * follows a left root right traversal method. which will then display the
	 * values in ascending order
	 *
	 * @param root is value at given point of binary tree
	 */

void inOrder(bNode *root){


	if (root -> left != NULL)
		inOrder(root->left);

	indexArray[recCount++]=root->data;

	if(root->right != NULL)
		inOrder(root->right);


}


/**
	 *
	 * follows a right root left traversal method. which will then display the
	 * values in decending order
	 *
	 * @param root is value at given point of binary tree
	 */

void inReverseOrder(bNode *root){


	if(root->right != NULL)
		inReverseOrder(root->right);

	indexArray[recCount++]=root->data;

	if(root ->left != NULL)
		inReverseOrder(root->left);


}


/*
 * @return the value for number of nodes
 */

int getNumNodes(){
	return numNodes;
}


/*
 *
 * allocates memory for array that will consist of names sorted in
 * alphabetical or reverse alphabetical order
 *
 *
 * @param args dictates if either 'd' or any other character passed
 *
 * @return indexArray, which has the names in (reverse) alphabetical order
 *
 *
 */

char **makeSortIndex(char arg){



	indexArray = (char **)malloc(sizeof(char *)*getNumNodes());
	if(indexArray == NULL){
		return NULL;
	}

	recCount=0;

	if(arg =='d' || arg =='D'){

		inReverseOrder(root);


	}else{

		inOrder(root);


	}


	return indexArray;

}





//deletes the bTree

 void deleteTree() {
       postOrder(root);
 }


/*
 *@ param root
 *
 * runs threw the tree and deletes every node
 */


 void postOrder (bNode *root) {

	 if(root->left != NULL){

		 postOrder(root->left);

	 }

	 if(root->right != NULL){

		 postOrder(root->right);

	 }


	 free(root->data);
	 free(root);
 }








