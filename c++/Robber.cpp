#define _CRT_SECURE_NO_WARNINGS
/*
仍然存在问题，未解决
*/
#include<iostream>
#include<stdlib.h>
using namespace std;
int opt(int * money, int num);
int main() {
	int * money = (int *)malloc(sizeof(int));
	int i = 0;
	while (1)
	{		
		char p = getchar();
		if (p >= 48 and p <= 57) {
			money[i++] = int(p - 48);
		}
		else if (p == ',') continue;
		else break;
		money = (int *)realloc(money, sizeof(int)*(i + 1));
	}
	cout<<opt(money, i);
	system("pause");
	return 0;
}
int opt(int * money, int num) {
	int * opt_money = (int *)malloc(sizeof(int)*(num + 1));

	for (int i = 0; i < num; i++) {
		if (i == 0) opt_money[i] == money[i];
		else if (i == 1) opt_money[i] = (money[0] > money[1] ? money[0] : money[1]);
		else {
			int A = opt_money[i - 2] + money[i];
			int B = opt_money[i - 1];
			opt_money[i] = A > B ? A : B;
		}
	}
	return opt_money[num - 1];
}