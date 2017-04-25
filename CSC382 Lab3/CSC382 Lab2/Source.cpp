//Ding Zhu CSC382 Lab#3
#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;


int Insertion(int A[], int n) // in reality the elements to be sorted are indexed from
							   // index 1 to index n
{
	int i, j, temp, steps =0;
	A[0] = -32768; //smallest possible integer using 2 bytes integer representation
	for (i = 1; i <= n; i++) {
		j = i;
		 while (A[j] < A[j - 1]) { // swap 
			temp = A[j];
			A[j] = A[j - 1];
			A[j - 1] = temp;
			j--;
			steps++;
		}
	}
	return steps;
}

float sequence(bool real, int n, int repeat, int bound) {
	int *A = new int[n];
	int hits = 0;
	float totalSteps = 0;
	for (int k = 0; k < repeat; k++) {
		for (int i = 0; i < n; i++) {
			A[i] = rand() % (2 * bound) - bound;
		}
			int z = Insertion(A, n);
				totalSteps += z;
	}
		return totalSteps/repeat;
}
void main() {
	int bound = 1000;
	int hits = 0;
	int repeat = 10000;
	int steps;
	float cAverage, rAverage;
	srand(time(NULL));

	printf("%s%25s%25s", "Input Size", "Calculated Average", "Real Average\n");
	int n[] = { 100, 500, 1000, 2500, 3000, 3500 };
	for (int i = 0; i < 6; i++) {
		rAverage = sequence(true, n[i], repeat, bound);
		cAverage = (float)((n[i]*n[i]) / 4) + (.75 *n[i]);
		printf("%10d%25.3f%25.3f\n", n[i], cAverage, rAverage);
	}

system("pause");
}