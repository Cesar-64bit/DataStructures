#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node {
	struct node *previous;
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
		new_node->previous = *head;
		new_node->next = *head;
	}
	else {
		struct node *search;
		search = *head;
		search->previous = new_node;
		while(search->next != *head)
			search = search->next;
		search->next = new_node;
		new_node->previous = search;	
		new_node->next = *head;
	}
}

void items(NODE *head) {
	struct node *search;
	search = *head;

	printf("right-left");
	while(search->next != *head) {
		printf("[%d]-", search->data);
		search = search->next;
	}

	printf("[%d]-", search->data);
	search = search->next;
	printf("[%d]", search->data);

	printf("\nleft-right");
	while(search->previous != *head) {
		printf("[%d]-", search->data);
		search = search->previous;
	}
	printf("[%d]-", search->data);
	search = search->previous;
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

	items(&head);

	return 0;
}