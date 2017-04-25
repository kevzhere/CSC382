#include <iostream>
#include <stdio.h>
#include <time.h>
using namespace std;

int Insertion(int A[], int n);
void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);

void main() {
	int n[] = { 10, 1000, 10000, 50000, 100000, 200000 };
	srand(time(NULL));
	/*int a[200000];
	for (int i = 0; i < 200000; i++) {
		a[i] = rand() % 2000;
	}*/
	printf("%6s%20s%20s", "Value", "Inserction Time", "Merge Time\n");
	for (int i = 0; i < 6; i++) {
		int *a = new int[n[i]];
		for (int j = 0; j < n[i]; j++) {
			a[j] = rand() % 2000;
		}
		time_t start, start2, end, end2;
		time(&start2);
		/*for (int k = 0; k < n[i]; k++) {
			cout << a[k] << " " ;
		}*/
		cout << endl;
		/*Insertion(a, n[i]);*/
		/*for (int k = 0; k < n[i]; k++) {
			cout << a[k] << " ";
		}*/
		time(&end2);
		time(&start);
		mergeSort(a, 0, n[i]-1);
		time(&end);
		printf("%6d%20ld%20ld\n", n[i], Insertion(a,n[i]-1), difftime(end, start));
	}
	/*cout << endl;
	merge_sort(a, 0, 50000);
	for (int i = 0; i < 50000; i++) {
		cout << a[i] << " ";
	}*/
	system("pause");
}


int Insertion(int A[], int n) // in reality the elements to be sorted are indexed from
							  // index 1 to index n
{
	time_t start, end;
	time(&start);
	int i, j, temp;
	//A[0] = -32768; //smallest possible integer using 2 bytes integer representation
	for (i = 1; i <= n; i++) {
		j = i;
		while (A[j] < A[j - 1]) { // swap 
			temp = A[j];
			A[j] = A[j - 1];
			A[j - 1] = temp;
			j--;
		}
	}
	time(&end);
	return difftime(end, start);
}

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	int *L = new int[n1], *R = new int[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; 
	j = 0; 
	k = l; 
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	are any */
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		// Same as (l+r)/2, but avoids overflow for
		// large l and h
		int m = l + (r - l) / 2;

		// Sort first and second halves
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}