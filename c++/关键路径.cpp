#include <iostream>
#include <stdio.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std ;
void initEvent(int eventNumber,int ** eventContainer);
int topoLogicalSort(int eventNumber ,int ** eventContainer,int *earliestTime);
void initEarliestTime(int * earliestTime,int ** eventContainer,int k,int i);
void initLatestTime(int * ealiestTime,int * latestTime ,int ** eventContainer,int eventNumber);
void criticalPath(int * ealiestTime,int * latestTime ,int eventNumber);

int main() {
    int eventNumber;
    cout<<"�����빤��������";
    cin>>eventNumber;
    int ** eventContainer=new int * [eventNumber]();
    int * earliestTime=new int[eventNumber]();
    int * latestTime=new int[eventNumber]();
    initEvent(eventNumber,eventContainer);
    if(!topoLogicalSort(eventNumber,eventContainer,earliestTime)){
        cout<<"����Ĺ���·���ƺ���һЩ����"<<endl;
        return 0;
    }
    cout<<"��õ���Ŀ�������ʱ��Ϊ��";
    for (int j = 0; j < eventNumber; ++j) {
        latestTime[j]=earliestTime[eventNumber-1];
        cout << earliestTime[j] <<" ";
    }
    cout<<endl;
    initLatestTime(earliestTime,latestTime,eventContainer,eventNumber);
    cout<<"��õ���Ŀ������ʱ��Ϊ��";
    for (int j = 0; j < eventNumber; ++j) {
        cout << latestTime[j] <<" ";
    }
    criticalPath(earliestTime,latestTime,eventNumber);
    return 0;
}
void initEvent(int eventNumber,int ** eventContainer){
    if (eventNumber==1){
        cout<<"ֻ��һ�����̣���ô�ؼ���Ŀ��Ϊ�䱾��"<<endl;
        system("pause");
        exit(0);
    }
    for(int i=0;i<eventNumber;++i){
        eventContainer[i]=new int [eventNumber]();
    }
    cout<<"OK!������ÿ��������Ҫ��ִ��ʱ���"<<endl<<"Ĭ�ϴ��¼�1��ʼִ��"<<endl;
    cout<<"�����������¼�֮����Ҫ��ʱ�䣨�޹���������0��������"<<endl;
    for(int i=0;i<eventNumber;++i){
        for(int j=0;j<eventNumber;++j){
            if(i!=j){
                cout << i + 1 << "->" << j + 1 << ":";
                cin >> eventContainer[i][j];
            }
        }
    }

}
int topoLogicalSort(int eventNumber ,int ** eventContainer,int *earliestTime){
    stack<int> eventStack;
    int count ,k;
    int * indegree =new int[eventNumber]();
    for(int i=0;i<eventNumber;++i){
        int sum=0;
        for(int j=0;j<eventNumber;++j){
            if(eventContainer[j][i]!=0) ++sum;
        }
        indegree[i]=sum;
        if(indegree[i]==0) eventStack.push(i);
    }
    count=0;
    while(!eventStack.empty()){
        k=eventStack.top();
        eventStack.pop();
        ++count;
        for(int i=0;i<eventNumber;++i){
            if(eventContainer[k][i]!=0){
                if(!(--indegree[i])) eventStack.push(i);
                initEarliestTime(earliestTime,eventContainer,k,i);
            }
        }
    }
    if(count<eventNumber) return 0;
    else return 1;

}
void initEarliestTime(int * earliestTime,int ** eventContainer,int k,int i){
    if(earliestTime[k]+eventContainer[k][i]>earliestTime[i]) earliestTime[i]=earliestTime[k]+eventContainer[k][i];
}
void initLatestTime(int * ealiestTime,int * latestTime ,int ** eventContainer,int eventNumber){
    for(int i=eventNumber-2;i>=0;--i){
        for(int j=0;j<eventNumber;++j){
            if(eventContainer[i][j]!=0){
                if(latestTime[i]>latestTime[j]-eventContainer[i][j]) latestTime[i]=latestTime[j]-eventContainer[i][j];
            }
            }
    }
}
void criticalPath(int * ealiestTime,int * latestTime ,int eventNumber){
    cout<<"�ؼ���ĿΪ��";
    for(int i=0;i<eventNumber;++i){
        if(ealiestTime[i]==latestTime[i]) cout<<i<<" ";
    }
    return;
}
