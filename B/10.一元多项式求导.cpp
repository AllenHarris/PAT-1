#include <iostream>
using namespace std;

int main(){
	int a,b;
	int flag = 0;  // flag�����ж��Ƿ��ǵ�һ����� 
	while(cin >> a >> b){
		if(b==0){
			if(flag==0){
				cout << "0 0";  //��Ϊ��ָ���ݽ�������һ��ָ������0��ֱ����� 0 0 
			}
			return 0;
		}
		if(flag==1){    // �����ǵ�һ����� 
			cout << " ";
		}
		cout << a*b << " " << b-1;
		flag=1;
	}
	if(flag==0){  //��û������ 
		cout << "0 0";
	}
	return 0; 
}
