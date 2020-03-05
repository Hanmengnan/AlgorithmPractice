#include <iostream>

using namespace std;

void my_swap(int &n, int &m)
{
    int temp = n;
    n = m;
    m = temp;
}
int main()
{
    int n, m;
    cin >> n >> m;
    my_swap(n, m);
    cout << n <<" "<< m << endl;
    return 0;
}