#include <iostream>
#include <set>
#define ll long long
using namespace std;


int main()
{
    int n;
    cin>>n;
    if (n < 3)
        cout << "Invalid Input";
    else
    {
        set<ll> num;
        ll temp;
        for (int i = 0; i < n; ++i)
        {
            cin >> temp;
            num.insert(temp);
        }
        if (num.size() == 2)
            cout << "There is no third largest element";
        else if (num.size() == 1)
            cout << "There is no second largest and third largest element";
        else{
            set<ll>::iterator index=num.end();
			index--;
			cout << *(index) << " ";
			index--;
			cout << *(index) << " ";
			index--;
			cout << *(index);
        }
    }
    return 0;
}