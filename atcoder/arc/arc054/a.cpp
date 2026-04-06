#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	double l,x,y,s,d;
	cin>>l>>x>>y>>s>>d;

	if(s>d) d+=l;

	cout<<setprecision(9);
	if(x<y){
		cout<<min((d-s)/(x+y),(l-d+s)/(y-x))<<'\n';
	}
	else{
		cout<<(d-s)/(x+y)<<'\n';
	}

	return 0;
}
