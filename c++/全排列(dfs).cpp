#include<iostream>
#include<stdlib.h>
using namespace std;
void dfs(int * container, int * status, int step);
int n;
int main() {
	cin >> n;
	int * container = (int *)malloc(sizeof(int)*n);
	int * status = (int *)calloc(n,sizeof(int));
	for (int i = 1; i <= n; i++) {
		container[i] = i;
	}
	dfs(container, status, 0);
	system("pause");
	return 0;
}
void dfs(int * container, int * status,int step) {
	if (step == n) {
		for (int i = 0; i < n; ++i) {
			cout << container[i] << " ";
		}
		cout << "\n";
		return;
	}
	else {
		for (int i = 0; i < n; ++i) {
			if (status[i] == 0) {
				container[step] = i+1;
				status[i] = 1;
				dfs(container, status, step + 1);
				status[i] = 0;
			}
		}
		return;
	}
}