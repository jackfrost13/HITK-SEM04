#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 100000
int cp = 0;
void swap (int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}
void print (int *A, int N) {
	int i;
	for (i = 0; i < N; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
}

void heapify (int *A, int N, int i) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < N && A[left] >= A[largest]) {
		largest = left;
	}
	if (right < N && A[right] >= A[largest]) {
		largest = right;
	}
	if (largest != i) {
		cp++;
		swap (&A[largest], &A[i]);
		heapify (A, N, largest);
	}
}

void build (int *A, int N) {
	int i;
	for (i = N/2; i >= 0; i--) {
		heapify (A, N, i);
	}
}
void heap_sort (int *A, int N) {
	int i;
	build (A, N);
	for (i = N - 1; i >= 1; i--) {
		swap (&A[0], &A[i]);
		heapify (A, i, 0);
	}
}
int main() {
	time_t start, stop;
	int *A = (int *) malloc (size * sizeof(int));
	int i = 0, value;
	int x;
	scanf ("%d", &x); 
	for (; i < size; i++) {
		scanf ("%d", &A[i]);
	}
	start = clock();
	heap_sort(A, size);
	stop = clock();
	print (A, size);
	
	double time_taken = (double) (stop - start) / CLOCKS_PER_SEC;
	printf ("Time Taken : %lf\n", time_taken);
	printf ("Comparisons : %d\n", cp);
	return 0;
}
