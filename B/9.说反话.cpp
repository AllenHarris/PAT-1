#include <iostream> 
#include <stack>  
using namespace std;

int main(){
	stack<string> s;   // ջ 
	string a;
	while(cin >> a){   // cin ���ո�ֹͣ 
		s.push(a);
	}
	cout << s.top();
	s.pop();
	while(!s.empty()){
		cout << " " << s.top();
		s.pop();
	}
	return 0;
} 
