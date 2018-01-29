#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXV=510;
const int INF=1000000000;
int N , M , start , en , G[MAXV][MAXV] , weight[MAXV]; //G���鱣���Ȩ�� �� weight�����Ȩ�أ�
int dis[MAXV] , w[MAXV] , num[MAXV];      //dis ������̾��� �� w ��¼����Ȩ֮�� �� num�������·������
bool visite[MAXV];  //����Ѿ����ʹ��ĵ�

void Dijkstra(int s);

int main(){
	cin >> N >> M >> start >> en ;
	for(int i=0;i<N;i++){
		cin >> weight[i];
	}
	int u,v;
	fill(G[0], G[0]+MAXV*MAXV, INF);
	for(int i=0;i<M;i++){
		cin >> u >> v;
		cin >> G[u][v];
		G[v][u] = G[u][v];  //����ͼ�ǶԳƾ���
	}
	Dijkstra(start);
	cout << num[en] << " " << w[en];
	return 0;
}
void Dijkstra(int s){    //���Ȩͼ�ĵ�Դ���·���㷨����ĳ���㵽�����������·��
	fill(dis,dis+MAXV,INF);  //����Ԫ��ʼ������
	memset(num,0,sizeof(num)); // ���ֽڳ�ʼ������
	memset(w,0,sizeof(w));
	dis[s]=0;   //�����̾�������Ϊ0
	w[s]=weight[s];
	num[s]=1;
	for(int i=0;i<N;i++){
		int u=-1 , MIN=INF;
		for(int j=0;j<N;j++){
			if(visite[j]==false && dis[j]<MIN){
				u=j;
				MIN=dis[j];
			}
		}

		if(u==-1) return ;  // u �������ж��Ƿ��������������������Ķ��㣬��uΪ-1��������ص��Ѿ�������

		visite[u]=true;
		for(int x=0;x<N;x++){
			if(visite[x]==false && G[u][x]!=INF){
				if(dis[u]+G[u][x]<dis[x]){     //�жϼ�x��� �����Ƿ��С
					dis[x] = dis[u] + G[u][x];
					w[x] = w[u]+weight[x];
					num[x]=num[u];
				}else if(dis[u] + G[u][x] == dis[x]){  //�ҵ���ͬ����·��
					if(w[u]+weight[x]>w[x]){
						w[x] = w[u] + weight[x];
					}
					num[x]+=num[u];
				}
			}
		}
	}
}

