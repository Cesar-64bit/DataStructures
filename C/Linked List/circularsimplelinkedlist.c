#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

typedef struct node *NODE;

void insert(NODE *head, int data) {
	struct node *new_node;
	new_node = (struct node*)malloc(sizeof(struct node));

	new_node->data = data;

	if(*head == NULL) {
		*head = new_node;
		new_node->next = new_node;
	}
	else {
		struct node *search;
		search = *head;
		while(search->next != *head)
			search = search->next;
		search->next = new_node;
		new_node->next = *head;		
	}
}

void remove(NODE *head, int data) {
	struct node *search;
	struct node *prev;
	search = *head;

	
	
}

void items(NODE *head) {
	struct node *search;
	search = *head;
	while(search->next != *head) {
		printf("[%d]-", search->data);
		search = search->next;
	}
	printf("[%d]-", search->data);
	search = search->next;
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

	remove(&head, 8);
	/*remove(&head, 3);
	remove(&head, 8);*/

	items(&head);

	return 0;
}