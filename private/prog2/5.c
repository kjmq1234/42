#include <stdio.h>

int main(void)
{
    char a = 0xff;

short b = 0xffff;

int c = 0xffffffff;

long long d = 0xffffffffff;


printf("%hhx\n", a);
printf("%hx\n", b);
printf("%x\n", c);
printf("%llx", d);
}