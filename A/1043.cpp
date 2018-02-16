#include <iostream>
#include <vector>
using namespace std;

vector<int> pre;
vector<int> post;

bool flag;  //�ж��Ƿ�Ϊ�������������� 

void getPost(int root,int tail){
	if(root>tail){
		return;
	}
	int i=root+1,j=tail;
	if(!flag){     //�Ǿ������������������к������� 
		while(i<=tail && pre[root]>pre[i]) i++;
		while(j>root && pre[root]<=pre[j]) j--;
	}else{
		while(i<=tail && pre[root]<=pre[i]) i++;
		while(j>root && pre[root]>pre[j]) j--;
	}
	if(i-j!=1){
		return ;
	}
	getPost(root+1,j);
	getPost(i,tail);
	post.push_back(pre[root]);
}

int main(){
	int N;
	cin >> N;
	pre.resize(N); 
	for(int i=0;i<N;i++){
		scanf("%d",&pre[i]);
	}
	getPost(0,N-1);
	if(post.size()!=N){   //���������򣬽��о������ 
		flag=true;
		post.clear();
		getPost(0,N-1);
	}
	if(post.size()==N){   //�����򳤶���ԭ������� 
		cout << "YES" << endl;
		for(int i=0;i<N;i++){
			if(i==0){
				cout << post[0];
			}else{
				cout << " " << post[i];
			}
		}
	}else{
		cout << "NO";
	}
	return 0;
}
