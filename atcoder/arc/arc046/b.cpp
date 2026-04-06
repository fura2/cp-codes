#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int a,b;

// experiment
/*
bool dfs(int n,int turn){
	if(n==0) return false;

	if(turn==0){
		for(int i=1;i<=n&&i<=a;i++){
			if(!dfs(n-i,1-turn)) return true;
		}
		return false;
	}
	else{
		for(int i=1;i<=n&&i<=b;i++){
			if(!dfs(n-i,1-turn)) return true;
		}
		return false;
	}
}
*/

int main(){
	int n; scanf("%d%d%d",&n,&a,&b);

	if     (a<b) puts(n<=a?"Takahashi":"Aoki");
	else if(a>b) puts("Takahashi");
	else         puts(n%(a+1)!=0?"Takahashi":"Aoki");

	return 0;
}
