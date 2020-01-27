#include<iostream>

using namespace std;

int sum = 0;
int * prime = new int[10001]();

bool is_prime(int num) {
	for (int i = 2; i <= num / 2 ; ++i) {
		if (num%i == 0) {
			return false;
		}
	}
	return true;
}

void init() {
	for (int i = 2; i <= 10000; ++i) {
		if (is_prime(i)) prime[i] = 1;
	}


	return;
}

int num_of_Prime(int num) {
	int tempsum, f;
	tempsum = f = 0;

	for (int i = num; i >=2; --i) {
		if (!prime[i]) continue;

		tempsum  = 0;

		for (int j = i; j >0; --j) {
			if (tempsum > num) break;
			else if (tempsum == num) {
				f++;
				break;
			}
			else {
				if (prime[j]) {
					tempsum += j;
				}
	
			}
		}
	}
	return f;
}

int main() {
	int num;

	init();

	while (true)
	{
		cin >> num;

		if (num == 0) break;

		cout << num_of_Prime(num) << endl;
		
		sum = 0;
	}

	return 0;
}