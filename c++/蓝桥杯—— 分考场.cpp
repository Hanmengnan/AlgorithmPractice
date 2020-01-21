#include<iostream>
#include<stdlib.h>


using namespace std;

int student_recognize[101][101] = { 0 };//学生相识情况

int room_detail[101][101] = { 0 };//房间内成员详细信息

int room_student_num[101] = { 0 };//房间内有多少人

int m, n;

int minnum_of_room;


void dfs(int stu_num,int room_num) {
	if (room_num>=minnum_of_room) {
		//当前所用房间数超过已知的最小房间数，就不用测试了
		return ;
	}
	if (stu_num > n) {
		//所有学生已经分配房间
		//???????
		minnum_of_room = minnum_of_room < room_num ? minnum_of_room : room_num;
		return ;
	}

	for (int i = 1; i <= room_num; i++)
	{
		int recent_room_student_num=room_student_num[i];
		int recent_room_recognize_student=0;

		for (int  j = 1; j <= recent_room_student_num; j++)
		{
			if(student_recognize[room_detail[i][j]][stu_num]!=1){
				recent_room_recognize_student++;
			}
			/* 目前房间有多少人不认识这个学生 */
		}
		if(recent_room_recognize_student==recent_room_student_num){
			room_student_num[i]++;
			room_detail[i][room_student_num[i]]=stu_num;
			dfs(stu_num+1,room_num);
			room_student_num[i]--;
		}
		
		/* 将新加入的学生插入到已有房间 */
	}

	// 为其单独新建一个房间，是否会对总体情况起到作用？
	room_num++;
	room_student_num[room_num]++;
	room_detail[room_num][room_student_num[room_num]]=stu_num;
	dfs(stu_num+1,room_num);
	room_student_num[room_num]--;
	room_num--;
	

}
int main() {

	
	cin >> n >> m;
	minnum_of_room = n;//最坏的情况是一个人一个房间

	for (int i = 0; i < m; ++i) {
		int p1, p2;
		cin >> p1 >> p2;
		
		student_recognize[p1][p2] = 1;
		student_recognize[p2][p1] = 1;
	}//读入成员的相识情况

	dfs(1,0);//初始1个成员，0个房间
	cout<<minnum_of_room;
	/*system("pause");*/
	return 0;
}