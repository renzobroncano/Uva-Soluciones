#include <iostream>
#include <vector>
#define MAX 502
using namespace std;
int board[MAX][MAX];
int main(){
	int w,h,n;
	vector<int> sr;
	while(cin>>w>>h>>n){
		if(!w&&!h&&!n)break;
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				board[i][j]=0;
			}
		}
		int x1,y1,x2,y2;
		for(int i=0;i<n;i++){
			cin>>x1>>y1>>x2>>y2;
			int lxi=x1,lxs=x2,lyi=y1,lys=y2;
			if(x1>x2){lxi=x2;lxs=x1;}
			if(y1>y2){lyi=y2;lys=y1;}
			for(int i=lxi-1;i<=lxs-1;i++){
				for(int j=lyi-1;j<=lys-1;j++){
					board[j][i]=1;
				}
			}
		}
		int cont=0;
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				if(board[i][j]==0){cont++;}
			}
		}
		sr.push_back(cont);
	}
	for(int i=0;i<sr.size();i++){
		if(!sr[i]) cout<<"There is no empty spots."<<endl;
		if(sr[i]==1)cout<<"There is one empty spot."<<endl;
		if(sr[i]>1)cout<<"There are "<<sr[i]<<" empty spots."<<endl;
			
	}
}