#define _CRT_SECURE_NO_WARNINGS


#include<iostream>
#include<stdlib.h>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;

long long  c_change(string opnum, int jinzhi) {

	long long ans = 0, arg = 1;
	for (int i = opnum.size() - 1; i > 0; --i)
	{
		if (opnum[i] <= '9') { ans += (opnum[i] - '0')*arg; }
		else { ans += (opnum[i] - 'A' + 10)*arg; }
		arg *= jinzhi;
	}
	return ans;
}
string o_change(long long sum, long long jinzhi) {
	string result = "";
	long long temp;
	string temps;
	while (sum / jinzhi != 0)
	{
		temp = sum % jinzhi;
		if (temp > 9) {
			temps = (temp - 10) + 'A';
		}
		else {

			temps = temp + '0';
		}
		result += temps;
		sum /= jinzhi;
	}

	temp = sum % jinzhi;
	if (temp > 9) {
		temps = (temp - 10) + 'A';
	}
	else {
		char * c = NULL;
		temps = temp + '0';
	}
	result += temps;

	reverse(result.begin(), result.end());

	return result;
}
int main() {
	freopen("./input1.txt", "r", stdin);
	int n, jinzhi, op;
	jinzhi = 10, op = 0;
	cin >> n;
	long long sum = 0;

	int index;
	for (int i = 0; i <= n; ++i) {
		if (i == 0) {
			getchar();
			continue;
		}

		string instruction;
		string ins;
		string  opnum;

		char tempc;
		while ((tempc = getchar()) != '\n')
		{
			instruction += tempc;
		}

		index = int(instruction.find(" "));
		if (index == -1) {
			ins = instruction;
		}
		else {
			ins = instruction.substr(0, index);
			opnum = instruction.substr(index);
		}

		if (ins == "CLEAR") {
			sum = 0;
			op = 0;
		}

		else if (ins == "NUM") {
			long long cnum = c_change(opnum, jinzhi);

			switch (op)
			{
			case 0:
				sum = cnum;
				break;
			case 1:
				sum += cnum;
				break;
			case 2:
				sum -= cnum;
				break;
			case 3:
				sum *= cnum;
				break;
			case 4:
				sum /= cnum;
				break;
			case 5:
				sum %= cnum;
				break;

			}
		}
		else if (ins == "EQUAL") {

			if (jinzhi != 10) {
				string result = o_change(sum, jinzhi);
				cout << result << endl;
			}
			else {
				cout << sum << endl;
			}


		}
		else if (ins == "CHANGE") {
			jinzhi = atoi(opnum.c_str());
		}
		else if (ins == "ADD") {
			op = 1;
		}
		else if (ins == "SUB") {
			op = 2;
		}
		else if (ins == "MUL") {
			op = 3;
		}
		else if (ins == "DIV") {
			op = 4;
		}
		else if (ins == "MOD") {
			op = 5;
		}
	}
	system("pause");
	return 0;
}