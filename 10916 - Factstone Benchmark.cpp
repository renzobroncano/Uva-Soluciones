#include<iostream>
using namespace std;

int main(){
		int n;
		while(cin>>n){
			if(n==0)break;
			int i=2;e = (n/10)-195;
			long long v = pow(double(2),e+1);
			long long va =0;
			while(v>va){
				va+=log2(i);
				i++;
			}
			cout<<i<<endl;

		}
}