#include <iostream>
#include <vector>
using namespace std;
int main(){
	string s;
	vector<int> sol;
	while(getline(cin,s)){
		if(s=="Game Over")break;
		int score =0;
		string cad="";
		for(int i=0;i<s.size();i++){
			if(s[i]!=' ') cad+=s[i];
		}
		int iCad[cad.size()];
		for(int i=0;i<cad.size();i++){
			if(cad[i]=='X') iCad[i]=10;
			else	if(cad[i]=='/') iCad[i]= 10 - (cad[i-1]-'0');
			else	iCad[i]=(cad[i]-'0');
		}
		int i=0;
		int cf =0;
		while(i<cad.size() && cf<10){
			if(cad[i]=='X'){
				score+=iCad[i]+ iCad[i+1] +iCad[i+2];
				i++;
			}else{
				if(cad[i]>=48&&cad[i]<=57){
					if(cad[i+1]>=48&&cad[i+1]<=57){ score+=(iCad[i]+iCad[i+1]);}
					if(cad[i+1]=='/'){ score+=(iCad[i]+iCad[i+1]+iCad[i+2]);}

					i+=2;
				}			
			}
			cf++;
		}
		sol.push_back(score);
	}
	for(int i=0;i<sol.size();i++) cout<<sol[i]<<endl;
}