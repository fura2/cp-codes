#include <algorithm>
#include <cstdio>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,c[499],s[499],f[499];
	scanf("%d",&n);
	rep(i,n-1) scanf("%d%d%d",c+i,s+i,f+i);

	rep(i,n){
		int t=0;
		for(int j=i;j<n-1;j++){
			t=max(t,s[j]);
			t=(t+f[j]-1)/f[j]*f[j];
			t+=c[j];
		}
		printf("%d\n",t);
	}

	return 0;
}
