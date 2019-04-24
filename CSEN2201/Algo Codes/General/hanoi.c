#include <stdio.h>

int count = 0;
void hanoi (int x, char A, char B, char C) {
	count++;
	if (x == 1) {
		printf("moving disc %d from %c to %c\n", x, A, B);
	}
	else {
		hanoi (x - 1, A, B, C);
		printf("moving disc %d from A to C\n", x);
		hanoi (x - 1, B, C, A);
	}
}

int main() {
	int N;
	printf("Enter number of disks : ");
	scanf("%d", &N);
	hanoi (N, 'A', 'B', 'C');
	printf("Number of steps : %d\n", count);
}
