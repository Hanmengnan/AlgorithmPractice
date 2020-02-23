#include <iostream>

using namespace std;

int main()
{
    int begin_minute, begin_second, end_minute, end_second;
    while (cin >> begin_minute >> begin_second >> end_minute >> end_second)
    {
        if (begin_minute == 0 && begin_second == 0 && end_minute == 0 && end_second == 0)
        {
            break;
        }
        int minute_lack = end_minute - begin_minute;
        int second_lack = end_second - begin_second;
        cout << minute_lack * 60 + second_lack << endl;
    }
    return 0;
}