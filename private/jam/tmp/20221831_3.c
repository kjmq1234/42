#include <stdio.h>
#include <string.h>
#define SIZE 20
void upsort(char name[][9], unsigned long long num[], int grade[], int size);
void downsort(char [][9], unsigned long long num[], int [], int size);
void name_sort(char name[][9], unsigned long long num[], int grade[], int size);
int find(char name[][9], unsigned long long num[], int grade[], int size);
void name_sort(char name[SIZE][9], unsigned long long num[SIZE], int grade[SIZE], int size);

int main(void)
{   
    int num, stu;
    char info_head[3][6] = {"이름", "학번", "점수"};
    char info_name[SIZE][9] ={ "Aiden",    "Amelia", "Aria",    "Ava",    "Caden",    "David",    "Elijah",    "Emma",    "Grayson",    "Isabella",    "Jackson",    "Liam",    "Lucas",    "Mateo",    "Mia",    "Noah",    "Oliver",    "Olivia",    "Riley",    "Sophia"};
    unsigned long long info_number[SIZE] = {20220018,20220005,20220020,20220009,20220019,20220006,20220017,20220015,20220003,20220014,20220004,20220008,20220013,20220011,20220016,20220012,20220007,20220010,20220002,20220001};
    int info_grade[SIZE] = {78,79,84,82,68,76,83,77,92,93,99,80,71,95,90,89,72,96,88,98};

     while (1)
    {
        printf("%d 이름 오름차순 출력   %d 학번 오름차순 출력\n",1,2);
        printf("%d 점수 내림차순 출력   %d 이름 검색\n",3,4);
        printf("%d 종료\n\n", 5);
        printf("번호를 선택하세요 : ");
        scanf("%d", &num);
    switch (num)
    {
    case 1:   
        name_sort(info_name, info_number, info_grade, SIZE);

        printf("\n이름\t  학번\t    점수\t");

        printf("\n");

        for (int i = 0; i<SIZE; i++)
        {
            printf("%-10s", info_name[i]); 
            printf("%lld  ", info_number[i]);
            printf("%d\n", info_grade[i]);    
        }
        printf("\n");
        break;       

    case 2: 
        upsort(info_name, info_number, info_grade, SIZE);
        printf("\n이름\t  학번\t    점수\t");
        printf("\n");

        for (int i = 0; i<SIZE; i++)
        {
            printf("%-10s", info_name[i]); 
            printf("%lld  ", info_number[i]);
            printf("%d\n", info_grade[i]);    
        }
        printf("\n");

        break;

    case 3:  
        downsort(info_name, info_number, info_grade, SIZE);
        
        printf("\n이름\t   학번\t     점수\t");
        printf("\n");

        for (int i = 0; i<SIZE; i++)
        {
            printf("%-10s", info_name[SIZE-i-1]);
            printf(" %lld  %d\n", info_number[SIZE-i-1], info_grade[SIZE-i-1]);
        }
        printf("\n");

        break;

    case 4:  
        stu = find(info_name, info_number, info_grade, SIZE);
        
        if (stu==100)
            break;
        printf("\n이름\t   학번\t     점수\t");
        printf("\n");
        
        printf("%-10s %-10lld %-10d\n",info_name[stu], info_number[stu], info_grade[stu]);
        printf("\n");
        break;

    case 5:
        return 0;
    }

    }
}

void upsort(char name[SIZE][9], unsigned long long num[], int grade[], int size)
{
    int tmp, tmp_1;
    char tmp_2[size][8];
    for (int j = 0; j<size; j++)
    {   
        for (int i = 0; i<size-j; i++)
        {
            if (num[size-i] < num[size-i-1])
            {
                tmp = num[size-i];
                num[size-i] = num[size-i-1];
                num[size-i-1] = tmp;
                
                tmp_1 = grade[size - i];
                grade[size-i] = grade[size-i-1];
                grade[size-i-1] = tmp_1;
            for (int l = 0; l<8; l++)
            {
                tmp_2[size-i][l] = name[size-i][l];
                name[size-i][l] = name[size-i-1][l];
                name[size-i-1][l] = tmp_2[size-i][l];
                    
            }
            }
        }
    }
}    


void downsort(char name[SIZE][9], unsigned long long num[SIZE], int grade[SIZE], int size)
{
    int tmp, tmp_1;
    char tmp_2[8];
    for (int j = 0; j<size; j++)
    {   
        for (int i = 0; i<size-j; i++)
        {
            
            if (grade[size-i] < grade[size-i-1])
            {
                tmp = grade[size-i];
                grade[size-i] = grade[size-i-1];
                grade[size-i-1] = tmp;
                
                tmp_1 = num[size - i];
                num[size-i] = num[size-i-1];
                num[size-i-1] = tmp_1;    
                for (int l = 0; l<8; l++)
                {
                    tmp_2[8] = name[size-i][l];
                    name[size-i][l] = name[size-i-1][l];
                    name[size-i-1][l] = tmp_2[8];
                }
            }
        }
    }            
}

int find(char name[SIZE][9], unsigned long long num[SIZE], int grade[SIZE], int size)
{
    char find_name[8];
    int stu, j=0, i=0;

    printf("이름을 입력하세요 : ");
    scanf("%s", find_name);
    printf("\n");
    for (int i=0; i<size; i++) 
    {
        if (strcmp(find_name, name[i])==0)
        {
            stu = i;
            return stu;
        }
    }
    printf("없는 이름입니다.\n\n");
    stu = 100;
    return stu;
}

void name_sort(char name[SIZE][9], unsigned long long num[SIZE], int grade[SIZE], int size)
{
    int tmp, tmp_1;
    char temp[9];

    for (int j = 0; j<size; j++)
    {   
        for (int i = 0; i<size-j; i++)
        {
            if (strcmp(name[size-i], name[size-i-1])<0)
            {
                tmp = num[size-i];
                num[size-i] = num[size-i-1];
                num[size-i-1] = tmp;
                
                tmp_1 = grade[size - i];
                grade[size-i] = grade[size-i-1];
                grade[size-i-1] = tmp_1;

                strcpy(temp,name[size-i]);
                strcpy(name[size-i], name[size-i-1]);
                strcpy(name[size-i-1], temp); 
            }
        }
    }
}
