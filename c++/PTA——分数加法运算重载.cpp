#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int fenzi(string a)
{
    string::iterator ab = find(a.begin(), a.end(), 'z');
    string fenzi(a.begin(), ab);
    int num = 0;
    int flag = 0;
    int len = fenzi.length() - 1;
    for (int i = len; i >= 0; --i)
    {
        if (fenzi[len - i] == '-')
            flag = 1;
        else
            num += int((fenzi[len - i] - '0') * pow(10, i));
    }
    if (flag == 1)
        num *= -1;
    return num;
}

int fenmu(string a)
{
    string::iterator ab = find(a.begin(), a.end(), 'z');
    string::iterator ae = find(a.begin(), a.end(), 'm');
    string fenmu(ab + 1, ae);
    int num = 0;
    int flag = 0;
    int len = fenmu.length() - 1;
    for (int i = len; i >= 0; --i)
    {
        if (fenmu[len - i] == '-')
            flag = 1;
        else
            num += int((fenmu[len - i] - '0') * pow(10, i));
    }
    if (flag == 1)
        num *= -1;
    return num;
}

int gcd(int m, int n)
{
    int mm = m > n ? m : n;
    int nn = m < n ? m : n;
    while (nn)
    {
        int temp = nn;
        nn = mm % nn;
        mm = temp;
    }
    return mm;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string a, b;
        cin >> a >> b;
        int az = fenzi(a);
        int am = fenmu(a);

        int bz = fenzi(b);
        int bm = fenmu(b);

        int rz = az * bm + bz * am;
        int rm = bm * am;
        int zm = gcd(rz, rm);

        rz = rz / zm;
        rm = rm / zm;
        if (rm < 0)
        {
            rz = -rz;
            rm = -rm;
        }
        cout << rz << 'z' << rm << 'm' << endl;
    }
    return 0;
}