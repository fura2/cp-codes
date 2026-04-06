#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; cin>>n>>m;
	vector<pair<int,int>> I[30];
	rep(i,n){
		int s,t,c; cin>>s>>t>>c; c--;
		I[c].emplace_back(s,t);
	}

	rep(c,m){
		sort(I[c].begin(),I[c].end());

		vector<pair<int,int>> J;
		int k=I[c].size();
		rep(i,k){
			if(i==k-1 || I[c][i].second!=I[c][i+1].first)
				J.emplace_back(I[c][i]);
			else
				I[c][i+1].first=I[c][i].first;
		}
		I[c]=J;
	}

	int sum[100002]={};
	rep(c,m) for(auto J:I[c]) {
		sum[J.first]++;
		sum[J.second+1]--;
	}
	rep(i,100001) sum[i+1]+=sum[i];

	cout<<*max_element(sum,sum+100002)<<endl;

	return 0;
}
