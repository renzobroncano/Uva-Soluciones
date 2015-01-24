#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	string s;
	while(getline(cin,s)){
	map<char,int> m;
	for(int i=0;i<s.size();i++){
		if(s[i]!=' ' && ((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z'))){
			m[s[i]]++;
		}
	}
	vector<char> cls;
	map<char,int>::iterator it ;
	int valMax = 0;
	for(it=m.begin();it!=m.end();it++){
		if(it->second > valMax){
			valMax = it -> second;
		}
	}
	for(it=m.begin();it!=m.end();it++){
		if(it->second == valMax){
			cls.push_back(it->first);
		}
	}

	sort(cls.begin(),cls.end());
	string rs="";
	for(int i=0;i<cls.size();i++){
		rs += cls[i];
	}
	if(cls.size()!=0)
	cout<<rs<<" "<<valMax<<endl;
	}

}