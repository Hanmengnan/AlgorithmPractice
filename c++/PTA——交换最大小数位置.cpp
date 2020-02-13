#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{

    int n;
    vector<int> num(20);

    while (cin >> n)
    {
        int min = 99999;
        int min_index = 0;
        int max = -99999;
        int max_index = n - 1;

        num.clear();
        for (int i = 0; i < n; ++i)
        {
            int temp;
            cin >> temp;
            num.push_back(temp);
            if (num[i] > max)
            {
                max = num[i];
                max_index = i;
            }
            if (num[i] < min)
            {
                min = num[i];
                min_index = i;
            }
        }

        int temp=num[0];
        num[0]=min;
        num[min_index]=temp;

        temp=num[n-1];
        num[n-1]=max;
		if (max_index == 0)
			num[min_index] = temp;
		else
        num[max_index]=temp;

		cout << num[0];
        for (int i = 1; i < n; ++i)
        {

            cout <<" "<< num[i] ;
        }
		cout << endl;

    }
    return 0;
}