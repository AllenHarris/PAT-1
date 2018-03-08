#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int maxn(1010);
struct Node{
	int ID;
	int lev;
};

vector<Node> Adj[maxn]; //�ڽӱ� 
bool inq[maxn]={false}; //�����Ƿ��Ѿ����������

int BFS(int s,int L){  //��ʼ�ڵ�Ͳ������� 
	int numForward=0; //ת����
	queue<Node> q;	//BFS���� 
	Node start;   //������ʼ��� 
	start.ID=s;		//��ʼ����� 
	start.lev=0;	//��ʼ�ڵ���Ϊ0 
	q.push(start);   //����ʼ�ڵ�ѹ����� 
	inq[start.ID]=true;  //��ʼ���ı����Ϊ�ѱ���������� 
	while(!q.empty()){   
		Node top=q.front();
		q.pop();
		int u=top.ID;  //���׽ڵ�ı�� 
		for(int i=0;i<Adj[u].size();i++){
			Node next=Adj[u][i];		//��u�����ܵ���Ľ�� next 
			next.lev=top.lev+1;			
			if(inq[next.ID]==false&&next.lev<=L){
				q.push(next);
				inq[next.ID]=true;
				numForward++;
			}
		}
	} 
	return numForward;
}

int main(){
	Node user;
	int N,L,numFollow,idFollow;
	cin >> N >> L;
	for(int i=1;i<=N;i++){
		user.ID=i;
		scanf("%d",&numFollow);
		for(int j=0;j<numFollow;j++){
			scanf("%d",&idFollow);
			Adj[idFollow].push_back(user);
		}
	}
	int numQuery,s;
	cin >> numQuery;
	for(int i=0;i<numQuery;i++){
		memset(inq,false,sizeof(inq));
		scanf("%d",&s);
		int numForward=BFS(s,L);
		printf("%d\n",numForward);
	}
	return 0;
} 
