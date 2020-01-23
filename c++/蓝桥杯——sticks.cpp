#include<iostream>
#include<algorithm>

#define long long ll
using namespace std;


int wood_length = 0;
int * num, *state;
int p, lenght, lastnum;


int cmp(int a, int b) {
	return a > b;
}
bool dfs(int exist_num, int exist_length) {
	if (exist_num == 0 && exist_length == 0) return true;
	// 木棒用光,剩余长度也为0，成功
	if (exist_num == 0 && exist_length != 0) return false;
	// 木棒用光,还有剩余长度，失败

	if (exist_length == 0) exist_length = lenght;
	// 刚好拼完一根，继续拼下一根

	int s = 0;
	if (exist_length != lenght) s = lastnum + 1;

	for (int i = s; i < p; ++i) {

 		if (!state[i - 1] && num[i] == num[i - 1]) continue;
		//上一根跟当前的长度一样，上一根没用，当前这个肯定也没法用

		if (!state[i] && exist_length >= num[i]) {
			state[i] = 1;
			lastnum = i;

			if (dfs(exist_num - 1, exist_length - num[i])) return true;
			else
			{
				state[i] = 0;
				if (lenght == exist_length || num[i] == exist_length) return false;
				//当前这根长度没法找到其余长度，是他们刚好拼接成功的，意味着这个长度终究会是问题，所以后续的都不用实验了
			}

		}
	}
	return false;
	
}

int  main() {
	
	
	while (cin >> p) {
			if (p == 0) break;

		int sum = 0;//所有棍子的总长度
		int maxlength = -1;//最长的部分

		num = (int *)malloc(sizeof(int)*p);
		state = (int *)malloc(sizeof(int)*p);//木棍使用状态

		for (int i = 0; i < p; ++i) {
			cin >> num[i];
			sum += num[i];
			if (num[i] > maxlength) maxlength = num[i];
		}

		sort(num, num + p,cmp);//降序排列

		for (int i = maxlength; i <= sum/2; ++i) {
			
			if (sum%i) continue;
			else
			cout << i << "\n";

			for (int i = 0; i < p; ++i) {
				state[i] = 0;
			}
			lenght = i;
			if (dfs(p, i)) {
				cout << "r:" << i << endl;
				break;
			
			}

		}
	}
	return 0;
}


