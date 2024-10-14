#include <iostream>
#include <string>
using namespace std;

string toLowerStr(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + 32;
        }
    }
    return str;
}

string toUpperStr(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 32;
        }
    }
    return str;
}

int calcHammingDist(string s1, string s2)
{
    s1 = toLowerStr(s1);
    s2 = toLowerStr(s2);
    int count = 0;
    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] != s2[i])
        {
            count++;
        }
    }
    return count;
}

int main()
{
    string s1, s2;
    do
    {
        cout << "DNA1: ";
        cin >> s1;
        cout << "DNA2: ";
        cin >> s2;
        if (s1.length() != s2.length())
        {
            cout << "오류: 길이가 다릅니다. 다시 입력해주세요." << endl;
        }
    } while (s1.length() != s2.length());
    int hammingDist = calcHammingDist(s1, s2);
    cout << "해밍 거리는 " << hammingDist << endl;

    return 0;
}
