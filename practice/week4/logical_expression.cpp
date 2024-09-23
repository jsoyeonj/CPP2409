#include <iostream>
using namespace std;
int main()
{
    bool b;

    b = (1 && 2);
    cout << "1&&2 = " << b << endl;

    b = (1 && 0);
    cout << "1&&0 = " << b << endl;

    b = (0 || 0);
    cout << "0||0 = " << b << endl;

    b = (0 || 1);
    cout << "0||1 = " << b << endl;

    b = -1;
    cout << "b= " << b << endl;
    cout << "!b= " << !b << endl;
    return 0;
}