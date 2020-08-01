#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    string s;
    vector<string> vs;
    for (int i = 0; i < n; ++i)
    {
        cin >> s;
        vs.push_back(s);
    }

    string ts;
    int sum;
    for (int i = 0; i < n; ++i)
    {
        ts = vs[i];
		sum = 0;    
        for (int j = 0; j < n; ++j)
        {
            if (vs[j].length() < vs[i].length())
                continue;
            if (ts == string(vs[j].end() - ts.length(), vs[j].end()))
                sum++;
        }
        cout << sum << endl;
    }

    return 0;
}