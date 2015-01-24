#include <iostream>
#include <vector>
#include <sstream> 
using namespace std;

int main(){
	int n;
	vector<string> v;
	vector<string> s; 
	while(cin>>n){
		if(!n)break;
		int sum=0;
		stringstream stream; 
		string num_l; 
		stream << n; 
		num_l = stream.str();
		for(int i =1;i<n;i++){
			 if(n%i==0){
			 	sum+=i;
			 }
		}
		string r;
		if(sum>n)r="  ABUNDANT";
		if(sum<n)r="  DEFICIENT";
		if(sum==n)r="  PERFECT";
		s.push_back(r);
		v.push_back(num_l);
	}
	int l = v[0].size();
	for(int i=1;i<v.size();i++){
		 if(l<v[i].size()) l= v[i].size();
	}

	cout<<"PERFECTION OUTPUT"<<endl;
	for(int i=0;i<s.size();i++){
		 for(int j=0;j<l-v[i].size();j++)cout<<" ";
		 cout<<v[i]<<s[i]<<endl;
	}
	cout<<"END OF OUTPUT"<<endl;
}
