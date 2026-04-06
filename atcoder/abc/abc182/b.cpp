#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int ans=0,c_ans=-1;
	for(int x=2;x<=1000;x++){
		int cnt=0;
		rep(i,n) if(a[i]%x==0) cnt++;
		if(c_ans<cnt) c_ans=cnt, ans=x;
	}
	printf("%d\n",ans);

	return 0;
}
