#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> figure(3);
    for (int i = 0; i < n; ++i)
    {
        figure.clear();
        for (int j = 0; j < 3; ++j)
        {
			string temp;
            cin >>temp;
			figure.push_back(temp);
        }
        
        if(figure[0][0]==figure[1][1]&&figure[0][0]==figure[2][2]&&figure[0][0]=='O')
            goto ok;
        if(figure[0][0]==figure[0][1]&&figure[0][0]==figure[0][2]&&figure[0][0]=='O')
            goto ok;
        if(figure[0][0]==figure[1][0]&&figure[0][0]==figure[2][0]&&figure[0][0]=='O')
            goto ok;
        if(figure[1][0]==figure[1][1]&&figure[1][0]==figure[1][2]&&figure[1][0]=='O')
            goto ok;
        if(figure[2][0]==figure[2][1]&&figure[2][0]==figure[2][2]&&figure[2][0]=='O')
            goto ok;
        if(figure[0][1]==figure[1][1]&&figure[0][1]==figure[2][1]&&figure[0][1]=='O')
            goto ok;
        if(figure[0][2]==figure[1][2]&&figure[0][2]==figure[2][2]&&figure[0][2]=='O')
            goto ok;
        if(figure[0][2]==figure[1][1]&&figure[0][2]==figure[2][0]&&figure[0][2]=='O')
            goto ok;
        cout << "no" << endl;
        continue;
    ok:
        cout << "yes" << endl;
    }

    return 0;
}