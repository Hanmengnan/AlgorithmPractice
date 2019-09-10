#include<iostream>
#include<stdlib.h>
using namespace std;
int output();
void swap(int x, int y);
void siftdown(int i);
void create();
int * container;
int n, num;
int main() {
	cin >> n;
	num = n;
	container = (int*)malloc(sizeof(int)*(n + 1));
	for (int i = 1; i <= n; ++i) {
		cin >> container[i];
	}
	create();
	for (int i = 1; i <= num; ++i) {
		cout << output() << " ";
	}
	system("pause");
	return 0;
}
void swap(int x, int y) {
	int t = container[x];
	container[x] = container[y];
	container[y] = t;
}
void siftdown(int i) {
	int t;
	int flag = 0;
	while (i * 2 <= n && flag == 0) {
		if (container[i] < container[i * 2]) {
			t = i * 2;
		}
		else {
			t = i;
		}
		if (i * 2 + 1 <= n) {
			if (container[t] < container[i * 2 + 1]) {
				t = i * 2 + 1;
			}
		}
		if (t != i) {
			swap(t, i);
			i = t;
		}
		else {
			flag = 1;
		}
	}
	return;
}
void create() {
	for (int i = n / 2; i > 0; i--) {
		siftdown(i);
	}
	return;
}
int output() {
	int t = container[1];
	container[1] = container[n];
	n--;
	siftdown(1);
	return t;
}