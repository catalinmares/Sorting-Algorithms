#include <iostream>

using namespace std;

int getLeftChild(int index) {
	return 2 * index + 1;
}

int getRightChild(int index) {
	return 2 * index + 2;
}

void swap(int &a, int &b) {
	int x = a;
	a = b;
	b = x;
}

void heapifyDown(int *array, int index, int N) {
	int leftChild = getLeftChild(index);
	int rightChild = getRightChild(index);
	int maxIndex = 0;

	if (leftChild < N && array[leftChild] > array[index]) {
		maxIndex = leftChild;
	} else {
		maxIndex = index;
	}

	if (rightChild < N && array[rightChild] > array[maxIndex]) {
		maxIndex = rightChild;
	}

	if (maxIndex != index) {
		swap(array[maxIndex], array[index]);
		heapifyDown(array, maxIndex, N);
	}
}

void buildHeap(int *array, int N) {
	for (int i = N / 2 - 1; i >= 0; i--) {
		heapifyDown(array, i, N);
	}
}