#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int MOD=1000000007;

int main(){
	int n;
	scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	vector<int> b(n);
	rep(i,n) b[i]=abs(i-(n-i-1));

	sort(a.begin(),a.end());
	sort(b.begin(),b.end());

	if(a==b){
		int ans=1;
		rep(i,n/2) ans=ans*2%MOD;
		printf("%d\n",ans);
	}
	else{
		puts("0");
	}

	return 0;
}
