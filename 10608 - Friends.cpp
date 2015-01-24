#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 500010
using namespace std;
vector<int> vn(MAX);
int find(int n){
    return (vn[n]==n? n: vn[n]=find(vn[n]));
} 
void Union(int a , int b){
    vn[find(a)] = find(b);    
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,c;
        cin>>n>>c;
        for(int i=0;i<n;i++) vn[i]=i;
        while(c--){
            int ni,nf;
            cin>>ni>>nf;
            Union(ni,nf);
        }
        vector<int> ft(n);
        for(int i=0;i<n;i++)ft[find(i)]++;
        sort(ft.begin(),ft.end());
        cout<<ft[n-1]<<endl;
    }
}
