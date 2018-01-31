#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

long long Map[256] ; //0-9 , a-z
long long inf = (1LL << 63) - 1;  // ȡlong long �����ֵ 2^63-1;
char N1[20],N2[20],temp[20];
int tag,radix; 

void init();
long long convertNum10(char a[],long long radix,long long t);  //aת��Ϊ10���� �� tΪ�Ͻ� 
int cmp(char N2[],long long radix, long long t);  //N2��10������t�Ƚ� 
long long binarySearch(char N2[],long long left,long long right, long long t);  //�������N2�Ľ��� 
int findlargestDigit(char N2[]); //�����λ�� 

int main(){
	init();
	cin >> N1 >> N2 >> tag >> radix;
	if(tag==2){
		swap(N1,N2);
	}
	long long t = convertNum10(N1,radix,inf);  //N1��radix����ת��Ϊʮ���� 
	long long low = findlargestDigit(N2);      //�ҵ�N2����λ����λ+1�����ɶ����½�
	long long high = max(low,t)+1 ;        //�Ͻ�
	long long ans =  binarySearch(N2,low,high,t);  //����
	if(ans==-1){
		cout << "Impossible" << endl;
	} else{
		printf("%lld",ans);
	}
	return 0;
}
 
int findlargestDigit(char N2[]){
	int ans=-1;
	for(int i=0;i<strlen(N2);i++){
		if(Map[N2[i]]>ans){
			ans = Map[N2[i]];
		}
	}
	return ans+1; //������λΪans��˵���������ĵ�����ans+1 
}

long long binarySearch(char N2[],long long left,long long right, long long t){
	long long mid;
	while(left<=right){
		mid = (left+right)/2;
		int flag = cmp(N2,mid,t);  //�ж�N2ת��Ϊ10���ƺ���t�Ƚ� 
		if(flag==0){
			return mid;            // �ҵ��⣬����mid 
		}else if(flag==-1){
			left = mid+1;
		}else{
			right = mid - 1;
		}
	}
	return -1; //�ⲻ���� 
}

int cmp(char N2[],long long radix, long long t){
	long long num = convertNum10(N2,radix,t);
	if(num<0){
		return 1;    //�����N2>t 
	}
	if(t>num){
		return -1; //t�ϴ󣬷���-1�� 
	}else if(t==num){
		return 0;   //��� 
	}else{
		return 1; //num�ϴ󣬷���1 
	}
}

long long convertNum10(char a[],long long radix,long long t){
	long long ans(0);
	for(int i=0;i<strlen(a);i++){
		ans = ans * radix + Map[a[i]]; //����ת��
		if(ans<0 || ans>t){   //����򳬹�N1��ʮ���� 
			return -1;
		} 
	}
	return ans;
}
void init(){
	for(char c = '0';c<='9';c++){
		Map[c] = c-'0';
	}
	for(char c='a';c<='z';c++){
		Map[c] = c - 'a' + 10;
	}
} 
