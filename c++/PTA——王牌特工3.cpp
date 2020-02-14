#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<char> list;

int main()
{
    string secret_code;
    while (cin >> secret_code)
    {

        list.clear();
        for (int i = 0; i < 26; ++i)
        {
            list.push_back(i + 'A');
        }

        for (int i = 0; i < secret_code.length(); ++i)
        {
            list.erase(remove(list.begin(), list.end(), secret_code[i]),list.end());
            list.insert(list.begin() + i, secret_code[i]);
        }

        int n;
        cin >> n;
		getchar();
        for (int i = 0; i < n; ++i)
        {
            string secret_data;
			
            getline(cin, secret_data);
            for (int j = 0; j < secret_data.length(); ++j)
            {
				if (secret_data[j] >= 'A' && secret_data[j] <= 'Z')
				{
					int index = find(list.begin(), list.end(), char(secret_data[j])) - list.begin();
					cout <<char( 'A' + index);
				}
				else if (secret_data[j] >= 'a' && secret_data[j] <= 'z')
				{
					int index=find(list.begin(), list.end(), char(secret_data[j]-32)) - list.begin();
					cout << char('a' + index);
				}
				else
					cout << secret_data[j];
            }
			cout << endl;
        }
    }

    return 0;
}