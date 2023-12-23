#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handler(int sig)
{
	printf("%d번 신호가 발생했습니다.", sig);
	exit(1);
}

int main(){
	int i, j;
	int sig;
	signal(2, handler);
	signal(4, handler);
	signal(8, handler);
	signal(9, handler);
	signal(11, handler);
	signal(14, handler);
	scanf("%d", &j);
	i = 7 / j;

	printf("%d", i);
	return 0;
}
