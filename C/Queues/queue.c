#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node {
	int data;
	struct node *next;
};

typedef struct node *NODE;

void enqueue(NODE *tail, int data) {
	struct node *newNode;
	newNode = (struct node*)malloc(sizeof(struct node));

	newNode->data = data;
	newNode->next = NULL;

	if(*tail == NULL) {
		*tail = newNode;
	} else {
		struct node *aux;
		aux = *tail;
		while(aux->next != NULL) {
			aux = aux->next;
		}
		aux->next = newNode;
	}
}

void dequeue(NODE *tail) {
	struct node *aux;
	aux = *tail;

	*tail = aux->next;
	free(aux);
}

void display(NODE *tail) {
	struct node *aux;
	aux = *tail;

	while(aux->next != NULL) {
		printf("[%d]-", aux->data);
		aux = aux->next;
	}

	printf("[%d]", aux->data);
}

int main(void) {
	NODE tail = NULL;

	enqueue(&tail, 1);
	enqueue(&tail, 2);
	enqueue(&tail, 3);

	dequeue(&tail);

	display(&tail);

	return 0;
}