/*************************************************************************************************
* Author:                       Peter Moldenhauer
* Date Created:                 2/11/17
* Last Modification Date:       2/16/17
* Filename:                     bst.c
* Class:                        CS 261 - Data Structures
* Assignment:                   Assignment 4
*
* Overview:
*   This file is a recursive implementation of the binary search tree (BST) data structure. It is
*   implemented in such a way that it can store arbitrary structures at each node (made possible
*   by the included compare.c file which contains the compare() and print_type() functions for the
*   given structure).
*
* Input:
*   There is no user input in this program.
*
* Output:
*   This program outputs various messages to the screen that notifies the user that various test
*   cases are passed when run on the binary search tree. These test functions are defined and
*   called in this file.
*************************************************************************************************/

/*
 File: bst.c
 Implementation of the binary search tree data structure.
  */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "bst.h"
#include "structs.h"

#define MEM_FIX // Modifies the test code to get rid of the memory leak issues

struct Node {
	TYPE         val;
	struct Node *left;
	struct Node *right;
};

struct BSTree {
	struct Node *root;
	int          cnt;
};

/*----------------------------------------------------------------------------*/
/*
 function to initialize the binary search tree.
 param tree
 pre: tree is not null
 post:	tree size is 0
		root is null
 */

void initBSTree(struct BSTree *tree)
{
	tree->cnt  = 0;
	tree->root = 0;
}

/*
 function to create a binary search tree.
 param: none
 pre: none
 post: tree->count = 0
		tree->root = 0;
 */

struct BSTree*  newBSTree()
{
	struct BSTree *tree = (struct BSTree *)malloc(sizeof(struct BSTree));
	assert(tree != 0);

	initBSTree(tree);
	return tree;
}

/*----------------------------------------------------------------------------*/
/*
function to free the nodes of a binary search tree
param: node  the root node of the tree to be freed
 pre: none
 post: node and all descendants are deallocated
*/

void _freeBST(struct Node *node)
{
	if (node != 0) {
		_freeBST(node->left);
		_freeBST(node->right);
#ifdef MEM_FIX
		assert(node->val);
		free(node->val);
#endif
		free(node);
	}
}

/*
 function to clear the nodes of a binary search tree
 param: tree    a binary search tree
 pre: tree ! = null
 post: the nodes of the tree are deallocated
		tree->root = 0;
		tree->cnt = 0
 */
void clearBSTree(struct BSTree *tree)
{
	_freeBST(tree->root);
	tree->root = 0;
	tree->cnt  = 0;
}

/*
 function to deallocate a dynamically allocated binary search tree
 param: tree   the binary search tree
 pre: tree != null;
 post: all nodes and the tree structure itself are deallocated.
 */
void deleteBSTree(struct BSTree *tree)
{
	clearBSTree(tree);
	free(tree);
}

/*----------------------------------------------------------------------------*/
/*
 function to determine if  a binary search tree is empty.

 param: tree    the binary search tree
 pre:  tree is not null
 */
int isEmptyBSTree(struct BSTree *tree) { return (tree->cnt == 0); }

/*
 function to determine the size of a binary search tree

param: tree    the binary search tree
pre:  tree is not null
*/
int sizeBSTree(struct BSTree *tree) { return tree->cnt; }

/*----------------------------------------------------------------------------*/
/*
 recursive helper function to add a node to the binary search tree.
 HINT: You have to use the compare() function to compare values.
 param:  cur	the current root node
		 val	the value to be added to the binary search tree
 pre:	val is not null
 */
struct Node *_addNode(struct Node *cur, TYPE val)
{
	/*write this*/

    struct Node *newNode;

    //x is for use in compare conditionals
    int x;

