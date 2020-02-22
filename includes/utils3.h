#include <iostream>

using namespace std;

typedef struct Node {
	int elem;
	struct Node *left, *right;
} TNode;

void insert(TNode* &root, int elem)
{
	if (root== NULL) {
		root = new struct Node;
		root-> elem = elem;
		root->left = root->right = NULL;

		return;
	}

	if (elem < root->elem) {
		insert(root->left, elem);
	} else {
		insert(root->right, elem);
	}
}

void storeSorted(TNode *root, int *array, int &i) {
	if (root != NULL) {
		storeSorted(root->left, array, i);
		array[i] = root->elem;
		i++;
		storeSorted(root->right, array, i); 
	}
}

void deallocateTree(TNode *root) {
	if (root == NULL) {
		return;
	}

	deallocateTree(root->left);
	deallocateTree(root->right);

	free(root);
}

void inorder(TNode *root) {
	if (root == NULL) {
		return;
	}

	inorder(root->left);
	printf("%d ", root->elem);
	inorder(root->right);
}