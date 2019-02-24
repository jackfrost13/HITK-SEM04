#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void computeLPSArray(char *pat, int M, int *lps);

void KMPSearch(char *pat, char *txt)
{
	int M = strlen(pat);
	int N = strlen(txt);

	// create lps[] that will hold the longest prefix suffix
	// values for pattern
	int *lps = (int *)malloc(sizeof(int)*M);
	int j = 0; // index for pat[]

	// Preprocess the pattern (calculate lps[] array)
	computeLPSArray(pat, M, lps);

	int i = 0; // index for txt[]
	int flag =0;
	while (i < N)
	{
        if (pat[j] == txt[i])//pattern is found
        {
            j++;
            i++;
        }

        if (j == M)
        {
            flag=1;
            printf("Found pattern at index %d \n", i-j);
            j = lps[j-1];
        }

        // mismatch after j matches
        else if (i < N && pat[j] != txt[i])
        {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j-1];
            else
                i = i+1;
        }
	}
	if(flag==0){
        printf("Pattern not found\n");
	}
	free(lps); // to avoid memory leak
}

void computeLPSArray(char *pat, int M, int *lps)//makes the array for the pattern. searches the pattern linearly and makes the array
{
	int len = 0; // length of the previous longest prefix suffix
	int i,j;

	lps[0] = 0; 
	i = 1;
	while (i < M)
	{
	if (pat[i] == pat[len])
	{
		len++;
		lps[i] = len;
		
		i++;
	}
	else 
	{
		if (len != 0)
		{
            len = lps[len-1];

		
		}
		else 
		{
            lps[i] = 0;
            i++;
		}
		
	}
	
	}
	for(j=0;j<i;j++)
			printf("%d ",lps[j]);
		printf("\n");
}
int main()
{
    char txt[100],pat[100];
	printf("Enter the text:\n");
	scanf("%s",txt);
	printf("Enter the pattern:\n");
	scanf("%s",pat);
    KMPSearch(pat, txt);
    return 0;
}

