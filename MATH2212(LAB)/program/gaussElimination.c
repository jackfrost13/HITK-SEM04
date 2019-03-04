#include <stdio.h>
  int main() {
    int n, i, j, k;
    float a[50][50], x[50], d, sum = 0.0;
    printf("\nEnter the no. of unknowns:");
    scanf("%d", & n);
    printf("\nEnter the value of augmented matrix: ");
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= (n + 1); j++)
        scanf("%f", & a[i][j]);
    }
    printf("\nAugmented matrix : ");
    for (i = 1; i <= n; i++) {
      printf(" \n");
      for (j = 1; j <= (n + 1); j++)
        printf(" %f", a[i][j]);
    }
    for (k = 1; k <= (n - 1); k++) {
      for (i = (k + 1); i <= n; i++) {
        d = a[i][k] / a[k][k];
        for (j = 1; j <= (n + 1); j++)
          a[i][j] = a[i][j] - (d * a[k][j]);
      }
    }
    printf(" \nUpper triangular matrix: ");
    for (i = 1; i <= n; i++) {
      printf("\n");
      for (j = 1; j <= (n + 1); j++)
        printf(" %f", a[i][j]);
    }
    x[n] = a[n][n + 1] / a[n][n];
    printf(" \n%f was unknown no. %d", x[n], n);
    for (i = (n - 1); i >= 1; i--) {
      for (j = (i + 1); j <= n; j++) {
        sum = sum + (a[i][j] * x[j]);
      }

      x[i] = (a[i][n + 1] - sum) / a[i][i];
      sum = 0.0;
      printf("\n%f was unknown no.%d", x[i], i);
    }
  }
