#include <stdio.h>

void mygets(char* input);

int main(void)
{

char input[100];

printf("문자열을 입력하세요 : ");

mygets(input); // mygets()로 대체

printf("입력 문자열 : ");

puts(input);
// printf("%s", input);
printf("입력 끝");

return 0;

}

void mygets(char* input)
{
    int i = 0;

    while (1)
    {
        input[i] = getchar();
        if(input[i] == '\n')
            break;
        i++;
    }
    input[i] = '\0';
}