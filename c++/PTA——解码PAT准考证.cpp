#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef struct stu
{
    char level;
    string room;
    string date;
    string id;
    int score;
} stu;

typedef struct ss
{
    int index;
    int score;
} ss;

int ss_sort(ss a, ss b)
{

    if (a.score > b.index)
        return true;
    else if (a.score == b.score)
    {
        
    }
    else
        return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<stu> stus;
    while (n--)
    {
        stu new_one;

        string data;
        int score;

        cin >> data >> score;

        new_one.level = data[0];
        new_one.room = data.substr(1, 3);
        new_one.date = data.substr(4, 6);
        new_one.id = data.substr(10, 3);
        new_one.score = score;
        stus.push_back(new_one);
    }
    for (int i = 1; i <= m; ++i)
    {

        int l;
        string data;
        cin >> l >> data;
        cout << "Case " << i << "#: ";
        cout << l << " " << data << endl;

        if (l == 1)
        {
            vector<ss> ss_list;
            for (int k = 0; k < stus.size(); ++k)
            {
                if (data[0] == stus[k].level)
                {
                    ss_list.push_back(ss{k, stus[k].score});
                }
            }
        }
        else if (l == 2)
        {
            int sum = 0;
            int count = 0;
            for (int k = 0; k < stus.size(); ++k)
            {
                if (stus[k].room == data)
                {
                    count++;
                    sum += stus[k].score;
                }
            }
            if (sum != 0)
                cout << count << " " << sum << endl;
            else
                cout << "NA" << endl;
        }
        else
        {
        }
    }
    return 0;
}