#include <stdio.h>
#include <stdlib.h>
#define size 10
void swap (int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}
void backtrack (int *a, int left, int right) {
	if (left == right) {
		int i = 0;
		for (; i < size; i++) {
			printf ("%d ", a[i]);
		}
		printf ("\n");
		return;
	}
	int i;
	for (i = left; i < right; i++) {
		swap (&a[left], &a[i]);
		backtrack (a, left + 1, right);
		swap (&a[left], &a[i]);
	}
}
int main() {
	int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	backtrack(a, 0, 10);
	return 0;
}
