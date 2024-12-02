#include <iostream>
#include <exception>
using namespace std;
int main()
{
    int pizza_slices = 0;
    int persons = 0;
    int slices_per_person = 0;
    try
    {
        cout << "피자 조각 수를 입력하시오: ";
        cin >> pizza_slices;
        if (pizza_slices == 0)
            throw invalid_argument("0은 나눌 수 없습니다");
        cout << "사람수를 입력하시오: ";
        cin >> persons;
        if (persons == 0)
            throw persons;
        slices_per_person = pizza_slices / persons;
        cout << "한사람당 피자는 " << slices_per_person << "입니다." << endl;
    }
    catch (exception &e)
    {
        cerr << "에러 " << e.what() << endl;
    }
    catch (...)
    {
        cerr << "에러" << endl;
    }
    return 0;
}