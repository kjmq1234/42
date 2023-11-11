#include <iostream>

int main(void){
    int num, total=0;
    for (int i=1; i<6; i++){
        
        std::cout<<i<<"번째 점수 입력: ";
        std::cin>>num;
        total+=num;
    }
    std::cout<<"합계: "<<total;
}