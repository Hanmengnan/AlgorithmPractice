#include<iostream>
#include<algorithm>
#define inf 0x3f3f3f3f
using namespace std;
int n;
double maxk, mink, ansmaxk, ansmink, ansx, ansy;
struct line {
	double x, maxy, miny;
}l[10010];
int cmp(line a, line b) {
	if (a.x < b.x) return 1;
	return 0;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lf%lf%lf", &l[i].x, &l[i].maxy, &l[i].miny);
	sort(l, l + n, cmp);//��һ����ʹ�����߶ΰ�x�����С�����ź� 
	for (int i = 0; i < n; i++) {//�Ѹ��߶��ϵĵ���Ϊ��ֱ���ϵ�һ���� 
		ansmaxk = inf;//��ʼ���������߶��ϵ�Ĵ�б�ʷ�Χ 
		ansmink = -inf;
		int j;
		for (j = 0; j < n; j++) {
			if (i != j) {
				if (i < j) {//�õ�����ͬʱ�����߶�i��j�Ĵ�ֱ�ߵ�б�ʷ�Χ 
					maxk = (l[i].miny - l[j].maxy) / (l[i].x - l[j].x);
					mink = (l[i].miny - l[j].miny) / (l[i].x - l[j].x);
				}
				else {
					maxk = (l[j].miny - l[i].miny) / (l[j].x - l[i].x);
					mink = (l[j].maxy - l[i].miny) / (l[j].x - l[i].x);
				}
				if (ansmaxk < mink || ansmink > maxk) break;//��i�߶�Ϊ�����Ĵ�б�ʲ����㵱ǰͬʱ�������߶ε�б�ʷ�Χ��˵�����ܴ��������߶Σ�ֱ��break
				if (maxk < ansmaxk) {
					ansmaxk = maxk;
					ansx = l[j].x;
					ansy = l[j].maxy;
				}
				ansmink = max(mink, ansmink);
			}
		}
		if (j == n) {//���ھ���i�߶��ϵ��һ��б�ʷ�Χ���õ��Ĵ�ֱ�߿���ͬʱ���������߶� 
			printf("%.0lf %.0lf %.0lf %.0lf\n", l[i].x, l[i].miny, ansx, ansy); //�߶�i��ȡ����͵㣬����һ���߶�Ҫȡ��ߵ� 
			return 0;
		}
	}
}