    //if the current node is NULL
    if(cur == NULL){
        //allocate space for a new node
        newNode = (struct Node *)malloc(sizeof(struct Node));
        // make sure that malloc was successful
        assert(newNode != NULL);
        //assign val to new node's value
        newNode->val = val;
        // make sure its pointers point to NULL
        newNode->left = newNode->right = NULL;
        //return the new node
        return newNode;
    }
    // if the current root node is not NULL then we keep moving down the tree
    else{
        //call compare function to determine what way to move
        x = compare(val, cur->val);
        //if the value of node is less than value of node we are inserting...
        if(x == -1){
            cur->left = _addNode(cur->left, val); // move down left
            return cur;
        }
        // otherwise move down to the right for insertion
        else{
            cur->right = _addNode(cur->right, val);
            return cur;
        }
    }
}

/*
 function to add a value to the binary search tree
 param: tree   the binary search tree
		val		the value to be added to the tree

 pre:	tree is not null
		val is not null
 pose:  tree size increased by 1
		tree now contains the value, val
 */
void addBSTree(struct BSTree *tree, TYPE val)
{
	tree->root = _addNode(tree->root, val);
	tree->cnt++;
}


/*
 function to determine if the binary search tree contains a particular element
 HINT: You have to use the compare() function to compare values.
 param:	tree	the binary search tree
		val		the value to search for in the tree
 pre:	tree is not null
		val is not null
 post:	none
 */

/*----------------------------------------------------------------------------*/
int containsBSTree(struct BSTree *tree, TYPE val)
{
	/*write this*/

    assert(tree != NULL);
    assert(val != NULL);

    //create a node for traversing and set it to the top (the root)
    struct Node *current = tree->root;
    int x; // for using compare

    //x is for using compare
    while(current != NULL){
        x = compare(val, current->val);
        //if compare returns 0, the values match
        if(x == 0){
            return 1; //return true
        }
        else {
            //if compare returns -1 then move left
            if(x == -1){
                current = current->left;
            }
            //if compare returns 1 then move right
            else {
                current = current->right;
            }
        }
    }
    //return false if you traverse the entire tree and the value has not been found
    return 0;
}

/*
 helper function to find the left most child of a node
 return the value of the left most child of cur
 param: cur		the current node
 pre:	cur is not null
 post: none
 */

/*----------------------------------------------------------------------------*/
TYPE _leftMost(struct Node *cur)
{
	/*write this*/

	assert(cur != NULL);

	//while you can still move left, move left
	while(cur->left != NULL){
        cur = cur->left;
	}

	//return the value of the new current leftmost node
	return cur->val;
}


/*
 recursive helper function to remove the left most child of a node
 HINT: this function returns cur if its left child is NOT NULL. Otherwise,
 it returns the right child of cur and free cur.

Note:  If you do this iteratively, the above hint does not apply.

 param: cur	the current node
 pre:	cur is not null
 post:	the left most node of cur is not in the tree
 */
/*----------------------------------------------------------------------------*/
struct Node *_removeLeftMost(struct Node *cur)
{
	/* Write this */

	assert(cur != NULL);

	//create a temp for removing purposes
	struct Node *tempNode;

	// If there is no left this is the left most so delete it and return its right
	if(cur->left == NULL){
        tempNode = cur->right;
        free(cur);
        return tempNode;
	}

      //	else recursive removal of left on the left node
	else {



/*		// Free the data first
#ifdef MEM_FIX
		assert(cur->val);
		free(cur->val);
#endif
		// Now free the node

*/		cur->left = _removeLeftMost(cur->left);


   return cur;
	}
}
/*
 recursive helper function to remove a node from the tree
 HINT: You have to use the compare() function to compare values.
 param:	cur	the current node
		val	the value to be removed from the tree
 pre:	val is in the tree
		cur is not null
		val is not null
 */
/*----------------------------------------------------------------------------*/
struct Node *_removeNode(struct Node *cur, TYPE val)
{
	/*write this*/

