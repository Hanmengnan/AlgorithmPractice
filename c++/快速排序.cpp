#include<iostream>
#include<stdlib.h>
using namespace std;


void qSort(int *num, int low, int high);
int Partition(int *num, int low, int high);
int *num;
int n;
int main() {

	cin >> n;
	num = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
	}
	qSort(num, 0, n - 1);
	for (int i = 0; i < n; ++i) {
		cout << num[i] << " ";
	}
	system("pause");
	return 0;
}
void qSort(int *num, int low, int high) {
	if (low < high) {
		int pivot = Partition(num, low, high);
		qSort(num, low, pivot - 1);
		qSort(num, pivot + 1, high);

	}
	return;

}

int Partition(int *num, int low, int high) {

	int pivot = num[low];
	while (low < high)
	{
		while (low < high&&num[high] >= pivot) high--;
		num[low] = num[high];
		while (low < high&&num[low] <= pivot) low++;
		num[high] = num[low];
	}
	num[low] = pivot;
	return low;
}