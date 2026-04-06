#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; cin>>n>>k;

	if((n-1)*(n-2)/2<k){
		cout<<-1<<endl;
	}
	else{
		vector<pair<int,int>> ans;
		rep(i,n-1) ans.emplace_back(i,n-1);

		int num=(n-1)*(n-2)/2;
		rep(i,n-1) for(int j=i+1;j<n-1;j++) {
			if(num>k){
				ans.emplace_back(i,j);
				num--;
			}
		}
		cout<<ans.size()<<endl;
		for(auto e:ans) cout<<e.first+1<<" "<<e.second+1<<endl;
	}

	return 0;
}
