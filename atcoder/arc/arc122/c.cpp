#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

lint check(vector<int> ans){
	lint x=0,y=0;
	for(int t:ans){
		if(t==1) x++;
		else if(t==2) y++;
		else if(t==3) x+=y;
		else          y+=x;
	}
	return x;
}

int main(){
	lint fib[88]={0,1};
	rep(i,86){
		fib[i+2]=fib[i]+fib[i+1];
	}

	lint n; scanf("%lld",&n);

	vector<int> pos;
	for(int i=87;i>0;i--){
		if(fib[i]<=n){
			n-=fib[i];
			pos.emplace_back(i);
		}
	}

	vector<int> ans={1,2};
	int idx=1;
	rep(i,pos[0]-2){
		if(i%2==0){
			ans.emplace_back(3);
		}
		else{
			ans.emplace_back(4);
		}
		if(idx<pos.size() && pos[0]-pos[idx]==i+2){
			if(i%2==0){
				ans.emplace_back(1);
			}
			else{
				ans.emplace_back(2);
			}
			idx++;
		}
	}

	if(pos[0]%2==0){
		rep(i,ans.size()){
			if(ans[i]%2==1) ans[i]++;
			else            ans[i]--;
		}
	}

	printf("%ld\n",ans.size());
	rep(i,ans.size()) printf("%d\n",ans[i]);

	return 0;
}
