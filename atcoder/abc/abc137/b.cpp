#include <cstdio>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int k,x; scanf("%d%d",&k,&x);

	rep(i,2*k-1) printf("%d ",x-k+i+1);

	return 0;
}
