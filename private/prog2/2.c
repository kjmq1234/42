#include <stdio.h>
<<<<<<< HEAD
#include <stdlib.h>
#include <string.h>
#define N 10

struct linked_list {
	char d;
	struct linked_list *next;
};

typedef struct linked_list ELEMENT;
typedef ELEMENT *LINK;

LINK string_to_list(char s[]) {
	LINK new;
    LINK head;
    LINK first;
    int i = 0;

	if (s[0] == '\0')
		return NULL;
	head = malloc(sizeof(ELEMENT));
    head->d = s[i++];
    first = head;
    while(1) {
		new = malloc(sizeof(ELEMENT));
        head->next=new;
        head = head->next;
		head->d = s[i++];
	     if (s[i] == '\0')
		    return first;
    }
}

void print_list(LINK head) {
	if (head == NULL)
		printf("NULL \n");
	else {
		printf("%c --> ", head -> d);
		print_list(head -> next);
	}
}

int main(void) {
	char input[N];
	LINK h;
    while (1)
    {
        printf("문자열 입력: ");
        scanf("%s", input);
        if (strncmp(input, "exit", 4) == 0)
        {
            printf("\nBYE......");
            exit(1);
        }
        h = string_to_list(input);
        printf("변환 리스트 결과 : \n");
    	print_list(h);
        printf("\n\n");
    }
    return 0;
=======
#define print_age(x) printf(#x" : %d\n", age_##x)

int main(void)
{
    int a= 3;
    print_age();
>>>>>>> 300cf9824974ad20bc970d200961779b86516856
}