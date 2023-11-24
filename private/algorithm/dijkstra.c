#include <stdio.h>
#include <stdlib.h>

#define INF 99999999
typedef int index;
typedef int number;

typedef struct
{
    int dest;
    int src;
    int weight;
} edge;

typedef edge* set_of_edges;

set_of_edges F;

void daijkstra(int n, const number** W);

int main(void)
{
    int n, m;
    number dest, src, weight;
    number** W;

    scanf("%d %d", &n, &m);
    W = (number**)calloc(n + 1, sizeof(number*));
    for (number i = 0; i <= n; i++)
        W[i] = (number*)calloc(n + 1, sizeof(number));

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &src, &dest, &weight);
        W[src][dest] = weight;
    }

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            if (W[i][j] == 0 && i != j)
                W[i][j] = INF;

    const number** w = (const number**)W;
    daijkstra(n, w);

    for (int i = 0; i < n - 1; i++)
        printf("v%d -> v%d: %d\n", F[i].src, F[i].dest, F[i].weight);

    for (int i = 0; i <= n; i++)
        free(W[i]);
    free(W);
    free(F);

    return 0;
}

void daijkstra(int n, const number** W)
{
    index vnear;
    index* touch;
    number* length;
    int min, cnt = 0;

    touch = (index*)malloc(sizeof(index) * (n + 1));
    length = (number*)malloc(sizeof(number) * (n + 1));

    F = (set_of_edges)calloc(n - 1, sizeof(edge));
    for (int i = 2; i <= n; i++)
    {
        touch[i] = 1;
        length[i] = W[1][i];
    }

    for (int j = 0; j < n - 1; j++)
    {
        min = INF;
        for (int i = 2; i <= n; i++)
        {
            if ((0 <= length[i]) && (length[i] < min))
            {
                min = length[i];
                vnear = i;
            }
        }
        F[cnt].dest = vnear;
        F[cnt].src = touch[vnear];
        F[cnt++].weight = (int)W[touch[vnear]][vnear];
        for (int k = 2; k <= n; k++)
        {
            if (length[vnear] + W[vnear][k] < length[k])
            {
                length[k] = length[vnear] + W[vnear][k];
                touch[k] = vnear;
            }
        }
        length[vnear] = -1;
    }

    free(touch);
    free(length);
}