    if(compare(val, cur->val) == -1)
        cur->left = _removeNode(cur->left, val);
    else if(compare(val, cur->val) == 1)
        cur->right = _removeNode(cur->right, val);
    else
    {
        if (cur->left == 0 && cur->right == 0)
            return NULL;
        else if (cur->left == 0) {
            struct Node *retval = cur->right;
            free(cur);
            return retval;
        }
        else if (cur->right == 0) {
            struct Node *retval = cur->left;
            free(cur);
            return retval;
        }
        else {
            cur->val = _leftMost(cur->right);
            cur->right = _removeLeftMost(cur->right);
        }
    }
    return cur;
}
/*
 function to remove a value from the binary search tree
 param: tree   the binary search tree
		val		the value to be removed from the tree
 pre:	tree is not null
		val is not null
		val is in the tree
 pose:	tree size is reduced by 1
 */
void removeBSTree(struct BSTree *tree, TYPE val)
{
	if (containsBSTree(tree, val)) {
		tree->root = _removeNode(tree->root, val);
		tree->cnt--;
	}
}

/*----------------------------------------------------------------------------*/


#if 1
#include <stdio.h>

/*----------------------------------------------------------------------------*/
void printNode(struct Node *cur) {
	 if (cur == 0) return;
	 printf("(");
	 printNode(cur->left);
	 /*Call print_type which prints the value of the TYPE*/
	 print_type(cur->val);
	 printNode(cur->right);
	 printf(")");

}

void printTree(struct BSTree *tree) {
	if (tree == 0) return;
	printNode(tree->root);
}
/*----------------------------------------------------------------------------*/

#endif


#if 1
/*
function to built a Binary Search Tree (BST) by adding numbers in this specific order
the graph is empty to start: 50, 13, 110 , 10

*/
struct BSTree *buildBSTTree() {
    /*     50
         13  110
        10
    */
    struct BSTree *tree	= newBSTree();

	/*Create value of the type of data that you want to store*/
	struct data *myData1 = (struct data *) malloc(sizeof(struct data));
	struct data *myData2 = (struct data *) malloc(sizeof(struct data));
	struct data *myData3 = (struct data *) malloc(sizeof(struct data));
	struct data *myData4 = (struct data *) malloc(sizeof(struct data));

	myData1->number = 50;
	myData1->name = "rooty";
	myData2->number = 13;
	myData2->name = "lefty";
	myData3->number = 110;
	myData3->name = "righty";
	myData4->number = 10;
	myData4->name = "lefty of lefty";


	/*add the values to BST*/
	addBSTree(tree, myData1);
	addBSTree(tree, myData2);
	addBSTree(tree, myData3);
	addBSTree(tree, myData4);


    return tree;
}

/*
function to print the result of a test function
param: predicate:  the result of the test
       nameTestFunction : the name of the function that has been tested
	   message

*/
void printTestResult(int predicate, char *nameTestFunction, char *message){
	if (predicate)
	   printf("%s(): PASS %s\n",nameTestFunction, message);
    else
	   printf("%s(): FAIL %s\n",nameTestFunction, message);
}

