/*
A1 = �ܱ�5����������������ż���ĺͣ�
A2 = ����5������1�����ְ�����˳����н�����ͣ�������n1-n2+n3-n4...��
A3 = ��5������2�����ֵĸ�����
A4 = ��5������3�����ֵ�ƽ��������ȷ��С�����1λ��
A5 = ��5������4��������������֡�
*/
#include <iostream>
using namespace std;

int main(){
	int M1=0,M2=0,M3=0,M4=0,M5=0;
	int A1=0,A2=0,A3=0,A5=0;
	double A4;
	int n , cnt = 0,flag=1;
	cin >> n;
	int *a = new int [n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=0;i<n;i++){
		int temp = a[i]%5;
		switch(temp){
			case 0:
				if(a[i]%2==0) {
					A1+=a[i];
					M1=1;
				}
				break;
			case 1:
				a[i]*=flag;
				A2+=a[i];
				flag*= (-1);
				M2=1;
				break;
			case 2:
				A3++;
				M3=1;
				break;
			case 3:
				A4+=a[i];
				M4=1;
				cnt++;
				break;	
			case 4:
				if(A5<a[i])	{
					A5=a[i];
				}
				M5=1;
				break;	
		}
	}
	if(M1==1){
		cout << A1 << " ";
	}else{
		cout << "N ";
	}
	if(M2==1){
		cout << A2 << " ";
	}else{
		cout << "N ";
	}
	if(M3==1){
		cout << A3 << " ";
	}else{
		cout << "N ";
	}
	if(M4==1){
		printf("%.1f ",A4/cnt);
	}else{
		cout << "N ";
	}
	if(M5==1){
		cout << A5 ;
	}else{
		cout << "N";
	}
	delete [] a;
	return 0;
}
