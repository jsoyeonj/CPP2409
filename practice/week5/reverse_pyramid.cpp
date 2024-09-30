#include <iostream>
using namespace std;

int main()
{
    int floor;
    cout << "몇 층을 쌓겠습니까? (5~100):";
    cin >> floor;
    for (int i = 0; i < floor; i++) // 층이 올라가는 방식
    {
        for (int j = 0; j < floor - 1 - i; j++) // 왼쪽 빈 공간을 'S'로 채움
        {
            cout << "S";
        }
        for (int k = 0; k < i * 2 - 1; k++) // '*'를 출력하는 부분
        {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
