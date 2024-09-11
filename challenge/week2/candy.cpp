#include <iostream>

using namespace std;
int main()
{ // 입력받기
    int money, candy;
    cout << "가지고 있는 돈을 입력하세요:";
    cin >> money;
    cout << "캔디의 가격을 입력하세요:";
    cin >> candy;
    // 계산
    int max = money / candy;
    int left_money = money % candy;
    // 출력
    cout << "현재 가지고 있는 돈: " << money << endl;
    cout << "캔디의 가격: " << candy << endl;
    cout << "최대로 살 수 있는 캔디= " << max << endl;
    cout << "캔디 구입 후 남은 돈= " << left_money << endl;

    return 0;
}