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

int main(){
	DllNodePtr list = create_dll(5);
	list = cons_dll(list, 4);
	list = snoc_dll(list, 6);

	print_dll(list);
	rprint_dll(tail_dll(list));

	int B[3] = {3,2,1};
	list = hconcat_dll(list, B, 3);

	print_dll(list);
	rprint_dll(tail_dll(list));

	int C[3] = {7,8,9};
	list = tconcat_dll(list, C, 3);

	print_dll(list);
	rprint_dll(tail_dll(list));

	print_dll(search_dll(list, 5));
	rprint_dll(tail_dll(search_dll(list, 5)));

	list = insAfter_dll(list, 4, 5);
	list = insAfter_dll(list, 7, 9);
	list = insAfter_dll(list, 7, 7);
	print_dll(list);

	list = insBefore_dll(list, 3, 1);
	print_dll(list);

	list = rinsBefore_dll(tail_dll(list), 12, 7);
	print_dll(list);

	list = deleteNode_dll(list, 12);
	print_dll(list);

	list = rdeleteNode_dll(tail_dll(list), 3);
	list = deleteNode_dll(list, 3);
	print_dll(list);

	free_dll(list);

	return 0;
}