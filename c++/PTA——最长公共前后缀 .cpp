/*
3个测试点过了2个
*/

#include<iostream>
#include<string>

using namespace std;
int *num;
string str;

void maxnum(int index) {
	
	for (int i = index; i < str.length(); ++i) {

		if (num[i - 1] == 0) {
			if (str[i] == str[0]) {
				num[i] = 1;
			}
		}
		else {
			if (str[i] == str[num[i - 1]]) {
				num[i] = num[i - 1] + 1;
			}
			else {
				int m, n;
				m = n = 0;
				for (int j = i - 1; num[j] != 0; j--) {
					if (str[j] == str[0]) {
						
						if (n == 0) {
							n = j;
						}
						else {
							n = m;
						}
						m = j;
					}
				}
				string s1(str.begin() + n, str.begin() + i+1);
				string s2(str.begin(), str.begin() + i - n+1);
				if (s1==s2) {
					num[i] = i - n + 1;
				}
				else {
					if (str[i] == str[0]) num[i] = 1;
					else num[i] = 0;

				}
			}
		}
	}
}
int main() {

	cin >> str;

	num = new int[str.length()]();
	maxnum(1);
	for (int i = 0; i < str.length(); ++i) {
		cout << num[i] ;
		if (i != str.length() - 1) {
			cout << " ";
		}
	}
	return 0;
}


