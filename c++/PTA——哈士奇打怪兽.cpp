#include <iostream>

using namespace std;

int main()
{

    int x1, y1, x2, y2;
    while (cin >> x1 >> y1 >> x2 >> y2)
    {
        for (int i = 1;; i++)
        {
            if ((x2 - i * y1) <= 0)
            {
                cout << "hsqwin" << endl;
                break;
            }
            if ((x1 - i * y2) <= 0)
            {
                cout << "hsqlose" << endl;
                break;
            }
        }
    }
    return 0;
}