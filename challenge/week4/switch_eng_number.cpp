#include <iostream>
using namespace std;
int main()
{
    int number;
    cout << "숫자를 입력하시오:";
    cin >> number;
    switch (number)
    {
    case 0:
        cout << "zero" << endl;
        break;
    case 1:
        cout << "one" << endl;
        break;
    default:
        cout << "many" << endl;
    }
    return 0;
}