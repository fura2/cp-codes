#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	int ans[6]={};
	rep(i,n){
		double a,b; scanf("%lf%lf",&a,&b);
		if     (a>=35) ans[0]++;
		else if(a>=30) ans[1]++;
		else if(a>=25) ans[2]++;
		if(b>=25) ans[3]++;
		if(b<0 && a>=0) ans[4]++;
		if(a<0) ans[5]++;
	}
	rep(i,6) printf("%d%c",ans[i],i<5?' ':'\n');
	return 0;
}
