#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
double d;
int main(){
    string h;
    int va,vo,to=0;
    d=0;
    bool flag=true;

    while(getline(cin,h)){
		  int vaux,tp;
		  int t =(((h[0]-'0')*10+(h[1]-'0')*3600) +(((h[3]-'0')*10+(h[4]-'0'))*60) + ((h[6]-'0')*10+(h[7]-'0')));
		  tp=t-to;
		  if(h.size()>8){
  		   vaux=atoi((h.substr(9,h.size()-9)).c_str());
  		   if(flag)vo=vaux;
		  }
		  if(!flag) d+=(double(tp)/3600.0)*vo;	
		  to=t;
		  if(h.size()>8)vo=vaux,flag = false;
		  else if(h.size()==8){cout<<h<<" ";printf("%.2f",d);cout<<" km"<<endl;}

	}
}
