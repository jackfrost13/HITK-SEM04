#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int counter = 0;
int partition (int *arr, int low, int high) {
	int mid = low + rand() % (high - low + 1);
	int zz = arr[mid];
	arr[mid] = arr[low];
	arr[low] = zz;
	int pivot = arr[low], i = high, j;
	for (j = high; j > low; j--) {
		counter++;
		if (arr[j] >= pivot) {
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i--;
		}
	}
	int t = arr[i];
	arr[i] = arr[low];
	arr[low] = t;
	return i;
}
void quick_sort(int *arr, int low, int high) {
	//printf("%d %d\n", low, high);
	//counter++;
	if (low < high) {
		int pivot = partition(arr, low, high);
		quick_sort(arr, low, pivot - 1);
		quick_sort(arr, pivot + 1, high);
	}
}

int main() {
    freopen("temp.txt", "r", stdin);
	srand(time(NULL));
	int arr[10], i, j;
	for (i = 0; i < 3628800; i++) {
		for (j = 0; j < 10; j++) {
			scanf("%d", &arr[j]);
		}
		quick_sort(arr, 0, 9);
		/*for (j = 0; j < 10; j++)
			printf("%d ", arr[j]);
		printf("\n");*/
		if (i == 0) {
			for (int j = 0; j < 10; j++)
				printf ("%d ", arr[j]);
			printf("\n");
		}
	}
	printf("%lf\n", (double)counter / 3628800);
	return 0;
}
