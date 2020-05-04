#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s, t;
next:
    while (cin >> s >> t)
    {
        int index = -1;
        for (string::iterator c = s.begin(); c != s.end(); ++c)
        {
            index = t.find_first_of(*c, index + 1);
            if (index == string::npos)
            {
                cout << "No" << endl;
                goto next;
            }
        }
        cout << "Yes" << endl;
    }
    return 0;
}