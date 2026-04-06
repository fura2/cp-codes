#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	a.erase(unique(a.begin(),a.end()),a.end());
	n=a.size();

	if(n==1){ cout<<1<<endl; return 0; }

	int ans=1;
	rep(i,n-1){
		bool flag=(a[i]<a[i+1]);
		for(;i<n-1;i++){
			if     ( flag && a[i]>a[i+1]){ ans++; break; }
			else if(!flag && a[i]<a[i+1]){ ans++; break; }
		}
	}
	printf("%d\n",ans);

	return 0;
}
