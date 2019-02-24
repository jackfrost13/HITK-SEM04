#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void precomp (int m, char pat[m], int lps[m]) {
	int j = 0, len = 0, i = 1;
	lps[0] = 0;
	while (i < m) {
		if (pat[i] == pat[len]) {
			len ++;
			lps[i] = len;
			i++;
		} else {
			if (len != 0) 	len = lps[len - 1];
			else {lps[i] = 0; i++;}
		}
	}
}
void kmp (int n, int m, char txt[n], char pat[m]) {
	int lps[m];
	precomp (m, pat, lps);
	int i = 0, j = 0, f = 0;
	while (i < n) {
		if (pat[j] == txt[i]) {
			j++;
			i++;
		}
		if (j == m) {
			printf ("Pattern occurs in the text at position %d\n", i - j);
			f = 1;
			j = lps[j - 1];
		} else if (i < n && pat[j] != txt[i]) {
			if (j != 0) 	j = lps[j - 1];
			else 		i += 1;
		}
	}
	if (f == 0)	printf ("Pattern not found in the text!\n");
}

int main() {
	int n, m;
	//printf ("Enter the length of the text : ");
	scanf ("%d", &n);
	//printf ("Enter the length of the pattern : ");
	scanf ("%d", &m);
	char *txt = (char *) malloc(n * sizeof (char));
	char *pat = (char *) malloc(m * sizeof (char));
	//printf ("Enter the text : ");
	scanf ("%s", txt);
	//printf ("Enter the pattern : ");
	scanf ("%s", pat);
	kmp (n, m, txt, pat);
}
