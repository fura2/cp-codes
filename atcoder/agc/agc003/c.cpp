#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	auto b=a;
	sort(b.begin(),b.end());

	int bad=0;
	rep(i,n){
		int idx=lower_bound(b.begin(),b.end(),a[i])-b.begin();
		if(i%2==0 && idx%2==1) bad++;
	}
	printf("%d\n",bad);

	return 0;
}
