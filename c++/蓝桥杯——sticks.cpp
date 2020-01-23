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
	// ľ���ù�,ʣ�೤��ҲΪ0���ɹ�
	if (exist_num == 0 && exist_length != 0) return false;
	// ľ���ù�,����ʣ�೤�ȣ�ʧ��

	if (exist_length == 0) exist_length = lenght;
	// �պ�ƴ��һ��������ƴ��һ��

	int s = 0;
	if (exist_length != lenght) s = lastnum + 1;

	for (int i = s; i < p; ++i) {

 		if (!state[i - 1] && num[i] == num[i - 1]) continue;
		//��һ������ǰ�ĳ���һ������һ��û�ã���ǰ����϶�Ҳû����

		if (!state[i] && exist_length >= num[i]) {
			state[i] = 1;
			lastnum = i;

			if (dfs(exist_num - 1, exist_length - num[i])) return true;
			else
			{
				state[i] = 0;
				if (lenght == exist_length || num[i] == exist_length) return false;
				//��ǰ�������û���ҵ����೤�ȣ������Ǹպ�ƴ�ӳɹ��ģ���ζ����������վ��������⣬���Ժ����Ķ�����ʵ����
			}

		}
	}
	return false;
	
}

int  main() {
	
	
	while (cin >> p) {
			if (p == 0) break;

		int sum = 0;//���й��ӵ��ܳ���
		int maxlength = -1;//��Ĳ���

		num = (int *)malloc(sizeof(int)*p);
		state = (int *)malloc(sizeof(int)*p);//ľ��ʹ��״̬

		for (int i = 0; i < p; ++i) {
			cin >> num[i];
			sum += num[i];
			if (num[i] > maxlength) maxlength = num[i];
		}

		sort(num, num + p,cmp);//��������

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


