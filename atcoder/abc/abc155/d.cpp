#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	int n;
	lint k; scanf("%d%lld",&n,&k);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	auto b=a;
	rep(i,n) b[i]*=-1;

	sort(a.begin(),a.end());
	sort(b.begin(),b.end());

	lint lo=-INF,hi=INF;
	while(hi-lo>1){
		lint mi=(lo+hi)/2;

		lint cnt=0;
		rep(i,n){
			if(a[i]==0){
				if(mi>=0) cnt+=n;
			}
			else if(a[i]>0){
				lint num;
				if(mi>=0) num=mi/a[i];
				else      num=-((-mi+a[i]-1)/a[i]);
				cnt+=upper_bound(a.begin(),a.end(),num)-a.begin();
			}
			else{
				lint num;
				if(mi>=0) num=mi/-a[i];
				else      num=-((-mi-a[i]-1)/-a[i]);
				cnt+=upper_bound(b.begin(),b.end(),num)-b.begin();
			}
			if(a[i]*a[i]<=mi) cnt--;
		}
		cnt/=2;

		if(cnt<k) lo=mi;
		else      hi=mi;
	}
	printf("%lld\n",lo+1);

	return 0;
}
