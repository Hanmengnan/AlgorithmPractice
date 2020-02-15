#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{

    string origin_string;
    getline(cin, origin_string);

    char split_letter = getchar();
    getchar();
    string join_string;
    getline(cin, join_string);

    int flag = 1;
    vector<int> index;

    for (int i = 1; i < origin_string.length(); ++i)
    {
        if (flag == 1 && origin_string[i] != split_letter)
        {
            index.push_back(i);
            flag = 0;
        }
        else if (flag == 0 && origin_string[i] == split_letter)
        {
            index.push_back(i);
            flag = 1;
        }
    }

    vector<string> split_string;
    string temp;
    cout << "[";
    for (int i = 0; i < index.size(); ++i)
    {
        cout << "\"";
        if (i % 2 == 0 && i != index.size() - 1)
        {
            temp = string(origin_string.begin() + index[i], origin_string.begin() + index[i + 1]);
            cout << temp;
            split_string.push_back(temp);
        }
        else if (i % 2 == 1)
        {
            split_string.push_back("");
        }
        else if (i == index.size() - 1)
        {
            temp = string(origin_string.begin() + index[i], origin_string.end());
            if (temp[0] == split_letter)
                split_string.push_back("");
            else
            {
                cout << temp;
                split_string.push_back(temp);
            }
        }

        cout << "\"";
        if (i != index.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;

    for (int i = 0; i < split_string.size(); ++i)
    {
        cout << split_string[i];
        if (i != split_string.size() - 1)
        {
            cout << join_string;
        }
    }
    return 0;
}