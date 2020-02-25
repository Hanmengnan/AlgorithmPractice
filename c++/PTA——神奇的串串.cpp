#include <iostream>
#include <string>

using namespace std;

int main()
{

    string s, t;
    while (cin >> s >> t)
    {
        cout << t;
        int m, n;
        int flag = 0;

        for (m = 0, n = s.length() - 1; m <= n;)
        {
            int temp_m = m;
            int temp_n = n;
            while (s[temp_m] == s[temp_n] && temp_n >= temp_m + 2)
            {
                temp_m++;
                temp_n--;
            }
            if (s[temp_m] < s[temp_n])
                flag = 0;
            else
                flag = 1;

            if (flag == 0)
            {
                cout << s[m++];
            }
            else
            {
                cout << s[n--];
            }
        }
        cout << endl;
    }

    return 0;
}
