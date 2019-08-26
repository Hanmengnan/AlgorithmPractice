#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
using namespace std;
typedef struct queue {
	int x;
	int y;
	int step;
}queue;
int direction[4][2] = { {1,0},{1,0},{0,1},{0,-1} };

int m, n;
int head, tail;
int e_x, e_y;

int ** book;
int ** container;
queue * way;

int error(int x, int y);
int bfs(int x, int y, int step);

int main() {

	scanf("%d%d", &m, &n);

	head = tail = 0;

	way = (queue*)malloc(sizeof(queue)*m*n);

	book = (int **)malloc(sizeof(int *)*m);
	container = (int **)malloc(sizeof(int *)*m);

	for (int i = 0; i < m; ++i) {
		book[i] = (int *)calloc(sizeof(int), n);
		container[i] = (int *)malloc(sizeof(int)*n);
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &container[i][j]);
		}
	}
	scanf("%d%d", &e_x, &e_y);

	printf("%d", bfs(0, 0, 0));
	system("pause");
	return 0;
}

int bfs(int x, int y, int step) {
	way[tail].x = x;
	way[tail].y = y;
	way[tail].step = 0;
	tail++;
	book[x][y] = 1;

	while (tail > head)
	{
		int flag = 0;
		for (int i = 0; i < 4; i++) {
			int tempx = way[head].x + direction[i][0];
			int tempy = way[head].y + direction[i][1];
			if (error(tempx, tempy)) continue;
			if (book[tempx][tempy] == 1 || container[tempx][tempy] == 1) continue;
			else {
				if (tempx == e_x - 1 && tempy == e_y - 1) {
					flag = 1;
					break;
				}
				else {
					book[tempx][tempy] = 1;
					way[tail].x = tempx;
					way[tail].y = tempy;
					way[tail].step = way[head].step + 1;
					printf("%d %d %d\n", way[tail].x, way[tail].y, way[tail].step);
					tail++;
				}
			}
		}
		if (flag == 1) break;
		head++;
	}

	return way[tail - 1].step;
}
int error(int x, int y) {
	if (x >= m || y >= n || x < 0 || y < 0) {
		return 1;
	}
	else return 0;
}