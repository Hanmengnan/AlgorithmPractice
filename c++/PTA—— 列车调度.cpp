#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct node
{
    int num;
    int vis;
} node;

vector<node> vec;

vector<int> func(int n)
{
    int count = 0;
    vector<int> max = {n};
    vector<int> temp = {n};
    for (int i = n - 1; i >= 0; --i)
    {
        if (vec[i].vis == 0)
        {
            if (vec[i].num < vec[n].num)
            {
                vector<int> t = func(i);
                temp.insert(temp.end(), t.begin(), t.end());
                if (temp.size() > max.size())
                    max = temp;
                temp = {n};
            }
        }
    }
    return max;
}


int main()
{
    int n, t;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> t;
        vec.push_back(node{t, 0});
    }
    int m = 0;
    int flag = 1;
    while (flag)
    {
        vector<int> v;
        for (int i = n - 1; i >= 0; --i)
        {
            flag = 0;
            if (vec[i].vis == 0)
            {
                v = func(i);
                for (int i = 0; i < v.size(); ++i)
                {
                    vec[v[i]].vis = 1;
                }
                flag = 1;
                m++;
            }
        }
    }
    cout << m << endl;
    return 0;
}