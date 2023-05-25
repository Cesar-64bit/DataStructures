#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node {
	int data;
	struct node *next;
};

typedef struct node *NODE;

void insert(NODE *head, int data) {
	struct node *new_node;
	new_node = (struct node*)malloc(sizeof(struct node));

	new_node->data = data;
	new_node->next = NULL;

	if(*head == NULL)
		*head = new_node;
	else {
		struct node *search;
		search = *head;
		while(search->next != NULL)
			search = search->next;
		search->next = new_node;
	}
 }

void remove(NODE *head, int data) {
	struct node *search;
	struct node *prev;
	search = *head;

	/*Delete first element in the list*/
	if(data == search->data && search == *head) {
		prev = *head;
		*head = search->next;
		free(prev);
	}
	/*Delete a middle element or last element*/
	else {
		do {
			prev = search;
			search = search->next;
			if(data == search->data) {
				prev->next = search->next;
				free(search);
				break;
			}
		}while(search->next!=NULL);
	}
}

 void items(NODE *head) {
 	struct node *search;
 	search = *head;

 	while(search->next != NULL) {
 		printf("[%d]-", search->data);
 		search = search->next;
 	}
 	printf("[%d]", search->data);
 }

int main(void) {
	NODE head = NULL;

	insert(&head, 1);
	insert(&head, 2);
	insert(&head, 3);
	insert(&head, 4);
	insert(&head, 5);
	insert(&head, 6);
	insert(&head, 7);
	insert(&head, 8);

	remove(&head, 1);
	remove(&head, 3);
	remove(&head, 8);


	items(&head);

	return 0;
}