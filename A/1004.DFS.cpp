#include <iostream> 
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int N=110;
vector<vector<int>> G(N) ;   //��������ڽӱ�
int leaf[N]={0};   //���ÿ��Ҷ�ӽڵ�ĸ���
int max_h=1; //�������

void DFS(int index, int h);

int main(){
	int n,m,parent,child,k;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		cin >> parent >> k;
		for(int j=0;j<k;j++){
			cin >> child;
			G[parent].push_back(child);   //�ӱ�
		}
	}
	DFS(1,1);
	cout << leaf[1];
	for(int i=2;i<=max_h;i++){
		cout << " " << leaf[i];
	}
	return 0;
} 
void DFS(int index, int h){  //indexΪ��ǰ�������Ľ���ţ� hΪ��ǰ���
	max_h=max(max_h,h);
	if(G[index].size()==0){
		leaf[h]++;
		return;
	}
	for(int i=0;i<G[index].size();i++){   //ö�������ӽڵ�
		DFS(G[index][i],h+1);
	}
} 
