#include <iostream>

using namespace std;
int main()
{
    double C, F;
    // 입력받기
    cout << "화씨온도: ";
    cin >> F;

    // 계산
    C = (5.0 / 9.0) * (F - 32);
    // 출력
    cout << "섭씨온도: " << C << endl;

    return 0;
}