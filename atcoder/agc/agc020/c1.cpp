#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using ulint=unsigned long long;

int main(){
	int n; scanf("%d",&n);

	int m=(2000*n+1+63)/64;
	vector<ulint> b(m);
	b[0]=1;
	rep(_,n){
		int a; scanf("%d",&a);
		int w=a/64,d=a%64;
		for(int i=m-1-w;i>=0;i--){
			if(i+w+1<m && d>0){
				b[i+w+1]|=b[i]>>(64-d);
			}
			b[i+w]|=b[i]<<d;
		}
	}

	vector<int> p;
	rep(i,m) rep(d,64) if(b[i]>>d&1) p.emplace_back(i*64+d);
	printf("%d\n",p[p.size()/2]);

	return 0;
}
