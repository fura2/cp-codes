#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int a1,a2,a3; cin>>a1>>a2>>a3;

	int ans=INF;
	for(int x2=-500;x2<=500;x2++){
		int cost2=0;
		rep(i,a2) cost2+=abs(x2+i);

		int cost1=INF;
		for(int x1=-1000;x1<=x2-a1;x1++){
			int tmp=0;
			rep(i,a1) tmp+=abs(x1+i+100);
			cost1=min(cost1,tmp);
		}

		int cost3=INF;
		for(int x3=x2+a2;x3<1000;x3++){
			int tmp=0;
			rep(i,a3) tmp+=abs(x3+i-100);
			cost3=min(cost3,tmp);
		}

		ans=min(ans,cost1+cost2+cost3);
	}
	printf("%d\n",ans);

	return 0;
}
