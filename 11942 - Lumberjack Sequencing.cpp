#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int t;
	vector<string> v;
	cin>>t;
	while(t--){
		bool exito1=true,exito2 =true;
		vector<int> ls;
		vector<int> lsAux;
		vector<int> lsRAux;
		int aux ;
		for(int i=0;i<10;i++) {
			cin>>aux;
			ls.push_back(aux);
			lsAux.push_back(aux);
		}
		sort(lsAux.begin(),lsAux.end());
		for(int i=0;i<lsAux.size();i++){
			lsRAux.push_back(lsAux[i]);
		}
		reverse(lsRAux.begin(),lsRAux.end());
		for(int i=0;i<ls.size();i++){
			if(lsAux[i]!=ls[i]) exito1=false;
		}
		for(int i=0;i<ls.size();i++){
			if(lsRAux[i]!=ls[i]) exito2=false;
		}
		if(!exito1 && !exito2) v.push_back("Unordered");
		else	  v.push_back("Ordered");
	}
	cout<<"Lumberjacks:"<<endl;
	for(int i=0;i<v.size();i++) cout<<v[i]<<endl;
}