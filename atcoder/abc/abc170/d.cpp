#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	vector<int> f(1000001);
	rep(i,n) f[a[i]]++;
	for(int x=1;x<=1000000;x++) if(f[x]>0) {
		for(int y=2*x;y<=1000000;y+=x) f[y]=0;
	}
	printf("%ld\n",count(f.begin(),f.end(),1));

	return 0;
}
