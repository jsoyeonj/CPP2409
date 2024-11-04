
#include "user.h"
#include <iostream>
#include <string>
using namespace std;

const int mapX = 5;
const int mapY = 5;

// 사용자 정의 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(int map[][mapX], int user_x, int user_y);
bool checkGoal(int map[][mapX], int user_x, int user_y);
void checkState(int map[][mapX], int user_x, int user_y, User &user); // 상태 체크 함수 선언
bool CheckUser(const User &user);                                     // 체력 체크 함수 선언

// 메인 함수
int main()
{
    int map[mapY][mapX] = {{0, 1, 2, 0, 4},
                           {1, 0, 0, 2, 0},
                           {0, 0, 0, 0, 0},
                           {0, 2, 3, 0, 0},
                           {3, 0, 0, 0, 2}};

    int user_x = 0;
    int user_y = 0;
    User user; // User 객체 생성

    while (1)
    {
        cout << "현재 체력: " << user.GetHP() << " ";
        string user_input = "";

        cout << "명령어를 입력하세요 (up, down, left, right, map, exit): ";
        cin >> user_input;

        if (user_input == "up")
        {
            user_y -= 1;
            bool inMap = checkXY(user_x, mapX, user_y, mapY);
            if (inMap == false)
            {
                cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                user_y += 1;
            }
            else
            {
                cout << "위로 한 칸 올라갑니다." << endl;
                user.DecreaseHP(1); // 이동 시 hp 감소
                displayMap(map, user_x, user_y);
                checkState(map, user_x, user_y, user); // 현재 상태 체크
            }
        }
        else if (user_input == "down")
        {
            user_y += 1;
            bool inMap = checkXY(user_x, mapX, user_y, mapY);
            if (inMap == false)
            {
                cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                user_y -= 1;
            }
            else
            {
                cout << "아래로 한 칸 이동합니다." << endl;
                user.DecreaseHP(1);
                displayMap(map, user_x, user_y);
                checkState(map, user_x, user_y, user);
            }
        }
        else if (user_input == "left")
        {
            user_x -= 1;
            bool inMap = checkXY(user_x, mapX, user_y, mapY);
            if (inMap == false)
            {
                cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                user_x += 1;
            }
            else
            {
                cout << "왼쪽으로 이동합니다." << endl;
                user.DecreaseHP(1);
                displayMap(map, user_x, user_y);
                checkState(map, user_x, user_y, user);
            }
        }
        else if (user_input == "right")
        {
            user_x += 1;
            bool inMap = checkXY(user_x, mapX, user_y, mapY);
            if (inMap == false)
            {
                cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                user_x -= 1;
            }
            else
            {
                cout << "오른쪽으로 이동합니다." << endl;
                user.DecreaseHP(1);
                displayMap(map, user_x, user_y);
                checkState(map, user_x, user_y, user);
            }
        }
        else if (user_input == "map")
        {
            displayMap(map, user_x, user_y);
        }
        else if (user_input == "exit")
        {
            cout << "종료합니다.";
            break;
        }
        else
        {
            cout << "잘못된 입력입니다." << endl;
            continue;
        }

        bool finish = checkGoal(map, user_x, user_y);
        if (finish == true)
        {
            cout << "목적지에 도착했습니다! 축하합니다!" << endl;
            cout << "게임을 종료합니다." << endl;
            break;
        }
        if (CheckUser(user) == false)
        {
            cout << "HP가 0이 되었습니다. 실패입니다!" << endl;
            break;
        }
    }
    return 0;
}

// 상태 체크 함수
void checkState(int map[][mapX], int user_x, int user_y, User &user)
{
    int posState = map[user_y][user_x];
    if (posState == 2)
    {
        cout << "적이 있습니다. HP가 2 줄어듭니다." << endl;
        user.DecreaseHP(2);
    }
    else if (posState == 1)
    {
        cout << "아이템이 있습니다." << endl;
    }
    else if (posState == 3)
    {
        cout << "포션이 있습니다. HP가 2 증가합니다." << endl;
        user.IncreaseHP(2);
    }
}

// 체력 체크 함수
bool CheckUser(const User &user)
{
    return user.GetHP() > 0;
}

// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY)
{
    return (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY);
}

// 지도와 사용자 위치 출력하는 함수
void displayMap(int map[][mapX], int user_x, int user_y)
{
    for (int i = 0; i < mapY; i++)
    {
        for (int j = 0; j < mapX; j++)
        {
            if (i == user_y && j == user_x)
            {
                cout << " USER |";
            }
            else
            {
                int posState = map[i][j];
                switch (posState)
                {
                case 0:
                    cout << "      |";
                    break;
                case 1:
                    cout << "아이템|";
                    break;
                case 2:
                    cout << "  적  |";
                    break;
                case 3:
                    cout << " 포션 |";
                    break;
                case 4:
                    cout << "목적지|";
                    break;
                }
            }
        }
        cout << endl;
        cout << " -------------------------------- " << endl;
    }
}

// 유저의 위치가 목적지인지 체크하는 함수
bool checkGoal(int map[][mapX], int user_x, int user_y)
{
    // 목적지 도착하면
    if (map[user_y][user_x] == 4)
    {
        return true;
    }
    return false;
}