#include <iostream>
#include <string>
using namespace std;

int main()
{
    string num;
    getline(cin, num);
    double r = 100;

    int b = 0;
    if (num[0] == '-')
    {
        b = 1;
        r *= 1.5;
    }
    if (atoi(&num[num.length() - 1]) % 2 == 0)
        r *= 2;

    int t = 0;
    for (int i = b; i < num.length(); ++i)
    {
        if (num[i] == '2')
            t++;
    }
    printf("%.2f", double(t) / (num.length() - b) * r);
    cout << "%";
    return 0;
}