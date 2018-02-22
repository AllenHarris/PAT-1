#include <cstdio>
#include <algorithm>
using namespace std;

struct node{
	int v,height; // vΪ���Ȩֵ��heightΪ��ǰ�����߶� 
	node *lchild,*rchild;
}*root;

node* newNode(int v){			//����һ���½�㣬vΪ���Ȩֵ 
	node* Node=new node;  //����һ��node���ͱ����ĵ�ַ�ռ� 
	Node->v=v;
	Node->height=1;
	Node->lchild=Node->rchild=nullptr;
	return Node;
} 

int getHeight(node* root){  	//��ȡ��rootΪ�����������ĵ�ǰ�߶� 
	if(root==nullptr){
		return 0;
	}
	return root->height;
}

void updateHeight(node* root){
	root->height=max(getHeight(root->lchild),getHeight(root->rchild))+1;
}

int getBalanceFactor(node* root){		//������root��ƽ������ 
	return getHeight(root->lchild)-getHeight(root->rchild);
}

void L(node* &root){  //����  
	node* temp=root->rchild;
	root->rchild=temp->lchild;
	temp->lchild = root;
	updateHeight(root);
	updateHeight(temp);
	root=temp;
} 

void R(node* &root){
	node* temp=root->lchild;
	root->lchild=temp->rchild;
	temp->rchild=root;
	updateHeight(root);
	updateHeight(temp);
	root=temp;
}

void insert(node* &root,int v){
	if(root==nullptr){
		root=newNode(v);
		return;
	}
	if(v<root->v){
		insert(root->lchild,v);
		updateHeight(root);
		if(getBalanceFactor(root)==2){
			if(getBalanceFactor(root->lchild)==1){
				R(root);
			}else if(getBalanceFactor(root->lchild)==-1){
				L(root->lchild);
				R(root);
			}
		}
	}else{
		insert(root->rchild,v);
		updateHeight(root);
		if(getBalanceFactor(root)==-2){   
			if(getBalanceFactor(root->rchild)==-1){		 //RR�� 
				L(root);
			}else if(getBalanceFactor(root->rchild)==1){  //RL�� 
				R(root->rchild);
				L(root);
			}
		}
	}
}

node* Create(int data[],int n){  //AVL���Ľ��� 
	node *root = nullptr;
	for(int i=0;i<n;i++){
		insert(root,data[i]);
	}
	return root;
}

int main(){
	int n,v;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&v);
		insert(root,v);
	}
	printf("%d\n",root->v);
	return 0;
}
