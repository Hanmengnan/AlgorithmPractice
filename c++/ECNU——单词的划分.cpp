#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, m;
    cin >> n;
    while (n--)
    {
        int count = 0;
        string str;
        cin >> str;
        cin >> m;
        vector<string> words_list(m);
        queue<string> words_queue;
        for (string &w : words_list)
            cin >> w;
        words_queue.push(str);
        while (!words_queue.empty())
        {
            count++;
            int s = words_queue.size();
            for (int i = 0; i < s; ++i)
            {

                string temp = words_queue.front();
                words_queue.pop();

                for (string s : words_list)
                {

                    if (temp.substr(0, s.length()) == s)
                    {
                        if (temp == s)
                            goto over;
                        else
                            words_queue.push(temp.substr(s.length()));
                    }
                }
            }
        }
    over:
        cout << count << endl;
    }
    return 0;
}
