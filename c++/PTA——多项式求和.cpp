#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
int main()
{
	int n;
	double m;
	double a[30000];	  //��¼ÿһ���ϵ��
	while (cin >> n >> m) //���ö�������
	{
		double fx = 0, x0 = 0;		 //fx�Ƕ���ʽ��ֵ��x0����ÿһ���ֵ
		for (int i = n; i >= 0; i--) //��������ѭ������Ϊ�˷���������ĳ˻��ͼ������һ��
			cin >> a[i];			 //����ϵ��
		for (int i = n; i > 0; i--)
		{
			x0 = a[i] * pow(m, i);
			fx += x0;
		}
		printf("%.3lf\n", fx + a[0]);
	}
	return 0;
}