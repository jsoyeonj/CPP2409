#include <iostream>
using namespace std;
int main()
{
    int choice;
    cout << "1. 파일 저장" << endl;
    cout << "2. 저장없이 닫기" << endl;
    cout << "3. 종료" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "파일 저장을 선택했습니다" << endl;
        break;
    case 2:
        cout << "파일 닫기를 선택했습니다" << endl;
        break;
    case 3:
        cout << "프로그램을 종료합니다" << endl;
        break;
    case 4:
        cout << "잘못된 선택입니다." << endl;
        break;
    }
}
