#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
int initMax(int arrayA[], int n);
void basesort(int arrayA[], int p, int n, int over);
int main() {
	int n;
	cin >> n;
	int * arrayA = (int *)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) {
		cin >> arrayA[i];
	}
	int max = initMax(arrayA, n);
	basesort(arrayA, max, n,1);
	for (int i = 0; i < n; i++) {
		cout << arrayA[i] << " ";
	}
	system("pause");
	return 0;
}
int initMax(int arrayA[],int n) {
	int max = 0;
	for (int i = 0; i < n; i++) {
		int temp = arrayA[i];
		int k = 0;
		while (temp>10)
		{
			temp /= 10;
			k++;
		}
		if (k > max) max = k;
	}
	return max;
}
void basesort(int arrayA[], int p,int n,int over) {
	if (over != p) {
		int ** queueArray = (int **)malloc(sizeof(int*)*10);
		for (int i = 0; i < 10; i++) {
			queueArray[i] = (int *)malloc(sizeof(int)*(n + 1));
			queueArray[i][n] = 0;
		}
		for (int i = 0; i < n; i++) {
			
			int index = (arrayA[i] % (int)pow(10, over))/pow(10,over-1);
			int num = queueArray[index][n];
			queueArray[index][num] = arrayA[i];
			queueArray[index][n]++;
		}
		int k = 0;
		for (int i = 0; i < 10; i++) {
			
			for (int j = 0; j < queueArray[i][n]; j++) {
				arrayA[k++] = queueArray[i][j];
			}
		}
		basesort(arrayA, p, n, over + 1);
	}
}