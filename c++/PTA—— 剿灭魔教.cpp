#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

	int t, n, m;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		vector<vector<int>> pre_work(n + 1);
		vector<int> state(n + 1);
		if (m == 0) {
			for (int i = 1; i < n + 1; ++i) {
				cout << i << " ";
			}
			cout << endl;
			continue;
		}
		else {
			int pre, aim;
			for (int i = 0; i < m; ++i)
			{
				cin >> aim >> pre;
				if (aim == pre) {
					goto error;
				}
				pre_work[aim].push_back(pre);
			}

			int f, p;
			p = 0;
		next:
			f = 0;
			for (int i = 1; i < state.size(); ++i)
			{
				if (state[i] == 0 && pre_work[i].empty())
					//寻找安装之前不需要安装其他零件的零件
				{
					f = 1;
					p++;
					for (int j = 1; j < n + 1; ++j)
					{
						if (find(pre_work[j].begin(), pre_work[j].end(), i) != pre_work[j].end())
							pre_work[j].erase(remove(pre_work[j].begin(), pre_work[j].end(), i), pre_work[j].end());
					}
					cout << i << " ";
					state[i] = 1;
				}
			}
			if (f == 0 and p < n)
				//找不到
			{
			error:cout << "-1 " << endl;
				continue;
			}
			else if (f == 1 and p < n)
			{

				goto next;
			}
			cout << endl;
		}
	}
	return 0;
}