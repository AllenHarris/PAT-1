#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n;
	double sum(0);
	cin >> n;
	vector<double> N(n);
	
	for(int i=0;i<n;i++){
		cin >> N[i];
		sum+= ((i+1)*N[i]*(n-i)); // λ��*��*�������������µ����ָ��� 
	}
	printf("%0.2f",sum);
	return 0;
	
}
