#include <stdio.h>
#include <string.h>
int max (int a, int b) {return a > b ? a : b;}
int main() {
	int N, M;
	scanf ("%d %d", &N, &M);
	int price[N], weight[N], dp[N + 1][M + 1];
	for (int i = 0; i < N; i++) scanf ("%d", &price[i]);
	for (int i = 0; i < N; i++) scanf ("%d", &weight[i]);
	for (int i = 0; i <= N; i++) {
		for (int w = 0; w <= M; w++) {
			if (i == 0 || w == 0) dp[i][w] = 0;
			else if (weight[i - 1] <= w) dp[i][w] = max(dp[i - 1][w], price[i - 1] + dp[i - 1][w - weight[i - 1]]);
			else dp[i][w] = dp[i - 1][w];
		}
	}
	// for (int i = 0; i <= N; i++) {
	// 	for (int w = 0; w <= M; w++) {
	// 		printf ("%d ", dp[i][w]);
	// 	}
	// 	printf("\n");
	// }

	int res = dp[N][M];    
    printf("%d\n", res);     
    int w = M;
    for (int i = N; i > 0 && res > 0; i--) {
        if (res == dp[i - 1][w]) 
            continue;
        else {
            printf("%d %d\n", price[i - 1], weight[i - 1]);
            res = res - price[i - 1];
            w = w - weight[i - 1];
        }
    }
	return 0;
}
