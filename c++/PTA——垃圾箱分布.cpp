/*5������4��*/
#include<iostream>
#include<sstream>
#include<string>
#include<map>
#include<cstring>

#define MAX 9999
using namespace std;

int m, n, k, d;
int method = 0;

int citizen[1020][1020];
int dis[1020];

int mchange(string a)//�ı��ţ�ʹ��1~n�Ǿ���㣬n+1�� n+m������Ͱ�㣬��Ϊ��������ַ�����Ҫע���λ��֮��ı�����ϵ��
{
	int len = a.length();
	int ans = 0;
	if (a[0] == 'G')
	{
		for (int i = 1; i < len; ++i)
		{
			ans = ans * 10 + a[i] - '0';//ǰһλ���ȳ�10�ټ��Ϻ�һλ��
		}
		ans += n;//���ϱ��G
	}

	else
	{
		for (int i = 0; i < len; ++i)
		{
			ans = ans * 10 + a[i] - '0';
		}
	}
	return ans;
}

void init() {
	cin >> n >> m >> k >> d;

	memset(citizen, MAX, sizeof(citizen));
	

	string b, e;
	int bi, ei, di;

	for (int i = 0; i < k; ++i) {
		cin >> b >> e >> di;

		bi = mchange(b);
		ei = mchange(e);

		citizen[bi][ei] = citizen[ei][bi] = di;
	}
	return;
}

void mindis(int i) {

	int *state = new int[m + n + 1]();

	memset(dis, MAX, sizeof(dis));
	
	dis[i] = 0;

	while (true)
	{
		int index = 0;

		for (int j = 1; j <= m + n; ++j) {
			if (state[j]) continue;

			if (index==0 || dis[j]<dis[index]) {
				index = j;
			}
		}

		if (index == 0)return;

		state[index] = 1;

		for (int j = 1; j <= m + n; ++j) {
			if (dis[j] > dis[index] + citizen[index][j]) {
				dis[j] = dis[index] + citizen[index][j];
			}
		}
	}

}

int main() {
	init();

	double max_min = 0;
	double max_sum = MAX;
	int index = 0;

	for (int i = n+1; i <= m + n; ++i) {
		mindis(i);


		int flag = 0;
		int sumpath = 0;
		int minpath = MAX;

		for (int j = 1; j <= n; ++j) {
			if (dis[j] > d) {
				
				flag = 1;
				break;
			}
			if (dis[j] < minpath) {
				minpath = dis[j];
			}
			sumpath += dis[j];
		}
		if (flag) continue;

		method++;

		if (max_min < minpath) {

			max_min = minpath;
			max_sum = sumpath;
			index = i;
		}
		else if (max_min == minpath && max_sum > sumpath) {
			max_min = minpath;
			max_sum = sumpath;
			index = i;
		}
	}

	if (method==0) {
		cout << "No Solution";
	}
	else {
		cout << "G" << index-n << endl;
		printf("%.1f %.1f", max_min, (max_sum/n*10.0+0.5)/10.0);
	}

	return 0;
}





