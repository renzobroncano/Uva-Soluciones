#include <iostream>
#define MAX 100
using namespace std;
long long binomial_coef(int n,int m){
    int i,j;
    long long bc[MAX][MAX];
    for(i=0;i<=n;i++)bc[i][0]=1;
    for(j=0;j<=n;j++)bc[j][j]=1;
    for(i=1;i<=n;i++){
        for(j=1;j<i;j++){
            bc[i][j]=bc[i-1][j-1]+bc[i-1][j];
        }
    }
    return bc[n][m];
    
}
int main(){
    long long c;
    while(cin>>c){
            int r=1;
            int nc=1;
            while(c!=nc){
                r++;
                nc=binomial_coef(2*r,r)/(1+r);
            }
            cout<<r<<endl;
    }
}