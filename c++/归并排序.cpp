#include<iostream>
#include<stdlib.h>
using namespace std;
void Merge(int arrayA[], int low, int mid, int height);
void MergeSort(int arrayA[], int i, int j);
int main() {
	int n;
	cin >> n;
	int * arrayA = (int *)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) {
		cin >> arrayA[i];
	}
	MergeSort(arrayA, 0, n-1);
	for (int i = 0; i < n; i++) {
		cout << arrayA[i]<<" ";
	}
	system("pause");
	return 0;
}
void Merge(int arrayA[], int low, int mid, int height) {
	int i, j, k;
	int * arrayB = (int *)malloc(sizeof(int)*(height-low+1));
	for (int temp = low; temp <=height; temp++) {
		arrayB[temp] = arrayA[temp];
	}
	for (i = low, j = mid + 1, k = i; i <= mid&&j <= height; k++) {
		if (arrayB[i] <= arrayB[j]) arrayA[k] = arrayB[i++];
		else arrayA[k] = arrayB[j++];
	}
	while (i <= mid) arrayA[k++] = arrayB[i++];
	while (j <= height) arrayA[k++] = arrayB[j++];
	
} 
void MergeSort(int arrayA[],int i,int j) {
	if (i < j) {
		int k = (i + j) / 2;
		MergeSort(arrayA, i, k);
		MergeSort(arrayA, k + 1, j);
		Merge(arrayA, i, k, j);
	}
}