#include<iostream>
using namespace std;

int m, n;
int path[101][101];

int main() {
	cin >> m >> n;

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < i; ++j) {
			path[i][j] = path[j][i] = 0;
		}
	}

	int b, e;
	for (int i = 0; i < n; ++i) {
		cin >> b >> e;
		path[b][e] = 1;
	}

	int k, p;
	cin >> k;
	p = 0;
	int *sequence = new int[m]();

	for (int i = 0; i < k; ++i) {
		int *state = new int[m]();
		for (int j = 0; j < m; ++j) {
			cin >> sequence[j];
		}

		for (int j = 0; j < m-1; ++j) {
			if (state[sequence[j]] == 1) {
				cout << "No" << endl;
				goto next;
			}
			state[sequence[j]] = 1;
			if (path[sequence[j]][sequence[j + 1]] ==1) {
				continue;
			}
			else {
				p = 0;
				for (int h = j ; h > 0; --h) {
					for (int l = 0; l < m; ++l) {
						if (state[l] == 0 && path[sequence[h]][l] == 1) {
							if (path[sequence[h]][sequence[j + 1]] == 1) p = 0;
							else p = 1;
							goto no;
						}
					}
				}
				no:if (p == 1) {
					cout << "No" << endl;
					goto next;
				}
			}
			
		}
		cout << "Yes" << endl;
	next:;
	}

	return 0;
}