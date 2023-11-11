#include <stdio.h>
int pbo(int);

int main(void)
{
    int result, a;
    
    scanf("%d", &a);
    result = pbo(a);
    printf("%d", result);
}

int pbo(int n)
{
    if (n<=1)
        return n;
    else
        return (pbo(n-1) + pbo(n-2));



}