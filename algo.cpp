#include <iostream>
#include <algo.h>
#include <utils1.h>

using namespace std;

void heapSort(int *array, int N) {
	buildHeap(array, N);

	for (int i = N - 1; i > 0; i--) {
		swap(array[0], array[N - 1]);
		N--;
		heapifyDown(array, 0, N);
	}
}