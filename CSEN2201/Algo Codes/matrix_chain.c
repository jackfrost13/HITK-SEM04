#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
int x = 1;
void print(int i, int j, int n, int *br) {
	if (i == j) {
		printf ("%d", x++);
		return;
	}
	printf ("(");
	print(i, *((br + i * n) + j), n, br);
	print(*((br + i * n) + j) + 1, j, n, br);
	printf (")");
}

int main() {
	int i, l, j, k, N = 7, q;
	int p[] = {30, 35, 15, 5, 10, 20, 25};
	int m[N][N], br[N][N];
	memset (m, 0, sizeof (m));
	for (l = 2; l < N; l++) {
		for (i = 1; i < N - l + 1; i++) {
			j = i + l - 1;
			m[i][j] = INT_MAX;
			for (k = i; k <= j - 1; k++) {
				q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (q < m[i][j]) {
					m[i][j] = q;
					br[i][j] = k;
				}
			}
		}
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf ("%d ", m[i][j]);
		}
		printf ("\n");
	}
	printf ("%d\n", m[1][N - 1]);
	print (1, N - 1, N, (int *)br);
	return 0;
}
