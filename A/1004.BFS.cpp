#include <cstdio>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

const int N=110;

vector<int> G[N];  //��
int h[N]={0};         //����������Ĳ��
int leaf[N]={0};     //���ÿ���Ҷ�ӽڵ����
int max_h=0;       //����������

void BFS();

int main(){
	int n,m;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int parent,k,child;
		cin >> parent >> k;
		for(int j=0;j<k;j++){
			cin >> child;
			G[parent].push_back(child);
		}
	} 
	h[1]=1;   //��ʼ�����ڵ�
	BFS();
	for(int i=1;i<=max_h;i++){
		if(i==1) cout << leaf[i];
		else cout << " " << leaf[i];
	}
	return 0; 
}

void BFS(){
	queue<int> Q;
	Q.push(1);    //�����ڵ�ѹ�����
	while(!Q.empty()){
		int id = Q.front();  //�������׽ڵ�
		Q.pop();
		max_h=max(max_h,h[id]);  //����������
		if(G[id].size()==0){    //�ж��Ƿ�ΪҶ�ӽڵ�
			leaf[h[id]]++;
		}
		for(int i=0;i<G[id].size();i++){
			h[G[id][i]] = h[id]+1;   //�ӽڵ���ΪG[id][i]
			Q.push(G[id][i]);   
		}
	}
}
