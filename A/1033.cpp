#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn(510);
const int inf(1000000000);
struct station {
	double price,dis;
}st[maxn];

bool cmp(station a,station b){
	return a.dis<b.dis;
} 

int main(){
	int n;
	double T,D,AVG;
	scanf("%lf%lf%lf%d",&T,&D,&AVG,&n); 
	for(int i=0;i<n;i++){
		cin >> st[i].price >> st[i].dis;
	}
	st[n].price=0;
	st[n].dis=D;    //�����յ�
	sort(st,st+n,cmp);
	if(st[0].dis!=0){
		cout << "The maximum travel distance = 0.00" << endl;
	}else{
		int now(0); //��ǰ�����ļ���վ���
		double ans,t,MAX=T*AVG; //�ܻ��ѣ���ǰ��������������ʻ����
		while(now<n){   //ÿ��ѭ��ѡ����һվ����վ��λ�� 
			int k(-1);
			double priceMIN=inf;
			for(int i=now+1;i<=n&&st[i].dis-st[now].dis<=MAX;i++){
				if(st[i].price<priceMIN){
					priceMIN=st[i].price;
					k=i;
					if(priceMIN<st[now].price){
						break;
					}
				}
			}
			if(k==-1) break; //����״̬���޷��ҵ�����վ���˳�ѭ��
			double need=(st[k].dis-st[now].dis)/AVG; //�ӵ�ǰվ�㵽��һ��վ����Ҫ������
			if(priceMIN<st[now].price){
				if(t<need){
					ans+=(need-t)*st[now].price;
					t=0;
				}else{
					t-=need;
				}
			} else{
				ans+=(T-t)*st[now].price;
				t=T-need;
			}
			now=k; //����K����վ��������һ��ѭ�� 
		} 
		if(now==n){ //�ܵ����յ� 
			printf("%.2f\n",ans);
		}else{  //���� 
			printf("The maximum travel distance = %.2f\n",st[now].dis+MAX);
		}
	}
	return 0;
}
