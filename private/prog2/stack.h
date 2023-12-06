#define STACK_H
#include <stdio.h>
#include <stdbool.h>
#define MAX_LEN 100
#define EMPTY -1
#define FULL (MAX_LEN - 1)
typedef struct stack {
	char s[MAX_LEN];
	int top;
} stack;
void reset(stack *stk);
void push(char c, stack *stk);
char pop(stack *stk);
char top(const stack *stk);
bool empty(const stack *stk);
bool full(const stack *stk);
void playstack(char const* str);
