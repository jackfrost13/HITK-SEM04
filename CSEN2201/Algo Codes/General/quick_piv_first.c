#include <stdio.h>
#include <time.h>

int partition (int *arr, int low, int high) {
	int pivot = arr[high], i = low - 1, j;
	for (j = low; j < high; j++) {
		if (arr[j] <= pivot) {
			i++;
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	int t = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = t;
	return i + 1;
}
void quick_sort(int *arr, int low, int high) {
	//printf("%d %d\n", low, high);
	if (low < high) {
		int pivot = partition(arr, low, high);
		quick_sort(arr, low, pivot - 1);
		quick_sort(arr, pivot + 1, high);
	}
}

int main() {
	int N;
	time_t start, stop;
	scanf("%d", &N);
	int arr[N], i;
	for (i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	start = clock();
	quick_sort(arr, 0, N - 1);
	stop = clock();
	printf("%lf\n", (double)(stop - start) / CLOCKS_PER_SEC);
	return 0;
}
