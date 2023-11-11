#include <iostream>
using namespace std;

void divide(int const num1, int const num2, int &de, int &dr);

int main(void){
int num1, num2; // 나누는 수, 나눠지는 수
int de, dr; // 몫, 나머지

cout<<"피 연산자 두 개를 입력하세요 : ";
cin >> num1 >> num2;

try{
    divide(num1, num2, de, dr);
    cout<<"몫은 "<<de<<", 나머지는 "<<dr<<"입니다.\n";
}

catch (int){
    cout<<"잘못된 입력 값입니다.\n";
}
}

void divide(int const num1, int const num2, int &de, int &dr){
    if (num2==0)
        throw 0;
    de = num1/num2;
    dr = num1%num2;
}