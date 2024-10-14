#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s = " HEllP WORLD";
    char ch = s[7];
    cout << " 인덱스 7의 문자 " << ch << endl;
    if (!s.empty())
    {
        cout << " 문자열은 비어있습니다." << endl;
    }
    else
    {
        cout << " 문자열은 비어있습니다." << endl;
    }
    s.insert(5, "C++");
    cout << "index 5에 C++ 문자열 삽입 " << s << endl;
    return 0;
}