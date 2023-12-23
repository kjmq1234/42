#include <stdio.h>
#include <stdlib.h>

typedef int index;
void knapsack (index i, int profit, int weight);
int promising (index i, int weight, int profit);
int compare(const void* one, const void* two);
typedef struct {
    int w;
    int p;
} info;
int n, W, maxprofit = 0, numbest;
int *include, *bestset;
info *object;

int main(void)  
{    
    scanf("%d %d", &n, &W);
    object= (info*) malloc(sizeof(info) * (n + 1));
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &object[i].p);
        scanf("%d", &object[i].w);
    }
    qsort(object, n + 1, sizeof(info), compare);
    include = (int*) malloc(sizeof(int) * (n + 1));
    bestset = (int*) malloc(sizeof(int) * n);
    knapsack(0, 0, 0);
    for (int i = 0; i < n; i++)
    {
        if (bestset[i])
            printf("YES ");
        else
            printf("NO ");            
    }
}

void knapsack (index i, int profit, int weight)
{
    if ((weight <= W) && (profit > maxprofit))
    {
        maxprofit = profit;
        numbest = i;
        for (int j = 1; j <= n; j++)
            bestset[j - 1] = include[j];
    }
    if (promising(i, weight, profit))
    {
        include[i + 1] = 1;
        knapsack(i + 1, profit + object[i + 1].p, weight + object[i+1].w);
        include[i + 1] = 0;
        knapsack(i + 1, profit, weight);
    }
}

int promising (index i, int weight, int profit)
{
    index j, k;
    int totweight;
    float bound;

    if (weight >= W)
        return (0);
    else
    {
        j = i + 1;
        bound = profit;
        totweight = weight;
        while ((j <= n) && (totweight + object[j].w <= W))
        {
            totweight = totweight + object[j].w;
            bound = bound +object[j].p;
            j++;
        }
        k = j;
        if (k <= n)
            bound = bound + ((W-totweight) * object[k].p/object[k].w);
        return (bound > maxprofit);
    }
}

int compare(const void* one, const void* two)
{
    info a = *((info*)one);
    info b = *((info*)two);

    float ratioA = (float)a.p / a.w;
    float ratioB = (float)b.p / b.w;

    return (ratioB - ratioA);
}