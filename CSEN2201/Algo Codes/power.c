#include <stdio.h>
int iterations = 1;
int power_n (int x, int n) {
	int ans = x, temp = n;
	while (n > 1) {
		iterations++;
		ans = x * ans;
		n--;
	}
	return ans;
}
int iter = 0;
int power_logn (int x, int n) {
	printf("iter : %d, n : %d\n", iter, n);
	iter++;
	if (n == 0)	return 1;
	if (n % 2 == 0) {
		return power_logn(x * x, n / 2);
	} else {
		return x * power_logn(x * x, (n - 1) / 2);
	}
}

int main() {
	int x, n;
	printf("Enter the value of x and n : \n");
	scanf("%d %d", &x, &n);
	if (power_n(x - 1, n) > power_n(x, n)) {
		printf("OVERFLOW!\n");
		return 0;
	}
	printf("%d ^ %d = %d\n", x, n, power_n (x, n));
	printf("Number of iterations : %d\n", iterations);
	if (power_logn(x - 1, n) > power_logn(x, n)) {
		printf("OVERFLOW!\n");
		return 0;
	}
	printf("%d ^ %d = %d\n", x, n, power_logn(x, n));
	printf("Number of iterations : %d\n", iter);
	return 0;
}
