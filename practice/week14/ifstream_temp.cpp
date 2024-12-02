#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream is("temp.txt");
    if (!is)
    {
        cerr << "파일 오픈에 실패하였습니다" << endl;
        exit(1);
    }

    int hour;
    double temperature;
    while (is >> hour >> temperature)
    {
        cout << hour << "시: 온도 " << temperature << endl;
    }
    return 0;
}