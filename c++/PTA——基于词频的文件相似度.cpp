#include<iostream>
#include<string>
#include<set>

using namespace std;


int main()
{
	int n, m;
	cin >> n;

	set<string> filesystem[100];
	
	for (int i =0; i < n; ++i) {
		string str = "";
		char c=getchar();
;		while ((c = getchar()) != '#') {
			
			if ((c >= 'a'&&c <= 'z') || (c >= 'A'&&c <= 'Z')) {
				if (c <= 'Z') {
					c = c + 32;
				}
				str += c;
			}
			else {
				if (str.length() >= 3){
					if (str.length() > 10) str = str.substr(0,10);
					filesystem[i].insert(str);
				}
				str = "";
			}
			
		}
		
	}

	cin >> m;

	for (int i = 0; i < m; ++i) {
		int file1, file2;
		cin >> file1 >> file2;

		int common = 0;

		for (set<string>::iterator index = filesystem[file1 - 1].begin(); index != filesystem[file1 - 1].end(); index++) {
			if (filesystem[file2 - 1].find(*index) != filesystem[file2 - 1].end()) {
				common++;
			 }
		}
		double result = double(common) / (filesystem[file1-1].size() + filesystem[file2-1].size() - common) * 100;
		printf("%.1f%%\n", result);
	}


	return 0;
}