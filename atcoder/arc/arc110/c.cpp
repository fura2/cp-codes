#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> p(n);
	rep(i,n) scanf("%d",&p[i]), p[i]--;

	vector<int> pos(n);
	rep(i,n) pos[p[i]]=i;

	vector<int> ans;
	vector<bool> used(n-1);
	rep(x,n){
		int i=pos[x];
		while(x<i){
			if(used[i-1]){
				puts("-1");
				return 0;
			}
			used[i-1]=true;
			pos[p[i]]=i-1;
			pos[p[i-1]]=i;
			swap(p[i-1],p[i]);
			ans.emplace_back(i-1);
			i--;
		}
	}

	if(ans.size()==n-1){
		rep(i,n-1) printf("%d\n",ans[i]+1);
	}
	else{
		puts("-1");
	}

	return 0;
}
