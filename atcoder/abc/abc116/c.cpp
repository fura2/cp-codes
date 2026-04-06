#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,h[100]; cin>>n;
	rep(i,n) cin>>h[i];

	int ans=0,y[100]={};
	rep(_,101){
		bool first=true;
		rep(i,n){
			if(y[i]<h[i]){
				y[i]++;
				if(first) first=false, ans++;
			}
			else first=true;
		}
	}
	cout<<ans<<endl;

	return 0;
}
