#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, m, count,flag;
    string str;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        flag=count = 0;
        cin >> str;
        for (int i = 0; i < str.length(); ++i)
        {
            if (str[i] == 'S')
                count++;
            else
                count--;
            if (count > m || count < 0)
            {
				flag = 1;
                cout << "NO" << endl;
                break;
            }
        }
		if (flag == 0)
			if (count == 0)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
    }
    return 0;
}