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

#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked.h"

DllNodePtr create_dll(int n){
	DllNodePtr head = malloc(sizeof(struct dll_node));
	head->prev = NULL;
	head->next = NULL;
	head->data = n;
	return head;
}

DllNodePtr cons_dll(DllNodePtr head, int a){
	DllNodePtr new_node = malloc(sizeof(struct dll_node));
	new_node->prev = NULL;
	new_node->next = head;
	new_node->data = a;
	head->prev = new_node;
	return new_node;
}

DllNodePtr snoc_dll(DllNodePtr head, int a){
	if (head->next == NULL){
		DllNodePtr new_node = malloc(sizeof(struct dll_node));
		new_node->prev = head;
		new_node->next = NULL;
		new_node->data = a;
		head->next = new_node;
	}else{
		snoc_dll(head->next, a);
	}

	return head;
}

DllNodePtr hconcat_dll(DllNodePtr head, int *A, int n){
	for(int i = 0; i < n; i++){
		head = cons_dll(head, *(A+i));
	}
	return head;
}

DllNodePtr tconcat_dll(DllNodePtr head, int *A, int n){
	for(int i = 0; i < n; i++){
		head = snoc_dll(head, *(A+i));
	}
	return head;
}

DllNodePtr insAfter_dll(DllNodePtr head, int a, int n){
	DllNodePtr nodeN = search_dll(head, n);

	if (nodeN == NULL){
		fprintf(stderr, "Error: Node with data %d does not exist.\n", n);
		return NULL;
	}else{
		DllNodePtr new_node = malloc(sizeof(struct dll_node));
		//set up new_node
		new_node->next = nodeN->next;
		new_node->prev = nodeN;
		new_node->data = a;
		//edit the one after existing
		if (nodeN->next)
			nodeN->next->prev = new_node;
		//edit existing node
		nodeN->next = new_node;
	}
	return head;
}

DllNodePtr insBefore_dll(DllNodePtr head, int a, int n){
	DllNodePtr nodeN = search_dll(head, n);
	DllNodePtr new_node;

	if (nodeN == NULL){
		fprintf(stderr, "Error: Node with data %d does not exist.\n", n);
		return NULL;
	}else{
		new_node = malloc(sizeof(struct dll_node));
		//set up new_node
		new_node->next = nodeN;
		new_node->prev = nodeN->prev;
		new_node->data = a;
		//edit the one after existing
		if (nodeN->prev)
			nodeN->prev->next = new_node;
		//edit existing node
		nodeN->prev = new_node;
	}
	if (new_node->prev)
		return head;
	else
		return new_node;
}

DllNodePtr rinsAfter_dll(DllNodePtr tail, int a, int n){
	DllNodePtr nodeN = rsearch_dll(tail, n);

	if (nodeN == NULL){
		fprintf(stderr, "Error: Node with data %d does not exist.\n", n);
		return NULL;
	}else{
		DllNodePtr new_node = malloc(sizeof(struct dll_node));
		//set up new_node
		new_node->next = nodeN->next;
		new_node->prev = nodeN;
		new_node->data = a;
		//edit the one after existing
		if (nodeN->next)
			nodeN->next->prev = new_node;
		//edit existing node
		nodeN->next = new_node;
	}
	return head_dll(tail);
}

DllNodePtr rinsBefore_dll(DllNodePtr tail, int a, int n){
	DllNodePtr nodeN = rsearch_dll(tail, n);
	DllNodePtr new_node;

	if (nodeN == NULL){
		fprintf(stderr, "Error: Node with data %d does not exist.\n", n);
		return NULL;
	}else{
		new_node = malloc(sizeof(struct dll_node));
		//set up new_node
		new_node->next = nodeN;
		new_node->prev = nodeN->prev;
		new_node->data = a;
		//edit the one after existing
		if (nodeN->prev)
			nodeN->prev->next = new_node;
		//edit existing node
		nodeN->prev = new_node;
	}
	if (new_node->prev)
		return head_dll(tail);
	else
		return new_node;
}

DllNodePtr search_dll(DllNodePtr head, int a){
	if (head == NULL)
		return NULL;
	if (head->data == a)
		return head;
	else{
		return search_dll(head->next, a);
	}
}

DllNodePtr rsearch_dll(DllNodePtr tail, int a){
	if (tail == NULL)
		return NULL;
	if (tail->data == a)
		return tail;
	else{
		return rsearch_dll(tail->prev, a);
	}
}

DllNodePtr deleteNode_dll(DllNodePtr head, int n){
	DllNodePtr nodeN = search_dll(head, n);

	if (!nodeN){
		fprintf(stderr, "Error: Node with data %d does not exist.\n", n);
		return NULL;
	}
	DllNodePtr next;
	if (nodeN->next)
		nodeN->next->prev = nodeN->prev;
	if (nodeN->prev)
		nodeN->prev->next = nodeN->next;
	if (!(nodeN->prev)){
		next = nodeN->next;
		free(nodeN);
		return next;
	}
	free(nodeN);
	return head;
}

DllNodePtr rdeleteNode_dll(DllNodePtr tail, int n){
	DllNodePtr nodeN = rsearch_dll(tail, n);

	if (!nodeN){
		fprintf(stderr, "Error: Node with data %d does not exist.\n", n);
		return NULL;
	}
	DllNodePtr next;
	if (nodeN->next)
		nodeN->next->prev = nodeN->prev;
	if (nodeN->prev)
		nodeN->prev->next = nodeN->next;
	if (!(nodeN->prev)){
		next = nodeN->next;
		free(nodeN);
		return next;
	}
	free(nodeN);
	return head_dll(tail);
}

void free_dll(DllNodePtr head){
	if (head){
		free_dll(head->next);
		free(head);
	}
}

DllNodePtr head_dll(DllNodePtr tail){
	if (!(tail->prev)){
		return tail;
	}else{
		return head_dll(tail->prev);
	}
}

DllNodePtr tail_dll(DllNodePtr head){
	if (!(head->next)){
		return head;
	}else{
		return tail_dll(head->next);
	}
}

void print_dll(DllNodePtr head){
	do {
		printf("%d ", head->data);
	} while((head = head->next));
	printf("\n");
}

void rprint_dll(DllNodePtr tail){
	do {
		printf("%d ", tail->data);
	} while((tail = tail->prev));
	printf("\n");
}