#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

struct interval{ int a,b; };

bool cmp_l(const interval &I,const interval &J){ return tie(I.a,I.b)<tie(J.a,J.b); }
bool cmp_r(const interval &I,const interval &J){ return tie(I.b,I.a)<tie(J.b,J.a); }

int main(){
	int n; scanf("%d",&n);
	vector<interval> I(n);
	rep(i,n) scanf("%d%d",&I[i].a,&I[i].b);

	lint ans=0;
	rep(_,2){
		multiset<interval,decltype(&cmp_l)> L(&cmp_l);
		multiset<interval,decltype(&cmp_r)> R(&cmp_r);
		for(auto J:I){
			L.emplace(J);
			R.emplace(J);
		}

		lint res=0;
		int x=0;
		while(1){
			bool ok=false;
			if(!L.empty()){
				auto J=*L.rbegin();
				if(x<J.a){
					res+=J.a-x;
					x=J.a;
					L.erase(L.find(J));
					R.erase(R.find(J));
					ok=true;
				}
			}
			if(!R.empty()){
				auto J=*R.begin();
				if(J.b<x){
					res+=x-J.b;
					x=J.b;
					L.erase(L.find(J));
					R.erase(R.find(J));
					ok=true;
				}
			}
			if(!ok) break;
		}
		res+=abs(x);

		ans=max(ans,res);
		rep(i,n){
			I[i].a*=-1;
			I[i].b*=-1;
			swap(I[i].a,I[i].b);
		}
	}
	printf("%lld\n",ans);

	return 0;
}
