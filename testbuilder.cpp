#include <fstream>
#include <math.h>
#define N0 100000
#define N1 1000
#define N2 10
#define N3 10000
#define N4 1000
#define N5 100000
#define N6 5000

using namespace std;

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

void test0() {
	ofstream out, ref;
	out.open("in/test0.in");
	ref.open("ref/test0.ref");
	out<<N0<<"\n";

	for (int i = 0; i < N0; i++) {
		out<<"2018 ";
		ref<<"2018 ";
	}

	out<<"\n";
	ref<<"\n";

	out.close();
	ref.close();
}

void test1() {
	ofstream out, ref;
	out.open("in/test1.in");
	ref.open("ref/test1.ref");
	out<<N1<<"\n";

	for (int i = 0; i < N1; i++) {
		out<<pow(i, 2)<<" ";
		ref<<pow(i, 2)<<" ";
	}

	out<<"\n";
	ref<<"\n";

	out.close();
	ref.close();
}

void test2() {
	ofstream out;
	out.open("in/test2.in");
	out<<N2<<"\n";

	int array[] = {0, -354663, 6756443, 4535, 332423, 239, 5843432, -245677334, 68791, -43234};

	for (int i = 0; i < N2; i++) {
		out<<array[i]<<" ";
	}

	out<<"\n";
	out.close();

	ofstream ref;
	ref.open("ref/test2.ref");

	qsort(array, N2, sizeof(int), compare);

	for (int i = 0; i < N2; i++) {
		ref<<array[i]<<" ";
	}

	ref<<"\n";
	ref.close();
}

void test3() {
	ofstream out, ref;
	out.open("in/test3.in");
	ref.open("ref/test3.ref");
	out<<N3<<"\n";

	int* array = new int[N3];

	for (int i = 1; i <= N3; i++) {
		out<<i<<" ";
		ref<<i<<" ";
	}

	out<<"\n";
	ref<<"\n";

	out.close();
	ref.close();

	delete array;
}

void test4() {
	ofstream out;
	out.open("in/test4.in");
	out<<N4<<"\n";

	int* array = new int[N4];

	for (int i = N4; i >= 1; i--) {
		array[i - 1] = pow(i, 2);
		out<<array[i - 1]<<" ";
	}

	out<<"\n";
	out.close();

	qsort(array, N4, sizeof(int), compare);

	ofstream ref;
	ref.open("ref/test4.ref");

	for (int i = 0; i < N4; i++) {
		ref<<array[i]<<" ";
	}

	ref<<"\n";
	ref.close();

	delete array;
}

void test5() {
	ofstream out;
	out.open("in/test5.in");
	out<<N5<<"\n";

	int* array = new int[N5];

	for (int i = 0; i < N5; i++) {
		array[i] = rand() % 100000 + 1;
		out<<array[i]<<" ";
	}

	out<<"\n";
	out.close();

	qsort(array, N5, sizeof(int), compare);

	ofstream ref;
	ref.open("ref/test5.ref");

	for (int i = 0; i < N5; i++) {
		ref<<array[i]<<" ";
	}

	ref<<"\n";
	ref.close();

	delete array;
}

void test6() {
	ofstream out;
	out.open("in/test6.in");
	out<<N6<<"\n";

	int* array = new int[N6];

	for (int i = 0; i < N6; i++) {
		if (i < 500 || (i > 3000 && i < 3500) || i > 4500) {
			array[i] = i;
		} else {
			array[i] = rand() % 10000 + 1;
		}

		out<<array[i]<<" ";
	}

	out<<"\n";
	out.close();

	qsort(array, N6, sizeof(int), compare);

	ofstream ref;
	ref.open("ref/test6.ref");

	for (int i = 0; i < N6; i++) {
		ref<<array[i]<<" ";
	}

	ref<<"\n";
	ref.close();

	delete array;
}

int main(int argc, char const *argv[])
{
	test0();
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();

	return 0;
}