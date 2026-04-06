// 初めて解いたときのコード

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

template<class T> T gcd(const T& a,const T& b){ return b==0?a:gcd(b,a%b); }

template<class T>
T xgcd(T a,T b,T& x,T& y){
	if(b==0){ x=1; y=0; return a; }
	T g=xgcd(b,a%b,y,x);
	y-=a/b*x;
	return g;
}

int main(){
	int q; scanf("%d",&q);

	int ans=0;
	rep(_,q){
		lint a,k; scanf("%lld%lld",&a,&k);

		while(a%k!=0){
			lint x=a/k+1,y=k,z=a%k;
			lint g=gcd(x,y);

			if(z%g==0){
				// find (m, n) s.t. m*x + n*y = z
				lint m,n;
				xgcd(x,y,m,n);
				m*=z/g;
				n*=z/g;
				assert(m*x+n*y==z);

				// compute the smallest positive m
				if(m>0){
					lint l=m/(y/g);
					m-=l*(y/g);
					n+=l*(x/g);
				}
				else{ // m<0
					lint l=(-m)/(y/g)+1;
					m+=l*(y/g);
					n-=l*(x/g);
				}
				assert(m>0);

				lint a2=a-m*x;
				if(a2>=0 && a2/k+1==x){
					a=a2;
					assert(a%k==0);
					break;
				}
			}

			lint lo=0,hi=2*k;
			while(hi-lo>1){
				lint mi=(lo+hi)/2;
				lint a2=a-mi*x;
				if(a2>=0 && a2/k+1==x) lo=mi;
				else                   hi=mi;
			}
			a-=hi*x;
		}

		ans^=a/k;
	}
	puts(ans>0?"Takahashi":"Aoki");

	return 0;
}
