#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int n,tar[3],l[8];

int sum[4],cost;

int dfs(int i){
	if(i==n){
		if(sum[0]==0 || sum[1]==0 || sum[2]==0) return INF;

		int res=INF,p[]={0,1,2};
		do{
			int tmp=cost;
			rep(j,3) tmp+=abs(tar[j]-sum[p[j]]);
			res=min(res,tmp);
		}while(next_permutation(p,p+3));
		return res;
	}

	int res=INF;
	rep(j,4){
		if(j<3 && sum[j]>0) cost+=10;
		sum[j]+=l[i];
		res=min(res,dfs(i+1));
		sum[j]-=l[i];
		if(j<3 && sum[j]>0) cost-=10;
	}
	return res;
}

int main(){
	cin>>n;
	rep(i,3) cin>>tar[i];
	rep(i,n) cin>>l[i];

	cout<<dfs(0)<<endl;

	return 0;
}
