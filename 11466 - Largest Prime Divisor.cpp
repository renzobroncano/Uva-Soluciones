#include <iostream>
#include <map>
#include <cmath>
using namespace std;
map<long long,int> fact_primo(long long x){
	map<long long,int> res;
	while(x%2==0){x/=2;res[2]++;}
	long long c =3;
	while(c<=sqrt(x)+1)
		if(x%c==0){x/=c;res[c]++;}
		else c+=2;
		if(x>1)res[x]++;
	return res;
}
 
int main() {
	long long n;
	while(cin>>n){
		if(n==0)break;
		map<long long,int> mf = fact_primo(n);
		long long  maxfac = -1;
		if(mf.size()!=1){
			for (map<long long,int>::iterator it=mf.begin(); it!=mf.end(); ++it)
				if(it->first>maxfac) maxfac = it->first;
		}
		cout<<maxfac<<endl;

	}
}


