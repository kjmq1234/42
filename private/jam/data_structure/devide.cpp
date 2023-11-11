#include <iostream>

using namespace std;

void divide(int a, int b, int& quotient, int& remainder);

int main() {
    int a, b, quotient, remainder;
    cout << "피연산자 두 개를 입력하세요: ";
    cin >> a >> b;

    try {
        divide(a, b, quotient, remainder);
        cout << "몫은 " << quotient << ", 나머지는 " << remainder << "입니다." << endl;
    }
    catch (invalid_argument& e) {
        cout << "잘못된 입력값입니다." << endl;
    }

    return 0;
}

void divide(int a, int b, int& quotient, int& remainder) {
    if (b == 0) {
        throw invalid_argument("Division by zero");
    }
    quotient = a / b;
    remainder = a % b;
}
