#include<iostream>
#include<stdlib.h>
using namespace std;
int getMax(int *num, int len);
void insertSort(int *num, int n);
int main() {
	int n;
	cin >> n;
	int *num = (int *)malloc(sizeof(int)*n);
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
	}
	insertSort(num, n);
	for (int i = 0; i < n; ++i) {
		cout << num[i] << " ";
	}
	system("pause");
	return 0;
}
int getMax(int *num, int len) {
	int max = num[0];
	int index = 0;
	for (int i = 1; i < len; ++i) {
		if (num[i] > max) {
			index = i;
			max = num[i];
		}
	}
	return index;
}
void insertSort(int *num, int n) {
	while (n) {

		int index = getMax(num, n);
		int temp = num[n - 1];
		num[n - 1] = num[index];
		num[index] = temp;
		n--;
	}
}
