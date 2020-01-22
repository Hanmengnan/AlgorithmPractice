#include<iostream>
#include<cmath>
#include<stdio.h>
#define ll long long

using namespace std;


ll Qpow(ll a, ll b, ll mod)
{
	ll res = 1;
	while (b)
	{
		if (b & 1)res = res * a%mod;
		a = a * a%mod;
		b >>= 1;
	}
	return res;
}

int main() {

	ll a, b, n;
	cin >> a >> b >> n;

	ll mod = b * 1000;

	ll res = Qpow(10, n + 2, mod);
	ll p = (a%mod * res%mod) % mod;
	
	printf("%03ld",  p/ b);

	return 0;
}