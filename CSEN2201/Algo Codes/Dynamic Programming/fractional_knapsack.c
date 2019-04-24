#include <stdio.h>
#include <string.h>
typedef struct ele {
	int weight, profit, index;
	double ratio;
} obj;

int main() {
	int N, M, i, j, curr_wt = 0;
	scanf ("%d %d", &N, &M);
	obj objects[N];
	double percent[N], profit = 0;
	memset (percent, 0, sizeof (percent));
	for (i = 0; i < N; i++) scanf ("%d", &objects[i].profit);
	for (i = 0; i < N; i++) {
		scanf ("%d", &objects[i].weight);
		objects[i].index = i;
		objects[i].ratio = (double) objects[i].profit / objects[i].weight;
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < N - 1; j++) {
			if (objects[j].ratio < objects[j + 1].ratio) {
				obj temp = objects[j];
				objects[j] = objects[j + 1];
				objects[j + 1] = temp;
			}
		}
	}
	for (i = 0; i < N; i++) {
		if (curr_wt + objects[i].weight <= M) {
			curr_wt += objects[i].weight;
			profit += objects[i].profit;
			percent[objects[i].index] = 1; 
		} else {
			profit += objects[i].ratio * (M - curr_wt);
			percent[objects[i].index] = (double) (M - curr_wt) / (objects[i].weight);
			curr_wt = M;
			break; 
		}
	}
	for (i = 0; i < N; i++)
		printf ("%lf ", objects[i].ratio);
	printf ("\n");
	printf ("Maximum Profit : %lf\n", profit);
	printf ("Fractions : \n");
	for (i = 0; i < N; i++)
		printf ("%lf ", percent[i]);
	printf ("\n");
	return 0;
}
