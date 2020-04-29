#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int main()
{
    unsigned n;
    cin >> n;
    vector<string> nums(n);
    
    for (auto &i : nums)
        cin >> i;
    sort(nums.begin(), nums.end(), [](string const &a, string const &b) { return b + a < a + b; });
    for (auto const &i : nums)
        cout << i;

    return 0;
}