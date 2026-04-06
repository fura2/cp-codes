#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w,n; scanf("%d%d%d",&h,&w,&n);
	vector<int> a(n),b(n);
	rep(i,n) scanf("%d%d",&a[i],&b[i]);

	auto X=a,Y=b;
	sort(X.begin(),X.end());
	X.erase(unique(X.begin(),X.end()),X.end());
	sort(Y.begin(),Y.end());
	Y.erase(unique(Y.begin(),Y.end()),Y.end());

	rep(i,n){
		a[i]=lower_bound(X.begin(),X.end(),a[i])-X.begin();
		b[i]=lower_bound(Y.begin(),Y.end(),b[i])-Y.begin();
		printf("%d %d\n",a[i]+1,b[i]+1);
	}

	return 0;
}
