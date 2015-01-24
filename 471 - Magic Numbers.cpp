#include <iostream>
#include <vector>
#include <sstream> 
#include <utility>  
using namespace std;
int num;
bool digit_df(long long n){
	bool exito = true;
	int d[]={0,0,0,0,0,0,0,0,0,0};
		stringstream stream; 
		string number; 
		stream << n; 
		number = stream.str();

	for(int i=0;i<number.size();i++){
		d[number[i]-'0']++;
	}
	for(int i=0;i<10;i++){
		if(d[i]>1){exito=false,i=10;}
	}
	return exito;
}
int main(){
	int t;
	vector<vector<pair<long long,long long> > > rs;
	vector<long long> is;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		long long limit = 9876543210;
		long long i = 1;
		long long temp=1;
		vector<pair<long long,long long> > cs;
		while(temp<=limit){
			temp = n*i;
			if(digit_df(i) &&digit_df(temp)){
				pair<long long,long long> p;
				p.first=temp;p.second=i;
				cs.push_back(p);
			}
			i++;
		}
		rs.push_back(cs);
		is.push_back(n);

	}
	for(int i=0;i<is.size();i++){
		vector<pair<long long,long long> > aux = rs[i];
		for(int j=0;j<aux.size();j++){
			pair<long long,long long> p = aux[j];
			cout<<p.first<<" / "<<p.second<<" = "<<is[i]<<endl;
		}
		if(i!=is.size()-1)cout<<endl;
	}
}