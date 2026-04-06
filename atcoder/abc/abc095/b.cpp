#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,x; cin>>n>>x;
	int mn;
	rep(i,n){
		int a; cin>>a;
		x-=a;
		if(i==0 || mn>a) mn=a;
	}
	cout<<n+x/mn<<endl;

	return 0;
}
