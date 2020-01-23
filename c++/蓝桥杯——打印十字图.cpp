#include<iostream>
#include<malloc.h>
using namespace std;

int **figue;
int main() {
	int n;
	int item = 0;
	cin >> n;
	n = n * 2 + 3;
	figue = (int **)malloc(sizeof(int*)*n);

	for (int i = 0; i < n; ++i) {
		figue[i] = (int *)malloc(sizeof(int)*n);
	}
	//创建四分之一

	for (int i=0, k = 0; i < n-2; ++i,++k) {
		if (i % 2 == 1) item = 0;
		else item = 1;

		for (int j=2+k; j < n; ++j) {
			figue[i][j] = figue[j][i] = item;
		}

	}
	//上下三角

	figue[0][0] = 0;
	for (int i = 1; i < n ; ++i) {
		if (i % 2 == 1) item = 0;
		else item = 1;
		figue[i][i] = figue[i - 1][i] = figue[i][i - 1] = item;
	}
	//// 中间部分

	
	for (int i = 0; i < n ; ++i) {
		for (int j = 0; j < n ; ++j) {
			
			if (figue[i][j] == 0) cout << ".";
			else if(figue[i][j]==1) cout << "$";
			else cout << "*";
		}
		for (int j = n-2; j >=0; --j) {
			if (figue[i][j] == 0) cout << ".";
			else cout << "$";
		}
		cout << "\n";
	}
	//整体上部分
	for (int i = n-2; i >=0 ; --i) {
		for (int j = 0; j < n; ++j) {
			if (figue[i][j] == 0) cout << ".";
			else cout << "$";
		}
		for (int j = n - 2; j >= 0; --j) {
			if (figue[i][j] == 0) cout << ".";
			else cout << "$";
		}
		cout << "\n";
	}
	return 0;
}