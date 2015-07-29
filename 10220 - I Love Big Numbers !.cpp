#include <iostream>
#include <map>
#include <string.h>
#include <sstream> 
using namespace std;

string suma(string a,string b){
    int l = 1+(a.length()>b.length()?a.length():b.length());
    string c(l,'0');
    a = string(l-a.length(),'0')+a;
    b = string(l-b.length(),'0')+b;
    int ac = 0,sum =0;
    for(int i=l-1;i>=0;i--){
        sum= a[i]+b[i]-'0'-'0'+ac;
        c[i]=(sum%10)+'0';
        ac=sum/10;
    }
    while(c.length()>0&&c[0]=='0')
    c.erase(c.begin());
    return c;
}

string mult(string a,string b){
    string m,n,r="0";
    int d,ac,prod;
    if(a.length()>b.length())
        m=a,n=b;
    else m=b,n=a;
    while(n.length()>0){
        d=n[n.length()-1]-'0';
        string aux = "0"+m;
        ac=0;
        for(int i=aux.length()-1;i>=0;i--){
            prod=d*(aux[i]-'0')+ac;
            aux[i]=(prod%10)+'0';
            ac=prod/10;
        }
        r=suma(r,aux);
        m=m+"0";
        n.erase(n.end()-1);
    }
    return r;
}
long long sum_factorial(int n){
        string fac = "1";
        long long r =0;
        for(int i=n;i>0;i--){
            stringstream s1;
            s1<<i;
            fac=mult(fac,s1.str());
        }
        for(int i=0;i<fac.size();i++){
            r+=(fac[i]-'0');
        }
        return r;
}
int main(){
    int n;
    while(cin>>n){
        cout<<sum_factorial(n)<<endl;
    }
}