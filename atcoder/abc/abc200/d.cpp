#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int n,a[200];

vector<int> res1,res2;
int memo[201][200][200];

bool dfs(int i,int sum1,int sum2){
	if(sum1==sum2 && !res1.empty() && !res2.empty()) return true;
	if(i==n) return false;

	if(!res1.empty() && !res2.empty() && memo[i][sum1][sum2]!=-1){
		return memo[i][sum1][sum2];
	}

	if(dfs(i+1,sum1,sum2)){
		if(!res1.empty() && !res2.empty()) memo[i][sum1][sum2]=1;
		return true;
	}

	sum1=(sum1+a[i])%200;
	res1.emplace_back(i);
	if(dfs(i+1,sum1,sum2)){
		if(!res1.empty() && !res2.empty()) memo[i][sum1][sum2]=1;
		return true;
	}
	res1.pop_back();
	sum1=(sum1-a[i]+200)%200;

	sum2=(sum2+a[i])%200;
	res2.emplace_back(i);
	if(dfs(i+1,sum1,sum2)){
		if(!res1.empty() && !res2.empty()) memo[i][sum1][sum2]=1;
		return true;
	}
	res2.pop_back();
	sum2=(sum2-a[i]+200)%200;

	if(!res1.empty() && !res2.empty()) memo[i][sum1][sum2]=0;
	return false;
}

int main(){
	scanf("%d",&n);
	rep(i,n) scanf("%d",&a[i]), a[i]%=200;

	memset(memo,-1,sizeof memo);
	if(dfs(0,0,0)){
		puts("Yes");
		for(auto res:{res1,res2}){
			printf("%ld ",res.size());
			rep(i,res.size()) printf("%d%c",res[i]+1,i+1<res.size()?' ':'\n');
		}
	}
	else{
		puts("No");
	}

	return 0;
}
