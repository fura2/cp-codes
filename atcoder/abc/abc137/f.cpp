#include <cstdio>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int p,a[3000];
	scanf("%d",&p);

	static int nCr[3000][3000];
	rep(n,3000) nCr[n][0]=1;
	rep(n,2999) rep(r,n+1) nCr[n+1][r+1]=(nCr[n][r+1]+nCr[n][r])%p;

	static int pw[3000][3000]; // pw[i][j] := i^j mod p
	rep(i,3000){
		pw[i][0]=1;
		rep(j,2999) pw[i][j+1]=pw[i][j]*i%p;
	}

	int ans[3000]={};
	rep(i,p){
		int a; scanf("%d",&a);
		if(a==0) continue;

		ans[0]++;
		rep(j,p){
			int tmp=nCr[p-1][j]*pw[(p-i)%p][p-j-1]%p;
			ans[j]=(ans[j]-tmp+p)%p;
		}
	}

	rep(i,p) printf("%d ",ans[i]);

	return 0;
}