/*
fucntion to test each node of the BST and their children

*/
void testAddNode() {
    struct BSTree *tree	= newBSTree();

#ifndef MEM_FIX
	struct data myData1,  myData2,  myData3,  myData4;
#else
	struct data *myData1 = (struct data *) malloc(sizeof(struct data));
	struct data *myData2 = (struct data *) malloc(sizeof(struct data));
	struct data *myData3 = (struct data *) malloc(sizeof(struct data));
	struct data *myData4 = (struct data *) malloc(sizeof(struct data));
#endif

	//check the root node
#ifndef MEM_FIX
	myData1.number = 50;
	myData1.name = "rooty";
    addBSTree(tree, &myData1);
	if (compare(tree->root->val, (TYPE *)&myData1) != 0) {
		printf("addNode() test: FAIL to insert 50 as root\n");
		return;
	}
#else
	myData1->number = 50;
	myData1->name = "rooty";
	addBSTree(tree, myData1);
	if (compare(tree->root->val, (TYPE *)myData1) != 0) {
		printf("addNode() test: FAIL to insert 50 as root\n");
		return;
	}
#endif
	//check the tree->cnt value after adding a node to the tree
    else if (tree->cnt != 1) {
        printf("addNode() test: FAIL to increase count when inserting 50 as root\n");
        return;
    }
    else printf("addNode() test: PASS when adding 50 as root\n");

#ifndef MEM_FIX
	myData2.number = 13;
	myData2.name = "lefty";
    addBSTree(tree, &myData2);

    //check the position of the second element that is added to the BST tree
    if (compare(tree->root->left->val, (TYPE *)&myData2) != 0) {
        printf("addNode() test: FAIL to insert 13 as left child of root\n");
        return;
    }
#else
	myData2->number = 13;
	myData2->name = "lefty";
	addBSTree(tree, myData2);

	//check the position of the second element that is added to the BST tree
	if (compare(tree->root->left->val, (TYPE *)myData2) != 0) {
		printf("addNode() test: FAIL to insert 13 as left child of root\n");
		return;
	}
#endif
    else if (tree->cnt != 2) {
        printf("addNode() test: FAIL to increase count when inserting 13 as left of root\n");
        return;
    }
    else printf("addNode() test: PASS when adding 13 as left of root\n");

#ifndef MEM_FIX
	myData3.number = 110;
	myData3.name = "righty";
    addBSTree(tree, &myData3);

    //check the position of the third element that is added to the BST tree
    if (compare(tree->root->right->val, (TYPE *) &myData3) != 0) {
        printf("addNode() test: FAIL to insert 110 as right child of root\n");
        return;
    }
#else
	myData3->number = 110;
	myData3->name = "righty";
	addBSTree(tree, myData3);

	//check the position of the third element that is added to the BST tree
	if (compare(tree->root->right->val, (TYPE *)myData3) != 0) {
		printf("addNode() test: FAIL to insert 110 as right child of root\n");
		return;
	}
#endif
	else if (tree->cnt != 3) {
        printf("addNode() test: FAIL to increase count when inserting 110 as right of root\n");
        return;
    }
    else printf("addNode() test: PASS when adding 110 as right of root\n");

#ifndef MEM_FIX
	myData4.number = 10;
	myData4.name = "righty of lefty";
	addBSTree(tree, &myData4);

	//check the position of the fourth element that is added to the BST tree
    if (compare(tree->root->left->left->val, (TYPE *) &myData4) != 0) {
        printf("addNode() test: FAIL to insert 10 as left child of left of root\n");
        return;
    }
#else
	myData4->number = 10;
	myData4->name = "righty of lefty";
	addBSTree(tree, myData4);

	//check the position of the fourth element that is added to the BST tree
	if (compare(tree->root->left->left->val, (TYPE *)myData4) != 0) {
		printf("addNode() test: FAIL to insert 10 as left child of left of root\n");
		return;
	}
#endif
    else if (tree->cnt != 4) {
        printf("addNode() test: FAIL to increase count when inserting 10 as left of left of root\n");
        return;
    }
    else printf("addNode() test: PASS when adding 10 as left of left of root\n");

#ifdef MEM_FIX
	deleteBSTree(tree);
#endif
}

/*
fucntion to test that the BST contains the elements that we added to it

*/
void testContainsBSTree() {
    struct BSTree *tree = buildBSTTree();

    struct data myData1,  myData2,  myData3,  myData4, myData5;


	myData1.number = 50;
	myData1.name = "rooty";
	myData2.number = 13;
	myData2.name = "lefty";
	myData3.number = 110;
	myData3.name = "righty";
	myData4.number = 10;
	myData4.name = "lefty of lefty";
    myData5.number = 111;
	myData5.name = "not in tree";

    printTestResult(containsBSTree(tree, &myData1), "containsBSTree", "when test containing 50 as root");

    printTestResult(containsBSTree(tree, &myData2), "containsBSTree", "when test containing 13 as left of root");

	printTestResult(containsBSTree(tree, &myData3), "containsBSTree", "when test containing 110 as right of root");

    printTestResult(containsBSTree(tree, &myData4), "containsBSTree", "when test containing 10 as left of left of root");

     //check containsBSTree fucntion when the tree does not contain a node
    printTestResult(!containsBSTree(tree, &myData5), "containsBSTree", "when test containing 111, which is not in the tree");

#ifdef MEM_FIX
	deleteBSTree(tree);
#endif
}

