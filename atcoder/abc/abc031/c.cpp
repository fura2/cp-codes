#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int ans=-INF;
	rep(i,n){
		int score1,score2=-INF;
		rep(j,n) if(i!=j) {
			int mn=min(i,j),mx=max(i,j),tmp1=0,tmp2=0;
			rep(k,mx-mn+1){
				if(k%2==0) tmp1+=a[mn+k];
				else       tmp2+=a[mn+k];
			}
			if(score2<tmp2){
				score1=tmp1;
				score2=tmp2;
			}
		}
		ans=max(ans,score1);
	}
	printf("%d\n",ans);

	return 0;
}
