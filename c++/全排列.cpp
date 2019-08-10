#include<iostream>
#include<stdlib.h>
using namespace std;
void perma(int *myArray, int b, int e);
int main() {
	int n;
	cin >> n;
	int * myArray = (int *)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) {
		cin >> myArray[i];
	}
	perma(myArray, 0, n - 1);
	system("pause");
	return 0;
}
void swap(int *x, int *y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
void perma(int *myArray, int b, int e) {
	if (b == e) {
		for (int i = 0; i <= e; i++) {
			printf("%d ", myArray[i]);
		}
		printf("\n");
	}
	else {
		for (int i = b; i <= e; i++) {
			swap(myArray + b, myArray + i);
			perma(myArray, b + 1, e);
			swap(myArray + b, myArray + i);
		}
	}
}