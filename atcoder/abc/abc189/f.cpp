#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m,k; scanf("%d%d%d",&n,&m,&k);
	vector<bool> bad(n+1);
	rep(i,k){
		int x; scanf("%d",&x);
		bad[x]=true;
	}

	{
		vector<int> cum(n+2);
		rep(i,n+1) cum[i+1]=cum[i]+(bad[i]?1:0);
		rep(i,n-m+2) if(cum[i+m]-cum[i]==m) {
			puts("-1");
			return 0;
		}
	}

	vector<double> c1(n+m),c2(n+m); // E[i] = c1[i] + c2[i] * E[0]
	vector<double> c1_cum(n+m+1),c2_cum(n+m+1);
	for(int x=n-1;x>=0;x--){
		if(bad[x]){
			c1[x]=0;
			c2[x]=1;
		}
		else{
			c1[x]=1+(c1_cum[x+1]-c1_cum[x+m+1])/m;
			c2[x]=(c2_cum[x+1]-c2_cum[x+m+1])/m;
		}

		c1_cum[x]=c1_cum[x+1]+c1[x];
		c2_cum[x]=c2_cum[x+1]+c2[x];
	}
	printf("%.9f\n",c1[0]/(1-c2[0]));

	return 0;
}
