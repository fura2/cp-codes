#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> x(n);
	rep(i,n) scanf("%d",&x[i]), x[i]--;

	vector<int> p(n);
	iota(p.begin(),p.end(),0);
	sort(p.begin(),p.end(),[&](int i,int j){
		return x[i]<x[j];
	});

	// x[i] が小さい数から順に, 必要な分だけ左詰めで埋める
	int pos=0;
	vector<int> a(n*n,-1);
	for(int i:p){
		int cnt=0;
		while(pos<x[i] && cnt<i){
			if(a[pos]==-1){
				a[pos]=i;
				cnt++;
			}
			pos++;
		}
		if(cnt!=i){
			puts("No");
			return 0;
		}
		a[x[i]]=i;
	}

	// 残りを埋める
	int idx=0,cnt=0;
	rep(i,n*n) if(a[i]==-1) {
		while(cnt==n-p[idx]-1){
			idx++;
			cnt=0;
		}
		a[i]=p[idx];
		cnt++;
	}

	vector P(n,vector<int>());
	rep(i,n*n) P[a[i]].emplace_back(i);
	rep(i,n) if(P[i][i]!=x[i]) {
		puts("No");
		return 0;
	}

	puts("Yes");
	rep(i,n*n) printf("%d%c",a[i]+1,i<n*n-1?' ':'\n');

	return 0;
}
