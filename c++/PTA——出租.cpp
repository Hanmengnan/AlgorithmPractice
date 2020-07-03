#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <vector>

using namespace std;

int main()
{
    string num;
    cin >> num;
    set<int, greater<int>> num_set;
    vector<int> num_vec;
    for (string::iterator i = num.begin(); i < num.end(); ++i)
    {
        num_set.insert(*i - '0');
    }
    cout << "int[] arr = new int[]{";

    int p = 0;
    set<int>::iterator i;
    for (i = num_set.begin(); p != num_set.size() - 1; ++i, ++p)
    {
        cout << *i << ",";
    }
    cout << *i << "};" << endl;

    cout << "int[] index = new int[]{";
    num_vec.assign(num_set.begin(), num_set.end());

    string::iterator j;
    for (j = num.begin(); j < num.end() - 1; ++j)
    {
        cout << find(num_vec.begin(), num_vec.end(), *j - '0') - num_vec.begin() << ",";
    }
    cout << find(num_vec.begin(), num_vec.end(), *j - '0') - num_vec.begin() << "};";
    return 0;
}
