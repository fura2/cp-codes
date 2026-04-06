// Greedy solution

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m;
	string s; cin>>n>>m>>s;

	vector<int> cost(n+1,-1);
	cost[n]=0;
	for(int x=n;x>0;) if(s[x]=='0') {
		int next=-1;
		for(int d=1;d<=m;d++) if(x-d>=0 && s[x-d]=='0') {
			cost[x-d]=cost[x]+1;
			next=x-d;
		}
		x=next;
	}

	if(cost[0]==-1) return puts("-1"),0;

	for(int x=0;x<n;){
		int pre=x;
		for(;cost[x]+1!=cost[pre];x++);
		printf("%d ",x-pre);
	}

	return 0;
}
