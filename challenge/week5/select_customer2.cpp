#include <iostream>
#include <string>
using namespace std;

int main()
{
    const int maxPeople = 5;
    string names[maxPeople];
    int ages[maxPeople];
    cout << maxPeople << "명의 회원 정보를 입력해주세요." << endl;
    for (int i = 0; i < maxPeople; i++)
    {
        cout << "사람 " << i + 1 << "의 이름: ";
        cin >> names[i];
        cout << "사람 " << i + 1 << "의 나이: ";
        cin >> ages[i];
    }

    int nums;
    while (1)
    {
        cout << "\n1. 가장 나이가 많은 사람 출력\n";
        cout << "\n2. 가장 나이가 적은 사람 출력\n";
        cout << "\n3. 종료\n";
        cout << "\n메뉴를 선택하세요: ";
        cin >> nums;

        if (nums == 1)
        {
            // 가장 나이가 많은 사람 출력
            int highage = ages[0];
            string highName = names[0];

            for (int i = 1; i < maxPeople; i++)
            {
                if (ages[i] > highage)
                {
                    highage = ages[i];
                    highName = names[i];
                }
            }
            cout << "가장 나이가 많은 사람: " << highName << " (" << highage << "세)\n";
        }
        else if (nums == 2)
        {
            // 가장 나이가 적은 사람 출력
            int lowage = ages[0];
            string lowName = names[0];

            for (int i = 1; i < maxPeople; i++)
            {
                if (ages[i] < lowage)
                {
                    lowage = ages[i];
                    lowName = names[i];
                }
            }
            cout << "가장 나이가 적은 사람: " << lowName << " (" << lowage << "세)\n";
        }
        else if (nums == 3)
        {
            // 프로그램 종료
            cout << "프로그램을 종료합니다.\n";
            break;
        }
        else
        {

            cout << "잘못된 입력입니다. 다시 시도하세요.\n";
        }
    }
    return 0;
}