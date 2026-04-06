#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m;
	string s,t; cin>>n>>m>>s>>t;

	int hist[128]={};
	for(char c:s) hist[c]++;

	rep(i,100){
		if(count(hist,hist+128,0)==128) return printf("%d\n",i),0;
		for(char c:t) if(hist[c]>0) hist[c]--;
	}
	puts("-1");

	return 0;
}
