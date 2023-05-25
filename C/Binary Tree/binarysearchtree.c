#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node {
	int key;
	struct node *left;
	struct node *right;
};

typedef struct node *NODE;

void insert_node(NODE *root, struct node *new_node, int key) {
	struct node *current;
	current = *root;

	if(key < current->key) {
		if(current->left == NULL)
			current->left = new_node;
		else
			insert_node(&current->left, new_node, key);
	}
	else if(key > current->key){
		if(current->right == NULL)
			current->right = new_node;
		else
			insert_node(&current->right, new_node, key);
	}
}

void create_node(NODE *root, int key) {
	struct node *new_node;
	new_node = (struct node*)malloc(sizeof(struct node));

	new_node->key = key;
	new_node->left = NULL;
	new_node->right = NULL;

	if(*root == NULL)
		*root = new_node;
	else
		insert_node(root, new_node, key);
}

// search a especific item
struct node *search(NODE *root, int key) {
	struct node *current;
	current = *root;

	if(current == NULL)
		return current;
	if(key == current->key)
		return current;
	else {
		if(key < current->key)
			return search(&current->left, key);
		else
			return search(&current->right, key);
	}
}

// return the minimun item on the tree
int minimum(NODE *root) {
	struct node *current;
	current = *root;

	if(current->left == NULL)
		return current->key;
		
	minimum(&current->left);
}

// return the maximun item on the tree
int maximum(NODE *root) {
	struct node *current;
	current = *root;

	if(current->right == NULL)
		return current->key;
		
	maximum(&current->right);
}

int successor(NODE *root) {
	struct node *current;
	current = *root;

	if(current->right != NULL)
		return minimum(&current->right);
}

int predecessor(NODE *root) {
	struct node *current;
	current = *root;

	if(current->left != NULL)
		return maximum(&current->left);
}

int main(void) {
	NODE root = NULL;

	create_node(&root, 15);
	create_node(&root, 18);
	create_node(&root, 6);
	create_node(&root, 3);
	create_node(&root, 7);
	create_node(&root, 17);
	create_node(&root, 20);
	create_node(&root, 2);
	create_node(&root, 4);
	create_node(&root, 13);
	create_node(&root, 9);

	struct node *address = search(&root, 13);

	if(address != NULL)
		printf("Data found");
	else
		printf("Data not found");

	printf("\nminimum: %d", minimum(&root));
	printf("\nmaximum: %d", maximum(&root));
	printf("\nsuccesor: %d", successor(&root));
	printf("\npredecessor: %d", predecessor(&root));

	return 0;
}