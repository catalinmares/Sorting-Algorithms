#include <iostream>
#include <algo.h>
#include <utils3.h>

using namespace std;

void treeSort(int *array, int N) {
	struct Node* root = NULL;

	insert(root, array[0]);

	for (int i = 1; i < N; i++) {
		insert(root, array[i]);
	}

	int i = 0;
	storeSorted(root, array, i);

	deallocateTree(root);
}