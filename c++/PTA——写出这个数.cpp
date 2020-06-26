#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

map<int, string> num = {{0, "ling"}, {1, "yi"}, {2, "er"}, {3, "san"}, {4, "si"}, {5, "wu"}, {6, "liu"}, {7, "qi"}, {8, "ba"}, {9, "jiu"}};

int main()
{
    string n;
    vector<string> con;
    while (cin >> n)
    {
        con.clear();
        int sum = 0;
        for (string::iterator i = n.begin(); i != n.end(); ++i)
        {
            sum += *i - '0';
        }
        while (sum)
        {
            con.push_back(num[sum % 10]);
            sum /= 10;
        }
        for (int i = con.size() - 1; i > 0; --i)
        {
            cout << con[i] << " ";
        }
        cout << con[0] << endl;
    }
    return 0;
}