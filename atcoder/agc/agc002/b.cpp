#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; cin>>n>>m;
	bool color[100000]={};
	color[0]=true;
	int num[100000];
	rep(i,n) num[i]=1;
	rep(i,m){
		int x,y; cin>>x>>y; x--; y--;
		num[y]++;
		num[x]--;
		if(color[x]){
			color[y]=true;
			if(num[x]==0) color[x]=false;
		}
	}

	cout<<count(color,color+n,true)<<endl;

	return 0;
}
