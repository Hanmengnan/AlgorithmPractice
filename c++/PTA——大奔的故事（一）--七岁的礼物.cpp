#include <iostream>

using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        int sum = 0;
        while (n)
        {
			if ((n % 7 == 0) || (n / 10 % 10 == 7) || (n % 10 == 7)) {
				n--;
				continue;
			}
            else
            {
				
                sum += n * n;
				n--;
            }
            
        }
        cout << sum<<endl;
    }
    return 0;
}