#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n,p,Max(1),a[100010];
	cin >> n >> p;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		//a[i+1] ~ a[n-1] �в��ҵ�һ������a[i]*p��������������λ�� 
		int j=upper_bound(a+i+1,a+n,(long long)a[i]*p)-a;//����a�Ļ��ᱨ�� 
		Max=max(Max,j-i);
	}
	cout << Max<< endl;;
	return 0;
} 
