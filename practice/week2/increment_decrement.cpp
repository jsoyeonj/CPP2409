#include <iostream>

using namespace std;
int main()
{
    int x = 1;
    cout << "x =" << x++ << endl;
    cout << "x =" << x++ << endl;
    cout << "x =" << ++x << endl;
    cout << "x =" << x-- << endl;
    cout << "x =" << x-- << endl;
    cout << "x =" << --x << endl;

    return 0;
}