#include<iostream>
#include <cstdio>
#include <string.h>
#define N 5000
using namespace std;
bool v[N];

void criba (){
    memset (v, true, sizeof (v));
    v [0] = v [1] = false;
 
    for ( int i = 4; i < N; i += 2 )
        v [i] = false;
 
    for ( int i = 3; i * i <= N; i++ ) {
        if ( v [i] ) {
            for ( int j = i * i; j < N; j += 2 * i )
                v [j] = false;
        }
    }
}
int main(){
	string s;
	criba();
	while(cin>>s){
		int a=0;
		for(int i=0;i<s.size();i++){
		   if(s[i]>='a' && s[i]<='z') a+=char(s[i]-48)-'0';
		   else if(s[i]>='A' && s[i]<='Z') a+=(char(s[i]-16)-'0')+26;
		}
		cout<<((v[a]||a==1)?"It is a prime word.":"It is not a prime word.")<<endl;
	}
}
