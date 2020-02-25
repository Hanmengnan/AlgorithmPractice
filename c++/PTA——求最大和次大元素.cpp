#include <iostream>

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;

        int biggest, second_biggest;
        biggest = second_biggest = INT64_MIN;

        int biggest_index, second_biggest_index;
        biggest_index = second_biggest_index = 1;

        int each_int;
        int flag = 0;

        for (int i = 1; i <= n; ++i)
        {
            cin >> each_int;
            if (each_int > biggest)
            {
                flag = 1;
            }
            else
            {
                if (each_int != biggest && each_int > second_biggest)
                {
                    second_biggest_index = i;
                    second_biggest = each_int;
                }
            }
            if (flag == 1)
            {
                second_biggest_index = biggest_index;
                second_biggest = biggest;
                biggest_index = i;
                biggest = each_int;
                flag = 0;
            }
        }
		if (biggest_index == second_biggest_index) second_biggest_index=0;
        cout << biggest_index << " " << second_biggest_index << endl;
    }

    return 0;
}