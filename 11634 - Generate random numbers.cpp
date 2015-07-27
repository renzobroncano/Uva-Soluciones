#include <iostream>
using namespace std;
int cant_num_aleatorios(int n){
	int c=1, ac=n*n;
	bool v[10000];
	for(int i=0;i<10000;i++)v[i]=false;
	v[n]=true;
	while(true){
		int a1=(ac/100)%10000;
		if(v[a1]==false){
			v[a1]=true;
			ac=a1*a1;
			c++;
		}else{
			break;
		}
	}
	return c;	
}
int main() {
	int n;
	while(cin>>n){
		if(n==0)break;
		cout<<cant_num_aleatorios(n)<<endl;
	}
}