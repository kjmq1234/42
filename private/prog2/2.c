#include <stdio.h>
#define print_age(x) printf(#x" : %d\n", age_##x)

int main(void)
{
    int a= 3;
    print_age();
}