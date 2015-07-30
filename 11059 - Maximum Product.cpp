#include <iostream>
#include <vector>
#include <algorithm>  
using namespace std;
int main(){
    int n;
    vector<long long> r;
    while(cin>>n){
        vector<long long> V(n);
        vector<long long> ac(n);
        for(int i=0;i<n;i++){
            cin>>V[i];
        }
        long long MaxValue = 0;
        for(int i=0;i<V.size();i++)if(MaxValue<V[i])MaxValue=V[i];
        for(int i=0;i<V.size();i++){
            long long  aux =V[i];
            int j=i+1;
            if(MaxValue<aux)MaxValue=aux;
            while(j<V.size()){
                aux=aux*V[j];
                if(MaxValue<aux)MaxValue=aux;
                //if(i==1)cout<<"Fac:"<<V[j]<<"Resultado:"<<aux<<endl;
                j++;
            }
        }
        if(MaxValue<V[V.size()-1])MaxValue=V[V.size()-1];
        r.push_back(MaxValue);
    }
    for(int i=0;i<r.size();i++){
        cout<<"Case #"<<(i+1)<<": The maximum product is "<<r[i]<<"."<<endl;
        if(i!=r.size()-1)cout<<endl;
    }
} 