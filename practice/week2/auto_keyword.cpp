#include <iostream>
using namespace std; // PI가 기호 상수
auto add(int x, int y)
{
    return x + y;
}
int main()
{
    auto sum = add(5, 6);
    cout << sum;
    return 0;
}