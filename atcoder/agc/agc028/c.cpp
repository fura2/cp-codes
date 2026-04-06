#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n),b(n);
	rep(i,n) scanf("%d%d",&a[i],&b[i]);

	// experiment
	/*
	rep(S,1<<n){
		bool b[30][2]={};
		rep(i,n){
			if((S>>i&1)==0) b[i][0]=true;
			else            b[(i+1)%n][1]=true;
		}
		rep(i,n){
			rep(j,2) putchar(b[i][j]?'A'+j:' ');
			putchar(i<n-1?' ':'\n');
		}
	}
	*/

	vector<int> p(2*n);
	iota(p.begin(),p.end(),0);
	sort(p.begin(),p.end(),[&](int i,int j){
		return (i<n?a[i]:b[i-n])<(j<n?a[j]:b[j-n]);
	});

	vector<lint> val(2*n);
	rep(i,2*n) val[i]=(p[i]<n?a[p[i]]:b[p[i]-n]);
	lint sum=accumulate(val.begin(),val.begin()+n,0LL);

	vector<int> apos(n),bpos(n);
	rep(i,2*n){
		if(p[i]<n) apos[p[i]]=i;
		else       bpos[p[i]-n]=i;
	}
	rep(i,n) if(apos[i]<n && bpos[i]<n) return printf("%lld\n",sum),0;

	lint ans=min(accumulate(a.begin(),a.end(),0LL),
				 accumulate(b.begin(),b.end(),0LL));
	rep(i,n){
		if(apos[i]>=n && bpos[i]>=n){
			ans=min(ans,sum-val[n-2]-val[n-1]+val[apos[i]]+val[bpos[i]]);
		}
		else if(apos[i]>=n){
			ans=min(ans,sum-(bpos[i]<n-1?val[n-1]:val[n-2])+val[apos[i]]);
		}
		else{ // bpos[i]>=n
			ans=min(ans,sum-(apos[i]<n-1?val[n-1]:val[n-2])+val[bpos[i]]);
		}
	}
	printf("%lld\n",ans);

	return 0;
}
