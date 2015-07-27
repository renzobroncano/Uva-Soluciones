#include<iostream>
#include<cmath>
using namespace std;
int main(){
     long long n;
     while(cin>>n){
           if(n==0)break;
           string c;
           double r = sqrt(n);
           int re = (int)r;
           if(double(re)==r) c="yes";
           else c="no";
           cout<<c<<endl;
     }
}