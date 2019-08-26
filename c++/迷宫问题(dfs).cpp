#include<iostream>;
#include<stdlib.h>
#include<math.h>
using namespace std;
void dfs(int x, int y, int step);
int r, c;
int b_x, b_y, e_x, e_y;
int min=99999;
int direction[4][2] = { {0,1}, {0,-1},{1,0},{-1,0} };
int **container;
int **status;
int main() {

	cin >> r >> c;

	container = (int **)malloc(sizeof(int*)*r);
	status = (int **)malloc(sizeof(int*)*r);
	for (int i = 0; i < r; ++i) {
		container[i] = (int *)malloc(sizeof(int)*c);
		status[i] = (int *)malloc(sizeof(int)*c);
	}
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cin >> container[i][j];
			status[i][j] = 0;
		}
	}
	

	cin >> b_x >> b_y >> e_x >> e_y;
	status[b_x-1][b_y-1] = 1;
	dfs(b_x-1, b_y-1, 0);
	cout << min;
	system("pause");
	return 0;
}
void dfs(int x, int y,int step) {
	if (x == e_x-1 && y == e_y-1) {
		if (step < min) min = step;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int tempx = x + direction[i][0];
		int tempy = y + direction[i][1];
		if (tempx < 0 || tempy < 0 || tempx >= r || tempy >= c) {
			continue;
		}
		if (status[tempx][tempy] == 1 || container[tempx][tempy] == 1) {
			continue ;
		}
		{
			status[tempx][tempy] = 1;
			dfs(tempx, tempy, step + 1);
			status[tempx][tempy] = 0;
			
		}


	}
	return;

}