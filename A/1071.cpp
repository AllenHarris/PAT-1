#include <iostream>
#include <map>
#include <string>
#include <cctype>
using namespace std;

int main(){
	string s,w;
	map<string,int> m;
	getline(cin,s);
	for(int i=0;i<s.length();i++){
		if(isalnum(s[i])){   //�ж��ַ��Ƿ�Ϊ��Сд��ĸ��0��~��9���ַ� 
			s[i]=tolower(s[i]);  
			w+=s[i];
		}else{
			if(w.length()){
				m[w]++;
			}
			w="";//���ã�׼���ж���һ������ 
		}
	}
	if(w.length()){   //�������ж�һ�Σ����������һ���Ϸ����� 
		m[w]++;
	}
	int MAX=0;
	for(auto it=m.begin();it!=m.end();it++){
		if(it->second>MAX){
			MAX=it->second;
			w=it->first;
		}
	}
	cout << w << " " << MAX << endl;
	return 0;
}
