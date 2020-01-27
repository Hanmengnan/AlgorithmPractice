/*8个过了6个*/
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>

#define MAX 9999
using  namespace std;

int m, n;
int num = 1;//树中目前有几个节点
int sum = 0;//生成树权值
int savesum = 0;
int mst_num = 0;
int ** prioty;
int *dis, *state;

vector<int> node;

void init(int n,int m) {
	prioty = new int*[n + 1];
	for (int i = 0; i <= n; ++i) {
		prioty[i] = new int[n + 1]();
		for (int j = 0; j <= n; ++j) {
			if (i != j) prioty[i][j] = MAX;
		}
	}

	for (int i = 0; i < m; ++i) {
		int b, e, p;
		cin >> b >> e >> p;
		prioty[b][e] = prioty[e][b] = p;
	}

	dis = new int[n + 1];
	for (int i = 0; i <= n; ++i) {
		dis[i] = prioty[1][i];
	} 

	state = new int[n + 1]();
	state[0] = state[1] = 1;

	num++;
	return;
}

void mst() {
	sum = 0;
	num = 1;
	while (num <= n)
	{
		int min = MAX;
		int index = 0;
		int p = 0;
		int i;
		for (i = 1; i <= n; ++i) {
			if (!state[i] && dis[i] < min) {
				min = dis[i];
				index = i;
				p = 1;
			}
			
		}
		if (p == 1) {
			node.push_back(index);
			sum += min;
		}
		num++;
		state[index] = 1;

		for (int i = 1; i <= n; ++i) {
			if (!state[i] && dis[i] > prioty[index][i]) {
				dis[i] = prioty[index][i];
			}
		}

	}
}

void only_mst() {
	map<int,vector<int*>> condition;
	vector<int*> temp;

	for (int i = 1; i <= n; ++i) {
		for (int j = i+1; j <= n; ++j) {
			if (condition.find(prioty[i][j]) == condition.end()) {
				temp.clear();
				int edge[2] = { i,j };
				temp.push_back(edge);
				condition.insert(make_pair(prioty[i][j], temp));
			}
			else
			{
				temp = condition[prioty[i][j]];

				int edge[2] = { i,j };
				temp.push_back(edge);
				condition.erase(prioty[i][j]);
				condition.insert(make_pair(prioty[i][j], temp));
			}
			
		}
	}
	/*for (map<int, vector<int*>>::iterator i = condition.begin(); i != condition.end(); ++i) {
		if ((i->second).size() == 1) condition.erase(i->first);
	}*/
	node.insert(begin(node), 1);
	
	savesum = sum;
	
	for (int i = 0; i < node.size(); ++i) {
		int b = node[i];
		int e = node[i + 1];
		int d = prioty[b][e];
		if (condition.find(prioty[b][e]) != condition.end()) {
			prioty[b][e] = prioty[e][b] = MAX;
			
			for (int j = 1; j <= n; ++j) {
				dis[j] = prioty[1][j];
				state[j] = 0;
			}
			state[1] = 1;

			mst();
			int nowsum = sum;
			if (savesum == nowsum) {
				mst_num++;
			}
			prioty[b][e] = prioty[e][b] = d;
		}

	}
}


int connection(vector<int> state) {
	stack<int> visit;
	int figure = 0;
	while (find(state.begin(),state.end(),0)!=state.end())
	{
		int index = find(state.begin(), state.end(), 0)-state.begin();
		state[index] = 1;
		visit.push(index);

		while (!visit.empty())
		{
			index = visit.top();
			visit.pop();

			for (int i = 1; i <= n; ++i) {
				if (prioty[index][i] != MAX && !state[i]) {
					visit.push(i);
					state[i] = 1;
				}
			}
		}
		figure++;
	}
	return figure;
}
int main() {
	cin >> n >> m;
	init(n,m);

	vector<int> tempstate(n+1);
	tempstate[0] = 1;
	int figure=connection(tempstate);

	//存在最小生成树->是否唯一
	
	if (figure == 1) {
		mst();
		//only_mst();

		cout << sum << endl << "Yes" << endl;

		/*if (mst_num == 1) {
			cout << savesum << endl << "Yes" << endl;
		}
		else {
			cout << mst_num << endl << "No" << endl;
		}*/
	}
	else {

		cout << "No MST" << endl << figure << endl;
	}
	

	//不存在->几个连通图
	return 0;
}