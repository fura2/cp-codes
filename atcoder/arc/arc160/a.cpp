#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,tar; cin>>n>>tar;
	vector<int> p(n);
	rep(i,n) cin>>p[i], p[i]--;

	vector<int> pos(n);
	rep(i,n) pos[p[i]]=i;

	vector<int> ans=p;
	vector<bool> used(n);
	rep(i,n){
		// determine A[i]
		for(int x=0;x<n;x++){
			if(used[x]) continue;

			// try A[i] = x
			if(p[i]==x){
				int cnt=i+1+(n-i)*(n-i-1)/2;
				if(cnt<tar){
					tar-=cnt;
				}
				else{
					used[x]=true;
					break;
				}
			}
			else{
				tar--;
				if(tar==0){
					reverse(ans.begin()+i,ans.begin()+pos[x]+1);
					rep(i,n) cout<<ans[i]+1<<" ";
					cout<<endl;
					return 0;
				}
			}
		}
	}

	rep(i,n) cout<<ans[i]+1<<" ";
	cout<<endl;

	return 0;
}
