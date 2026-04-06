#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	sort(a.begin(),a.end());

	int ans=0;
	rep(i,n){
		for(int j=i+1;j<n;j++) if(a[i]<a[j]) {
			for(int k=j+1;k<n;k++) if(a[j]<a[k]) {
				if(a[i]+a[j]>a[k]) ans++;
			}
		}
	}
	printf("%d\n",ans);

	return 0;
}
