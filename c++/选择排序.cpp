#include<iostream>
#include<stdlib.h>
using namespace std;
void selectSort(int *num, int n);
int main() {
	int n;
	cin >> n;
	int *num = (int *)malloc(sizeof(int)*n);
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
	}
	for (int i = 1; i <= n; ++i) {
		selectSort(num, i);
	}

	for (int i = 0; i < n; ++i) {
		cout << num[i] << " ";
	}
	system("pause");
	return 0;
}
void selectSort(int *num, int n) {
	int i = n - 1;
	int key = num[i];
	while (key < num[i - 1]) {
		num[i] = num[i - 1];
		i--;
		if (i == 0) break;
	}
	num[i] = key;

}
