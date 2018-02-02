#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int maxNode=1111;
int N,M,K,query,q;  //����������������������ѯ���� 
int ConvertToMinute(int h,int m){   //ʱ��ת�� 
	return h*60+m;
}

struct Win{
	int endTime,popTime;  //���ڵ�ǰ�����������ʱ�䡢���׿ͻ��ķ������ʱ�� 
	queue<int> q; //���� 
}win[20];

int ans[maxNode],needTime[maxNode];  //�������ʱ��ͷ�����Ҫʱ�� 

int main(){
	int inIndex(0);   //��ǰ��һ��δ��ӵĿͻ���� 
	cin >> N >> M >> K >> query;
	for(int i=0;i<K;i++){
		cin >> needTime[i];
	}
	for(int i=0;i<N;i++){
		win[i].popTime = win[i].endTime = ConvertToMinute(8,0);
	}
	for(int i=0;i<min(N*M,K);i++){
		win[inIndex%N].q.push(inIndex);
		win[inIndex%N].endTime+= needTime[inIndex];
		if(inIndex<N){
			win[inIndex].popTime=needTime[inIndex];
		}
		ans[inIndex] = win[inIndex%N].endTime;
		inIndex++;
	}
	for(;inIndex<K;inIndex++){   //������Ŀͻ� 
		int idx=-1,minPopTime=1<<30;  //1<<30 ��� 
		for(int i=0;i<N;i++){
			if(win[i].popTime<minPopTime){
				idx=i;
				minPopTime=win[i].popTime;
			}
		}
		win[idx].q.pop(); //���׿ͻ��뿪 
		win[idx].q.push(inIndex); //�������Ŷӿͻ�������� 
		win[idx].endTime += needTime[inIndex];//���¸ô��ڶ��еķ������ʱ�� 
		win[idx].popTime += needTime[win[idx].q.front()];//���´��ڶ���ʱ�� 
		ans[inIndex]=win[idx].endTime;
	}
	for(int i=0;i<query;i++){
		cin >> q;  //��ѯ�ͻ���� 
		if(ans[q-1]-needTime[q-1]>=ConvertToMinute(17,0)){
			cout << "Sorry" << endl;
		}else{
			printf("%02d:%02d\n",ans[q-1]/60,ans[q-1]%60);
		}
	}
	return 0;
}
