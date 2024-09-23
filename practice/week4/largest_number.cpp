#include <iostream>
using namespace std;
int main()
{
    int a, b, c, largest;
    cout << "3개의 정수를 입력하시오: ";
    cin >> a >> b >> c;
    if (a > b && a > c)
        largest = a;
    else if (b > a && b > c)
        largest = b;
    else if (b == a && b > c) // a랑 b가 같을수 있기 때문에 b랑a가 같고 b보다c가 클 조건을 넣는다.
        largest = a;
    else
        largest = c;
    cout << "가장 큰 정수는" << largest << endl;
    return 0;
}