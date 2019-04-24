#include <stdio.h>
#include <time.h>

int main() {
	FILE *fp;
	fp = fopen("ascending.txt", "w");
	fprintf(fp, "100000\n");
	int i;
	srand(time(NULL));
	for (i = 0; i < 100000; i++) {
		fprintf(fp, "%d\n", i + 1);
	}
	fclose(fp);
	return 0;
}