/*
fucntion to test the left_Most_element

*/
void testLeftMost() {
    struct BSTree *tree = buildBSTTree();

	struct data myData3, myData4;

	myData3.number = 110;
	myData3.name = "righty";
	myData4.number = 10;
	myData4.name = "lefty of lefty";

	printTestResult(compare(_leftMost(tree->root), &myData4) == 0, "_leftMost", "left most of root");

	printTestResult(compare(_leftMost(tree->root->left), &myData4) == 0, "_leftMost", "left most of left of root");

	printTestResult(compare(_leftMost(tree->root->left->left), &myData4) == 0, "_leftMost", "left most of left of left of root");

	printTestResult(compare(_leftMost(tree->root->right), &myData3) == 0, "_leftMost", "left most of right of root");

#ifdef MEM_FIX
	deleteBSTree(tree);
#endif
}

void testRemoveLeftMost() {
    struct BSTree *tree = buildBSTTree();
    struct Node *cur;

    cur = _removeLeftMost(tree->root);

	printTestResult(cur == tree->root, "_removeLeftMost", "removing leftmost of root 1st try");

    cur = _removeLeftMost(tree->root->right);
    printTestResult(cur == NULL, "_removeLeftMost", "removing leftmost of right of root 1st try");

#ifdef MEM_FIX
	tree->root->right = NULL;
#endif

 	cur = _removeLeftMost(tree->root);
    printTestResult(cur == tree->root, "_removeLeftMost", "removing leftmost of root 2st try");

#ifdef MEM_FIX
	deleteBSTree(tree);
#endif
}

void testRemoveNode() {
    struct BSTree *tree = buildBSTTree();
    struct Node *cur;

	struct data myData1,  myData2,  myData3,  myData4;

	myData1.number = 50;
	myData1.name = "rooty";
	myData2.number = 13;
	myData2.name = "lefty";
	myData3.number = 110;
	myData3.name = "righty";
	myData4.number = 10;
	myData4.name = "lefty of lefty";

#ifdef MEM_FIX
    tree->root = _removeNode(tree->root, &myData4);
#else
	_removeNode(tree->root, &myData4);
#endif
    printTestResult(compare(tree->root->val, &myData1) == 0 && tree->root->left->left == NULL, "_removeNode", "remove left of left of root 1st try");

#ifdef MEM_FIX
	tree->root = _removeNode(tree->root, &myData3);
#else
	_removeNode(tree->root, &myData3);
#endif
	 printTestResult(compare(tree->root->val, &myData1) == 0 && tree->root->right == NULL, "_removeNode", "remove right of root 2st try");

#ifdef MEM_FIX
	tree->root = _removeNode(tree->root, &myData2);
#else
	_removeNode(tree->root, &myData2);
#endif
	printTestResult(compare(tree->root->val, &myData1) == 0 && tree->root->left == 0, "_removeNode", "remove right of root 3st try");

    cur = _removeNode(tree->root, &myData1);
#ifdef MEM_FIX
	tree->root = cur;
#endif
    printTestResult(cur == NULL, "_removeNode", "remove right of root 4st try");

#ifdef MEM_FIX
	deleteBSTree(tree);
#endif
}

/*

Main function for testing different fucntions of the Assignment#4.

*/

int main(int argc, char *argv[]){

   //After implementing your code, please uncommnet the following calls to the test functions and test your code

    testAddNode();

	printf("\n");
   	testContainsBSTree();

	printf("\n");
    testLeftMost();

	printf("\n");
    testRemoveLeftMost();

	printf("\n");
    testRemoveNode();


	return 0;


}

#endif
