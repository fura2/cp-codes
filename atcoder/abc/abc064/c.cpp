#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;

	int arb=0;
	bool color[8]={};
	rep(i,n){
		int a; cin>>a;
		if(a<3200) color[a/400]=true;
		else       arb++;
	}

	int c=count(color,color+8,true);
	cout<<max(c,1)<<' '<<c+arb<<endl;

	return 0;
}
