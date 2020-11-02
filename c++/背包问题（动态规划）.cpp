#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
int **initContainer(int num, int volume);
void initGoods(int num, struct good *goodsContainer);
int knapsack(struct good *goodsContainer, int **container, int volume, int index);
typedef struct good
{
	int size;
	int prize;
} goods;
int goodsNum, bagVolume;
int main()
{

	cin >> goodsNum;
	cin >> bagVolume;
	int **arr = initContainer(goodsNum, bagVolume);
	struct good *goodsContainer = (struct good *)malloc(sizeof(struct good) * goodsNum);
	initGoods(goodsNum, goodsContainer);
	cout << knapsack(goodsContainer, arr, bagVolume, 0);
	system("pause");
	return 0;
}
int **initContainer(int num, int volume)
{
	int **arr = (int **)malloc(sizeof(int *) * num);
	for (int i = 0; i < num; i++)
	{
		arr[i] = (int *)malloc(sizeof(int) * volume);
	}
	return arr;
}
void initGoods(int num, struct good *goodsContainer)
{

	for (int i = 0; i < num; i++)
	{
		cin >> goodsContainer[i].size;
		cin >> goodsContainer[i].prize;
	}
}
int knapsack(struct good *goodsContainer, int **container, int volume, int index)
{
	int sum = 0;
	if (index == goodsNum or volume <= 0)
		return sum;
	else
	{
		if (goodsContainer[index].size <= volume)
		{
			int y_worth = knapsack(goodsContainer, container, volume - goodsContainer[index].size, index + 1) + goodsContainer[index].prize;
			int n_worth = knapsack(goodsContainer, container, volume, index + 1);
			sum += y_worth > n_worth ? y_worth : n_worth;
			return sum;
		}
		else
			return sum;
	}
}