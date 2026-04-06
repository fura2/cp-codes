#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> x(n),y(n);
	rep(i,n) scanf("%d%d",&x[i],&y[i]);

	rep(i,n) for(int j=i+1;j<n;j++) for(int k=j+1;k<n;k++) {
		int dx1=x[j]-x[i];
		int dy1=y[j]-y[i];
		int dx2=x[k]-x[i];
		int dy2=y[k]-y[i];
		if(dx1*dy2-dx2*dy1==0){
			puts("Yes");
			return 0;
		}
	}
	puts("No");

	return 0;
}
