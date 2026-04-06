#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n); rep(i,n) scanf("%d",&a[i]);

	sort(a.begin(),a.end());

	int cnt=0;
	rep(i,n) if(i>0 && a[i-1]==a[i]) cnt++;
	printf("%d\n",n-(cnt+1)/2*2);

	return 0;
}
