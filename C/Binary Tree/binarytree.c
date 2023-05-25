#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node {
	struct node *left;
	int data;
	struct node *right;
};

typedef struct node *NODE;

void insert_node(NODE *root, int data, struct node *new_node) {
	struct node *current;
	current = *root;

	if(data < current->data) {
		if(current->left == NULL)
			current->left = new_node;
		else
			insert_node(&current->left, data, new_node);
	}
	else if(data > current->data) {
		if(current->right == NULL)
			current->right = new_node;
		else
			insert_node(&current->right, data, new_node);
	}
}

void create_node(NODE *root, int data) {
	struct node *new_node;
	new_node = (struct node*)malloc(sizeof(struct node));

	new_node->left = NULL;
	new_node->data = data;
	new_node->right = NULL;

	if(*root == NULL)
		*root = new_node;
	else
		insert_node(root, data, new_node);
}

// root->left->right
void preorder(NODE *root) {
	if(*root != NULL) {
		struct node *current;
		current = *root;

		printf("[%d]", current->data);
		preorder(&current->left);
		preorder(&current->right);
	}
}

// left->rigth->root
void postorder(NODE *root) {
	if(*root != NULL) {
		struct node *current;
		current = *root;

		postorder(&current->left);
		postorder(&current->right);
		printf("[%d]", current->data);
	}
}

// left->root->right
void inorder(NODE *root) {
	if(*root != NULL) {
		struct node *current;
		current = *root;

		inorder(&current->left);
		printf("[%d]", current->data);
		inorder(&current->right);
	}
}

int main(void) {
	NODE root = NULL;

	create_node(&root, 3);
	create_node(&root, 1);
	create_node(&root, 8);
	create_node(&root, 7);

	printf("preorder: ");
	preorder(&root);
	printf("\npostorder: ");
	postorder(&root);
	printf("\ninorder: ");
	inorder(&root);
	return 0;
}