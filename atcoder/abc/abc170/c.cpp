#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int x,n; scanf("%d%d",&x,&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	for(int d=0;;d++){
		if(count(a.begin(),a.end(),x-d)==0) return printf("%d\n",x-d),0;
		if(count(a.begin(),a.end(),x+d)==0) return printf("%d\n",x+d),0;
	}

	return 0;
}
