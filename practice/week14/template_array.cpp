#include <iostream>
using namespace std;
// 템플릿 함수: 배열 a2의 요소를 배열 a1에 복사
template <typename T1, typename T2>
void copy(T1 a1[], T2 a2[], int n)
{
    for (int i = 0; i < n; ++i)
        a1[i] = a2[i];
}
int main()
{
    int intArray1[5] = {10, 20, 30, 40, 50};
    double doubleArray2[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    // copy 함수를 사용하여 double 배열을 int 배열에 복사
    copy(intArray1, doubleArray2, 5);
    // 결과 출력
    cout << "Copied intArray1 from doubleArray2: ";
    for (int i = 0; i < 5; ++i)
    {
        std::cout << intArray1[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
