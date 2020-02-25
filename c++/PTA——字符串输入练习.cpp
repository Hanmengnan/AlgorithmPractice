#include <iostream>
#include <string>
using namespace std;

int main()
{
    char c;
    int num = 0;
    while ((c=getchar())!=EOF)
    {
        if (c == '\n')
        {
            cout << num << endl;
            num = 0;
        }
        else
        {
            num++;
        }
    }
    return 0;
}