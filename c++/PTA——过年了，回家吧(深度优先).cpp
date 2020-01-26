#include<iostream>
#include<map>
#include<string>
#include<vector>


using  namespace std;

int n, m;
int ** tran;

int *city_state;
int * c_times;

vector<int> route;
vector<int> min_route;
int sum_time = 0;
int sum_ctime = 0;
int min_time = 9999;
int min_ctime = 9999;

int p = 0;

void dfs(int start, int aim) {

	if (start == aim) {
		p = 1;
		if (min_time >= sum_time && min_ctime >= sum_ctime) {
			min_time = sum_time;
			min_ctime = sum_ctime;

			min_route.clear();
			min_route.assign(route.begin(), route.end());
		}
		return;
	}
	else if (sum_time > min_time) {
		return;
	}

	for (int i = n - 1; i >= 0; --i) {
		if (tran[start][i] != 0 && city_state[i] == 0) {

			sum_time += (tran[start][i] + c_times[i]);
			sum_ctime += 1;
			city_state[i] = 1;

			route.push_back(i);

			dfs(i, aim);

			sum_time -= (tran[start][i] + c_times[i]);
			sum_ctime -= 1;
			city_state[i] = 0;

			route.pop_back();

		}
	}
	return;
}



int main() {


	cin >> n;

	map<string, int > train_index;
	map<int, string> train_back;

	c_times = new int[n];
	city_state = new int[n];

	string train_station;
	int c_time;

	for (int i = 0; i < n; ++i) {
		cin >> train_station >> c_time;
		train_index.insert(make_pair(train_station, i));
		train_back.insert(make_pair(i, train_station));

		c_times[i] = c_time;
		city_state[i] = 0;
	}

	cin >> m;

	tran = new int*[n];
	for (int i = 0; i < n; ++i) {
		tran[i] = new int[n]();
	}

	string begin, end;

	int d_time;//中转时间
	int begin_index, end_index;

	for (int i = 0; i < m; ++i) {
		cin >> begin >> end >> d_time;

		begin_index = train_index[begin];
		end_index = train_index[end];

		tran[begin_index][end_index] = tran[end_index][begin_index] = d_time;
	}

	string start, aim;
	cin >> start >> aim;
	if (train_index.find(start) == train_index.end() || train_index.find(aim) == train_index.end()) {
		goto error;
	}

	int start_index, aim_index;
	start_index = train_index[start];//起点
	aim_index = train_index[aim];//终点

	if (start_index == aim_index) {
		cout << 0 << endl;
		cout << start << endl;

	}
	else {
		city_state[start_index] = 1;


		dfs(start_index, aim_index);

		if (p) {
			cout << min_time - c_times[aim_index] << endl;

			cout << train_back[start_index];
			for (vector<int>::iterator i = min_route.begin(); i != min_route.end(); ++i) {
				cout << "->";
				cout << train_back[*i];
			}
		}
		else {
		error:cout << "Why not go home by plane?" ;
		}
	}

	return 0;
}