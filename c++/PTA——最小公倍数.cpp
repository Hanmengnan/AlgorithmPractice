#include<iostream>
#include<algorithm>
using namespace std;

int gcd(int mm,int nn){
    int m=max(mm,nn);
    int n=min(mm,nn);
    while(n!=0){
        int temp=m%n;
        m=n;
        n=temp;
    }
    return m;

}

int main()
{
    int m,n;
    while(cin>>m>>n){
        int x=gcd(m,n);
        int m_base=m/x;
        int n_base=n/x;
        cout<<m_base*n_base*x<<endl;
    }
    return 0;
}