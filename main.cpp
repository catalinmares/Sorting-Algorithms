#include <iostream>
#include <fstream>
#include <string.h>
#include <algo.h>
#include <time.h>

using namespace std;

int main(int argc, char const *argv[])
{
	if (argc < 2) {
		cerr<<"Usage: "<<argv[0]<<" {0, 1, 2, 3, 4, 5}\n";

		return 1;
	}

	int N;
	clock_t start_t, end_t;
	double total_t;

	char inFile[11];
	strcpy(inFile, "in/test");
	strcat(inFile, argv[1]);
	strcat(inFile, ".in");

	ifstream in;
	in.open(inFile);


	in>>N;

	int* array = new int[N];

	for (int i = 0; i < N; i++) {
		in>>array[i];
	}

	in.close();

	#ifdef HEAP

	printf("Running test %s for HEAP SORT ................ ", argv[1]);
	start_t = clock();
	heapSort(array, N);
	end_t = clock();

	#elif COUNT

	printf("Running test %s for COUNTING SORT ................ ", argv[1]);
	start_t = clock();
	array = countingSort(array, N);
	end_t = clock();

	#elif TREE

	printf("Running test %s for TREE SORT ................ ", argv[1]);
	start_t = clock();
	treeSort(array, N);
	end_t = clock();

	#endif

	char outFile[12];
	strcpy(outFile, "out/test");
	strcat(outFile, argv[1]);
	strcat(outFile, ".out");

	ofstream out;
	out.open(outFile);

	for (int i = 0; i < N; i++) {
		out<<array[i]<<" ";
	}

	out<<"\n";
	out.close();

	char refFile[12];
	strcpy(refFile, "ref/test");
	strcat(refFile, argv[1]);
	strcat(refFile, ".ref");

	ifstream ref;
	ref.open(refFile);

	int* refArray = new int[N];

	for (int i = 0; i < N; i++) {
		ref>>refArray[i];

		if (refArray[i] != array[i]) {
			printf("FAILED\n");
			goto failed;
		}
	}

	printf("PASSED\n");

failed:
	total_t = (double) (end_t - start_t) / CLOCKS_PER_SEC;
	printf("A rulat in %f\n", total_t);
	ref.close();

	delete array;
	delete refArray;

	return 0;
}