#include <iostream>
using namespace std;
int main()
{
    int number = 10;
    // 변수 number의 주소를 계산하여 p에 저장한다.
    int *p = &number;
    // p가 가리키는 공간에 저장된 값을 출력한다.
    cout << *p << endl;
    return 0;
}
