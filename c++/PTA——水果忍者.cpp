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
	sort(l, l + n, cmp);//排一下序，使所有线段按x坐标从小到大排好 
	for (int i = 0; i < n; i++) {//把该线段上的点作为答案直线上的一个点 
		ansmaxk = inf;//初始化经过该线段上点的答案斜率范围 
		ansmink = -inf;
		int j;
		for (j = 0; j < n; j++) {
			if (i != j) {
				if (i < j) {//得到可以同时穿过线段i和j的答案直线的斜率范围 
					maxk = (l[i].miny - l[j].maxy) / (l[i].x - l[j].x);
					mink = (l[i].miny - l[j].miny) / (l[i].x - l[j].x);
				}
				else {
					maxk = (l[j].miny - l[i].miny) / (l[j].x - l[i].x);
					mink = (l[j].maxy - l[i].miny) / (l[j].x - l[i].x);
				}
				if (ansmaxk < mink || ansmink > maxk) break;//以i线段为基础的答案斜率不满足当前同时穿过两线段的斜率范围，说明不能穿过所有线段，直接break
				if (maxk < ansmaxk) {
					ansmaxk = maxk;
					ansx = l[j].x;
					ansy = l[j].maxy;
				}
				ansmink = max(mink, ansmink);
			}
		}
		if (j == n) {//存在经过i线段上点的一个斜率范围所得到的答案直线可以同时穿过所有线段 
			printf("%.0lf %.0lf %.0lf %.0lf\n", l[i].x, l[i].miny, ansx, ansy); //线段i上取了最低点，则另一条线段要取最高点 
			return 0;
		}
	}
}