#include <iostream>
#include <vector>
#include <iomanip>  
#include <sstream> 
#define MAX 5000
using namespace std;
char m[MAX][MAX];
int p[MAX][MAX];
void init(int h,int w){
	for(int i=0;i<=h+1;i++){
			m[i][0]='1';m[i][w+1]='1';
	}
	for(int j=0;j<=w+1;j++){
			m[0][j]='1';m[h+1][j]='1';
	}
}
int ubicar_punt(int x1, int y1, int x2, int y2){
	int postion =0;
	if(x2<x1)postion=1;
	if(x2>x1)postion=2;
	if(y2>y1)postion=3;
	if(y2<y1)postion=4;
	return postion;
}
void busqueda(int a, int b){
	int x=a,y=b;
	int px=a,py=b+1;
		bool exito = false,inicio = false;
		while(!exito){
			if(x==a && y==b && inicio){
				exito=true;
				return;
			}
			inicio=true;
			int  pq = ubicar_punt(x,y,px,py);
			switch(pq){
				case 1: if(m[x][y+1]=='1' && m[px][py]=='0'){
							x--;px--;p[x][y]++;
						}else{
							if(m[x][y+1]=='1' && m[px][py]=='1'){
								px++,py--;
							}else{
								if(m[x][y+1]=='0'){
									y++;px++;py+=2;p[x][y]++;
								}
							}
						}break;//
				case 2:if(m[x][y-1]=='1' && m[px][py]=='0'){
							x++;px++;p[x][y]++;
						}else{
							if(m[x][y-1]=='1' && m[px][py]=='1'){
								px--,py++;
							}else{
								if(m[x][y-1]=='0'){
									y--;px--;py-=2;p[x][y]++;
								}
							}
						}break;
				case 3:if(m[x+1][y]=='1' && m[px][py]=='0'){
							y++;py++;p[x][y]++;
						}else{
							if(m[x+1][y]=='1' && m[px][py]=='1'){
								px--,py--;
							}else{
								if(m[x+1][y]=='0'){
									x++;py--;px+=2;p[x][y]++;
								}
							}
						}break;
				case 4:if(m[x-1][y]=='1' && m[px][py]=='0'){
							y--;py--;p[x][y]++;
						}else{
							if(m[x-1][y]=='1' && m[px][py]=='1'){
								px++,py++;
							}else{
								if(m[x-1][y]=='0'){
									x--;px-=2;py++;p[x][y]++;
								}
							}
						}break;

			}
		}
}
int main(){
	int h,w;
	vector<vector<int> > sol;
	while(cin>>h>>w){
		if(!h&&!w)break;
		vector<int> vr;
		for(int i=0;i<5;i++){
			vr.push_back(0);
		}
		init(h,w);
		for(int i=1;i<=h;i++){
			string s;cin>>s;
			for(int j=1;j<=w;j++){
				m[i][j]=s[j-1];
			}
		}
		for(int i=1;i<=h;i++){
			for(int j=1;j<=w;j++){
				if(m[i][j]=='1'){
				p[i][j]=-1;
				}else{
					p[i][j]=0;
				}
			}
		}
		busqueda(h,1);
		
		for(int i=1;i<=h;i++){
			for(int j=1;j<=w;j++){
				if(p[i][j]!=-1){
					vr[p[i][j]]++;
				}
			}
		}
		sol.push_back(vr);
	}	
	for(int i=0;i<sol.size();i++){
		vector<int> aux = sol[i];
		for(int j=0;j<aux.size();j++){
			cout<<setw(3)<<aux[j];
		}cout<<endl;
	}
}