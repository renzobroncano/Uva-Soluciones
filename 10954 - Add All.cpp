#include<iostream>
#include<queue>
#include <functional> 
using namespace std;
class mycomparison
{
  bool reverse;
public:
  mycomparison(const bool& revparam=false)
    {reverse=revparam;}
  bool operator() (const int& lhs, const int&rhs) const
  {
    if (reverse) return (lhs>rhs);
    else return (lhs<rhs);
  }
};
int main(){
	int n;
	while(cin>>n){
		if(!n)break;
		priority_queue<int, std::vector<int>, std::greater<int> >Q;
		for(int i=0;i<n;i++){
			int aux;
			cin>>aux;
			Q.push(aux);
		}
		int s=0;
		while(Q.size()>1){
			int p1 = Q.top();
			Q.pop();
			int p2 = Q.top();
			Q.pop();
			Q.push(p1+p2);
			s+=(p1+p2);
		}
		cout<<s<<endl;
	}
}


