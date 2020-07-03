#include <iostream>
#include <string>
using namespace std;

int main()
{
    string data = "I Love GPLT";

    for (string::iterator i = data.begin(); i < data.end() - 1; ++i)
    {
        cout << *i << endl;
    }
    cout << data[data.length() - 1];
    return 0;
}