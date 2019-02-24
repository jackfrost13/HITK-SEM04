#include <stdio.h>
#include <limits.h>

int N, heap_size = -1;
void swap (int *a, int *b) {int temp = *b; * b = * a; *a = temp;}

void min_heapify(int A[], int i) {
	int smallest, left = 2 * i + 1, right = 2 * i + 2;
	if (left <= heap_size && A[left] < A[i]) 	smallest = left;
	else 		smallest = i;
	if (right <= heap_size && A[right] < A[smallest]) 	smallest = right;
	if (smallest != i) {
		swap (&A[smallest], &A[i]);
		min_heapify (A, smallest);
	}
}
void decrease (int A[], int i, int key) {
	A[i] = key;
	while (i > 0 && A[(i - 1) / 2] > A[i]) {
		swap (&A[(i - 1) / 2], &A[i]);
		i = (i - 1) / 2;
	}
}

void enque (int A[], int key) {
	heap_size++;
	A[heap_size] = INT_MAX;
	decrease (A, heap_size, key);
}
int extract_min(int A[]) {
	int min = A[0];
	swap (&A[0], &A[heap_size]);
	heap_size--;
	min_heapify(A, 0);
	return min;
}

int main() {
	int i, key, j;
	int A[100], choice;
	while (1) {
		printf ("1.Enque\n");
		printf ("2.Extract_min\n");
		printf ("3.Print Min\n");
		printf ("4.Exit\n");
		scanf ("%d", &choice);
		if (choice == 1) {
			scanf ("%d", &key);
			enque (A, key);
		} else if (choice == 2) {
			printf ("%d extracted\n", extract_min(A));
		} else if (choice == 3) {
			printf ("%d\n", A[0]);
		} else {
			return 0;
		}
	}
	return 0;
}
