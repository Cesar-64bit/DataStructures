#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node {
	int data;
	struct node *next;
};

typedef struct node *NODE;

void push(NODE *top, int data) {
	struct node* newNode;
	newNode = (struct node*)malloc(sizeof(struct node));

	newNode->data = data;
	newNode->next = *top;
	*top = newNode;
}

void pop(NODE *top) {
	struct node *aux;
	aux = *top;

	*top = aux->next; 
	free(aux);
}

void items(NODE *top) {
	struct node *aux;
	aux = *top;

	while(aux->next != NULL) {
		printf("[%d]-", aux->data);
		aux = aux->next;
	}

	printf("[%d]", aux->data);
}

int main(void) {
	NODE top = NULL;

	push(&top, 1);
	push(&top, 2);
	push(&top, 3);

	pop(&top);

	items(&top);

	return 0;
}