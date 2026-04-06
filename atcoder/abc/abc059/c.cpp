#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const lint INF=1LL<<61;

int main(){
	int n; cin>>n;
	vector<int> a(n);
	rep(i,n) cin>>a[i];

	lint ans=INF;
	for(int a0:{1,-1,a[0]}) if(a0!=0) {
		lint tmp=abs(a0-a[0]),sum=a0;
		for(int i=1;i<n;i++){
			sum+=a[i];
			if(sum-a[i]>0){
				if(sum>=0){
					tmp+=sum+1;
					sum=-1;
				}
			}
			else if(sum-a[i]<0){
				if(sum<=0){
					tmp+=1-sum;
					sum=1;
				}
			}
		}
		ans=min(ans,tmp);
	}
	cout<<ans<<endl;

	return 0;
}
