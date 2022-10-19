#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
	smaller = NULL;
	larger = NULL;
	if(head == NULL){
		return;
	}
	pivothelper(head, smaller, larger, pivot);
}

void pivothelper(Node *&head, Node *&smaller, Node *&larger, int pivot){
	if(head->next != NULL){
		pivothelper(head->next, smaller, larger, pivot);
	}
	if(head->val <= pivot){
		Node *tmps = smaller;
		smaller = head;
		smaller->next = tmps;
	}
	else{
		Node *tmpl = larger;
		larger = head;
		larger->next = tmpl;
	}
	head = NULL;
}