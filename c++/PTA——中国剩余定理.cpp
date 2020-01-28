#include<iostream>

#define ll long long
using namespace std;

ll gcd(ll m, ll n) {
	ll temp = 0;
	while (n!=0) {
		temp = m % n;
		m = n;
		n = temp;
	}
	return m;
}

int main() {
	ll m, mm, n, nm;

	cin >> m >> mm >> n >> nm;
	if ((mm - nm) % gcd(m, n) == 0) {
		ll i = -1;
		ll sum = 0;
		while (true)
		{
			i++;
			sum = (m*i + mm);
			if ( sum% n == nm) break;

		}
		cout << (m*i + mm) << endl;
	}
	else {
		cout << "no answer." << endl;
	}
	return 0;
}