#define INF 999999
#include <stdio.h>
#include <stdlib.h>
void floyd2(int n, int** W, int** D, int** P);
void path(int** P, int q, int r);
void print(int** W, int** D, int** P, int n);
void free_all(int n, int** W, int** D, int** P);

int	main(void)
{
	int	n;
	int** W;
	int** D;
	int** P;

	scanf("%d", &n);
	W = (int**)calloc(n, sizeof(int*));
	D = (int**)calloc(n, sizeof(int*));
	P = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		W[i] = (int*)calloc(n, sizeof(int));
		D[i] = (int*)calloc(n, sizeof(int));
		P[i] = (int*)malloc(n * sizeof(int));
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &W[i][j]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if ((i != j) && (W[i][j] == 0))
				W[i][j] = INF;
	floyd2(n, W, D, P);
	print(W, D, P, n);
	free_all(n, W, D, P);
}

void floyd2(int n, int** W, int** D, int** P)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			D[i][j] = W[i][j];
			P[i][j] = -1;
		}
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (D[i][j] > D[i][k] + D[k][j])
				{
					P[i][j] = k;
					D[i][j] = D[i][k] + D[k][j];
				}
}

void path(int** P, int q, int r)
{
	if (P[q][r] != -1)
	{
		path(P, q, P[q][r]);
		printf("V%d ", P[q][r] + 1);
		path(P, P[q][r], r);
	}
}

void print(int** W, int** D, int** P, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (D[i][j] != INF)
				printf("%2d ", D[i][j]);
			else
				printf("0 ");
		}	
		printf("\n");
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (P[i][j] != -1)
			{
				printf("%d ", i + 1);
				path(P, i, j);
				printf("%d\n", j + 1);
			}
			else
				printf("0 \n");
		}
	}
}

void free_all(int n, int** W, int** D, int** P)
{
	for (int i = 0; i < n; i++)
		free(W[i]);
	free(W);
	for (int i = 0; i < n; i++)
	{
		free(P[i]);
		free(D[i]);
	}
	free(P);
	free(D);
}