#include<iostream>
#include<vector>
#include<math.h>
#include <stdlib.h>
using namespace std;
int main(){
	int n;
	while(cin>>n){
		string r="Jolly";
	
		   int aux;
		   vector<int> v;
		   for(int i=0;i<n;i++){
		   	cin>>aux;
		   v.push_back(aux);
		   }
	   if(n>1){
			bool est[n];
			for(int i=1;i<n;i++) est[i]=false;
		   for(int i=1;i<v.size();i++){
				int a=abs(v[i]-v[i-1]);
			if(a<n){est[a]=true;}
		   }
		   for(int i=1;i<n;i++){
				if(est[i]==false){r="Not jolly";i=n;}
		   }
	   }
	   cout<<r<<endl;
			
	}
}
