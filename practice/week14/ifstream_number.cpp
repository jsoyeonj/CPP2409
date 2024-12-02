#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream is{"numbers.txt"};
    if (!is)
    {
        cerr << "파일 오픈에 실패하였습니다" << endl;
        exit(1);
    }
    int number;
    while (is)
    {
        is >> number;
        cout << number << " ";
    }
    cout << endl;
    return 0;
}