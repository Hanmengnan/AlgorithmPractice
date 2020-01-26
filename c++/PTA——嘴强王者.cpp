#include<iostream>


using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	int * zuipao = new int[n+1];

	for (int i = 1; i <= n; ++i) {
		cin >> zuipao[i];
	}

	int type, begin, end;
	
	for (int i = 0; i < m; ++i) {
		cin >> type >> begin >> end;

		int j, max = -1, index = 0;
		if (type == 0) zuipao[begin] = end;
		else {
			for ( j = begin; j <= end; ++j) {
				if (max < zuipao[j]) {
					max = zuipao[j];
					index = j;
				}
			}
			cout << index << " " << max << "\n";
		}
	}
	return 0;
}