#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;
int main(){
    string h;
    while(cin>>h){
        if(h.size()==4)h="0"+h;
        if(h[0]=='0'&&h[1]=='0'&&h[3]=='0'&&h[4]=='0')break;
        int hr=(h[0]-'0')*10+(h[1]-'0'),mn=(h[3]-'0')*10+(h[4]-'0');
        double r,pa = abs(30*double(hr)-11*(double(mn)/2.0)),sa=360-pa;
        r=pa;
        if(pa>sa)r=sa;
        printf("%.3f\n",r);
    }
}