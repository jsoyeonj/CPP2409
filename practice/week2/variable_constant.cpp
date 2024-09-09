#include <iostream>
#define PI 3.14159265359
using namespace std; // PI가 기호 상수
int main()
{
    int income = 1000;            // 1000이 리터럴 상수
    const double TAX_RATE = 0.25; // TAX_RATE가 상수변수
    income = income - TAX_RATE * income;

    double x = 100;
    x = x * PI;

    cout << x << endl;
    return 0;
}