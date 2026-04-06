#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);

	int ans=0;
	vector<bool> b(100001);
	rep(i,n){
		int a; scanf("%d",&a);
		if(b[a]) ans++;
		b[a]=true;
	}
	printf("%d\n",ans);

	return 0;
}
