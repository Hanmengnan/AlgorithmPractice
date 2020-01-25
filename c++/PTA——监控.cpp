#include<iostream>

#define ll long long

using namespace std;

int main() {

	int  n;
	cin >> n;

	int max = -1;
	int num[2 * 100000 + 1];
	
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
		for (int j = i-1; j >=0; --j) {
			if (num[j] <= num[i] || num[i] == 0) continue;
			max = max > (num[j] % num[i]) ? max : (num[j] % num[i]);
		}
	}
	cout << max;
	return 0;
}