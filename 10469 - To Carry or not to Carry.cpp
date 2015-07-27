#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
void circuito_sumador(long long a,long long b){
 
    vector<int> nb;
    vector<int> A1;
    vector<int> B1;
    while(a!=0 || b!=0){
       int byA =  a&1;   A1.push_back(byA);
       int byB =  b&1;   B1.push_back(byB);
        
       if(byB +byA == 2){
              nb.push_back(0);                      
       }else{
             nb.push_back(byB +byA);                                            
       }
       
       a=a>>1;                                      
       b=b>>1;                                     
    }
     
    long long num=0;
    for(int i=0;i<nb.size();i++){
            long long aux = pow(2,i);
            num = num + (nb[i]*aux);                      
    }
     
    cout<<num<<endl;
}
 
int main(){
   long long  a,b;
     
    while(cin>>a>>b){
      
        circuito_sumador(a,b);
    }
}