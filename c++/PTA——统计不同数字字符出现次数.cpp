#include <iostream>

using namespace std;

int main()
{

    char c;
    int num[10] = {0};
    while ((c = getchar()) != '\n')
    {
        if ((c - '0') >= 0 && (c - '0') <= 9)
            num[c - '0']++;
    }
    int flag = 0;
    for (int i = 0; i < 10; i++)
    {
        if (num[i])
        {
            flag = 1;
            cout << i << "-" << num[i] << endl;
        }
    }
    if (flag == 0)
        cout << "None!" << endl;
    return 0;
}