/*
 * Simple example of doubly-linked lists written in C.
 *
 * Author: Christopher W. Schankula
 * Last updated: December 19th, 2017
 * Code is licensed under the CC BY 4.0 license.
 *
 * THE CODE PROVIDED HEREIN IS PROVIDED "AS-IS"
 * THE AUTHOR ASSUMES NO RESPONSBILITY OR WARRANTY
 * FOR USE OF THE CODE PROVIDED HEREIN
 * EXTENSIVE TESTING OF THIS CODE IS REQUIRED
 * TO ENSURE ITS CORRECTNESS AS PART OF THE INTENDED
 * APPLICATION THEREOF
 */

struct dll_node {
	struct dll_node *prev;
	struct dll_node *next;
	int data;
};

typedef struct dll_node *DllNodePtr;

//creating new nodes
DllNodePtr create_dll(int a);
//adding elements
DllNodePtr cons_dll(DllNodePtr head, int a);
DllNodePtr snoc_dll(DllNodePtr head, int a);
DllNodePtr hconcat_dll(DllNodePtr head, int *A, int n);
DllNodePtr tconcat_dll(DllNodePtr head, int *A, int n);
//search for nodes
DllNodePtr search_dll(DllNodePtr head, int a);
DllNodePtr rsearch_dll(DllNodePtr tail, int a);
//delete nodes
DllNodePtr deleteNode_dll(DllNodePtr head, int n);
DllNodePtr rdeleteNode_dll(DllNodePtr tail, int n);
void free_dll(DllNodePtr head);
//insert new nodes in the middle
DllNodePtr insAfter_dll(DllNodePtr head, int a, int n);
DllNodePtr insBefore_dll(DllNodePtr head, int a, int n);
DllNodePtr rinsAfter_dll(DllNodePtr head, int a, int n);
DllNodePtr rinsBefore_dll(DllNodePtr head, int a, int n);
//head and tail
DllNodePtr head_dll(DllNodePtr tail);
DllNodePtr tail_dll(DllNodePtr head);
//printing
void print_dll(DllNodePtr head);
void rprint_dll(DllNodePtr tail);