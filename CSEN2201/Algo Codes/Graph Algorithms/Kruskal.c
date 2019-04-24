#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
typedef struct edg {
	int val, first, second;
} edge;
int cmp (const void *x, const void *y) {
	edge *X = (edge *) x;
	edge *Y = (edge *) y;
	return (X -> val - Y -> val);
}
int A[MAX + 1], rank[MAX + 1];
void MAKE_SET(int N) {
	int i;
	for (i = 1; i <= N; i++) {
		A[i] = i;
		rank[i] = 0;
	}
	
}
int FIND(int s) {
	if (A[s] != s)	return A[s] = FIND(A[s]);
	return A[s];
}
void LINK (int s, int f) {
	if (rank[s] > rank[f])	A[f] = A[s];
	else {
		A[s] = A[f];
		if (rank[s] == rank[f])	rank[f]++;
	}
}
void UNION (int s, int f) {
	LINK(FIND(s), FIND(f));
}
int main() {
	int N, i, j, c = 0;
	scanf ("%d", &N);
	edge E[N];
	int EDGE[N + 1][N + 1];
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			scanf ("%d", &EDGE[i][j]);
			if (j > i && EDGE[i][j] != -1) {
				E[c].val = EDGE[i][j];
				E[c].first = i;
				E[c].second = j;
				c++;
			}
		}
	}
	for (i = 0; i < c; i++) {
		printf ("%d -> (%d, %d)\n", E[i].val, E[i].first, E[i].second);
	}
	printf ("\n");
	qsort (E, c, sizeof (edge), cmp);
	for (i = 0; i < c; i++) {
		printf ("%d -> (%d, %d)\n", E[i].val, E[i].first, E[i].second);
	}
	printf ("\n");
	MAKE_SET(N + 1);
	int MST = 0;
	for (i = 0; i < c; i++) {
		if (FIND(E[i].first) != FIND(E[i].second)) {
			MST += E[i].val;
			printf ("%d %d\n", E[i].first, E[i].second);
			UNION(E[i].first, E[i].second);
		}
	}
	printf ("Value of MST is : %d\n", MST);
	return 0;
}
