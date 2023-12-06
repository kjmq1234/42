#include "stack.h"

void playstack(char const* str)
{
	stack s;

	reset(&s); // 스택 초기화
	printf("문자열 : %s\n", str);
	// 스택에 문자열 push
	for (int i = 0; str[i] != '\0'; ++i)
		if (!full(&s))
			push(str[i], &s);
	printf("역 문자열 : ");
	// 스택에서 문자열 pop
	while (!empty(&s))
		putchar(pop(&s));
	putchar('\n');
}

void reset(stack *stk){
	stk -> top = EMPTY;
}
void push(char c, stack *stk){
	stk -> top++;
	stk -> s[stk -> top] = c;
}
char pop(stack *stk){
	return (stk -> s[stk -> top--]);
}
char top(const stack *stk){
	return (stk -> s[stk -> top]);
}
bool empty(const stack *stk){
	return (stk -> top == EMPTY);
}
bool full(const stack *stk){
	return (stk -> top == FULL);
}
