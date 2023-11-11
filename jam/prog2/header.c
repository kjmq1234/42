#include "headerfile.h"
#ifdef PI
#undef PI
#define PI 3.141592
#endif

int main(void)
{
    printf("%lf", PI);
}