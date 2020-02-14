#include <iostream>
#include <string>
#include<vector>
using namespace std;

int main()
{

    int n;
    string name;
    
    while (cin >> n)
    {
        int *vote=new int[3]();
        for (int i = 0; i < n; ++i)
        {
            cin >> name;
            if (name == "Li")
                vote[0]++;
            else if (name == "Zhang")
                vote[1]++;
            else if (name == "Fun")
                vote[2]++;
        }
        cout<<"Li:"<<vote[0]<<endl;
        cout<<"Zhang:"<<vote[1]<<endl;
        cout<<"Fun:"<<vote[2]<<endl;
    }
    return 0;
}