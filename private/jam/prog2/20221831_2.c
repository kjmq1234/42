#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    int status;
    char schedule[500];
} t_day;

int isleapyear(int year);
void print_cal(int year, int month, t_day* days);
int manu(int year, int month, t_day* days);
void add_schedule(int year, int month, t_day* days);
void check_schdule(int year, int month, t_day* days);
void delete_schdule(int year, int month, t_day* days);

int main(void)
{
    int year, month;
    int month_of_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    t_day* days;
    int sig;

    printf("년을 입력하세요 : ");
    scanf("%d", &year);
    while (1)
    {
        printf("\n월을 입력하세요 : ");
        scanf("%d", &month);
        if ((month >= 1) && (month <= 12))
            break;
        else
            printf("잘못된 월을 입력했습니다. 1~12사이의 숫자를 입력해주세요.");
    }
    if (month == 2)
    {
        if (year % 400 == 0)
            days = (t_day*) malloc(month_of_days[month - 1] + 1 * sizeof(t_day));
        else if (year % 100 == 0)
            days = (t_day*) malloc(month_of_days[month - 1] * sizeof(t_day));
        else if (year % 4 == 0)
            days = (t_day*) malloc(month_of_days[month - 1] + 1 * sizeof(t_day));
        else
            days = (t_day*) malloc(month_of_days[month - 1] * sizeof(t_day));
    }
    else
        days = (t_day*) malloc(month_of_days[month - 1] * sizeof(t_day));
    for (int i = 0; i < month_of_days[month - 1]; i++)
        days[i].status = 0;
    while (1)
        if (!manu(year, month, days))
            break;
}

void print_cal(int year, int month, t_day* days)
{
    int month_of_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int week = 1;

    printf("\n\n");
    if (month == 2)
    {
        if (year % 400 == 0)
          month_of_days[1] += 1;
        else if (year % 100 == 0)
            month_of_days[1] += 0;
        else if (year % 4 == 0)
            month_of_days[1] += 1;
        else
            month_of_days[1] += 0;
    }

    week += (365 * (year - 1) + (year / 4) - (year / 100) + (year / 400));
    for (int i = 0; i < month; i++)
        week += month_of_days[i - 1];
    if (isleapyear(year) && ((month == 1) || (month == 2)))
        week -= 1;
    week %= 7;
    printf("                         %15d년 %d월\n\n", year, month);
    printf("                    Sun    Mon    Tue    Wed    Thu    Fri    Sat\n\n");
    printf("                    ");    
    for (int i = 0; i < 7; i++)
    {
        if (week != i)
            printf("       ");
        else
            break;
    }
    for (int i = 0; i < month_of_days[month - 1]; i++)
    {
        if (week == 7)
        {
            printf("\n\n");
            printf("                    ");    
            week -= 7;
        }
        if (days[i].status == 1)
        {
            if (i <= 10)
              printf(" *%-5d", i + 1);
            else
              printf(" *%-4d ", i + 1);
        }
        else
            printf(" %-6d", i + 1);
        week++;
    }
    printf("\n\n\n\n\n\n\n");
}

int manu(int year, int month, t_day* days)
{
    int sig;
    
    system("clear");    
    while (1)
    {
        print_cal(year, month, days);   
        printf("1. 일정 입력           2. 일정 삭제           3. 일정 확인           4. 종료\n\n");
        printf("메뉴를 입력하세요 : ");
        scanf("%d", &sig);
        switch (sig)
        {
            case 1:
                add_schedule(year, month, days);
                system("clear");    
                return (1);
            case 2:
                delete_schdule(year, month, days);
                return (1);
            case 3:
                check_schdule(year, month, days);
                return (1);
            case 4:
                printf("\n");
                return (0);
            default:
                printf("잘못된 숫자를 입력했습니다. 1~4사이의 숫자를 입력해주세요.\n");
        }
    }
}

void check_schdule(int year, int month, t_day* days)
{
    int day;
    char enter;

    printf("날짜를 입력하세요 : ");
    while (1)
    {
        scanf("%d", &day);
        if (day == 0)
            return ;
        else if (days[day - 1].status == 1)
            break;
        else
            printf("일정이 없습니다. 일정이 있는 날짜를 입력해주세요(일정 확인 종료: 0)\n");
    }
    printf("%d년 %d월 %d일 일정은 %s입니다.\n", year, month, day, days[day - 1].schedule);
    getchar();
    while (1)
    {
        scanf("%c", &enter);
        if (enter == '\n')
            break;
    }
}

void add_schedule(int year, int month, t_day* days)
{
    int day;

    printf("날짜를 입력하세요 : ");
    while (1)
    {
        scanf("%d", &day);
        if (day == 0)
            return ;
        else if (days[day - 1].status == 0)
            break;
        else
            printf("일정이 이미 있습니다. 일정이 없는 날짜를 입력해주세요(일정 추가 종료: 0)\n");
    }
    days[day - 1].status = 1;
    printf("일정을 입력하세요 : ");
    getchar();
    scanf("%[^\n\r]", days[day-1].schedule);
}

void delete_schdule(int year, int month, t_day* days)
{
    int day;

    printf("날짜를 입력하세요 : ");
    while (1)
    {
        scanf("%d", &day);
        if (day == 0)
            return ;
        else if (days[day - 1].status == 1)
            break;
        else
            printf("일정이 없습니다. 일정이 있는 날짜를 입력해주세요(일정 삭제 종료: 0)\n");
    }
    days[day - 1].status = 0;
}

int isleapyear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1;
    } else {
        return 0;
    }
}