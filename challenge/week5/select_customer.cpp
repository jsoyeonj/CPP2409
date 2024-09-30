#include <iostream>
#include <string>
using namespace std;
int main()
{
    const int maxPeople = 2;
    string names[maxPeople];
    int ages[maxPeople];
    cout << maxPeople << "명의 회원 정보를 입력해주세요." << endl;
    for (int i = 0; i < maxPeople; i++)
    {
        cout << "사람" << i + 1 << "의 이름:";
        cin >> names[i];
        cout << "사람" << i + 1 << "의 나이:";
        cin >> ages[i];
    }
    int ageThreshold;
    cout << "득정 나이 이상인 사람을 찾으려면 나이를 입력하세요: ";
    cin >> ageThreshold;
    cout << ageThreshold << "세 이상인 고객들" << endl;
    int detectedPeople = 0;
    for (int i = 0; i < maxPeople; i++)
    {
        if (ages[i] >= ageThreshold)
        {
            cout << names[i] << "(" << ages[i] << "세)" << endl;
            detectedPeople++;
        }
    }
    if (detectedPeople == 0)
    {
        cout << ageThreshold << "이상의 나이를 가진 고객이 없습니다";
    }
}