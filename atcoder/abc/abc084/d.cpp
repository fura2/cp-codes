#include <cstdio>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int P_MAX=100000;
bool er[P_MAX+1];
void sieve(){
	rep(i,P_MAX+1) er[i]=(i>=2);
	for(int i=2;i*i<=P_MAX;i++) if(er[i]) for(int j=i*i;j<=P_MAX;j+=i) er[j]=false;
}

int main(){
	sieve();

	int ans[100001]={};
	for(int i=1;i<=100000;i++){
		ans[i]=ans[i-1];
		if(i%2==1 && er[i] && er[(i+1)/2]) ans[i]++;
	}

	int q; scanf("%d",&q);
	rep(i,q){
		int l,r; scanf("%d%d",&l,&r);
		printf("%d\n",ans[r]-ans[l-1]);
	}

	return 0;
}
