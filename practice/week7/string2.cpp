#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s = "Hello World!";
    s.erase(7, 2);
    cout << "index7 부터 2글자 문자열 제거" << s << endl;
    int found = s.find("Hello");
    if (found >= 0)
    {
        cout << "찾은 위치: " << found << endl;
    }
    found = s.find(",", 4);
    if (found >= 0)
    {
        cout << "특정 위치 이후로 찾은 위치:" << found << endl;
    }
    found = s.find("World");
    if (found >= 0)
    {
        cout << "찾은 위치:" << found << endl;
    }
    else
    {
        cout << "찾을 수 없습니다: found=" << found << endl;
    }
    return 0;
}