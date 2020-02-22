#include <iostream>
#include <string.h>
#include <algo.h>

using namespace std;

int* countingSort(int *array, int N) {
	int max = array[0];
	int min = array[0];

	for (int i = 1; i < N; i++) {
		if (max < array[i]) {
			max = array[i];
		}

		if (min > array[i]) {
			min = array[i];
		}
	}

	int range = max - min + 1;
	int* counts = new int[range];
	memset(counts, 0, range * sizeof(int));

	for (int i = 0; i < N; i++) {
		counts[array[i] - min]++;
	}

	for (int i = 1; i < range; i++) {
        counts[i] += counts[i - 1];
	}

	int* sorted = new int[N];

	for (int i = 0; i < N; i++) {
		sorted[counts[array[i] - min] - 1] = array[i];
		counts[array[i] - min]--;
	}

	return sorted;
}