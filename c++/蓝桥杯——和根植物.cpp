#include<iostream>
#include<stdlib.h>


using namespace std;

int main() {

	int m, n;
	cin >> m >> n;
	int connection;
	cin >> connection;
	int num = 0;
	int * plant = (int *)malloc(sizeof(int)*(m*n+1));
	for (int i = 0; i < m*n + 1; ++i) {
		plant[i] = i;
	}

	for (int i = 0; i < connection; ++i) {
		int bp, ep;
		cin >> bp >> ep;

		while (plant[bp]!=bp)
		{
			bp = plant[bp];
		}
		while (plant[ep] != ep)
		{
			ep = plant[ep];
		}
		if (ep != bp) {
			plant[ep] = bp;
		}

	}

	for (int i = 1; i < m*n + 1; ++i) {
		//cout << i<<":"<<plant[i] << '\n';
		if (plant[i] == i) num++;
	}
	cout << num;
	//system("pause");
	return 0;
}