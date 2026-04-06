#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

random_device seed_gen;
mt19937 rng(seed_gen());

int main(){
	while(1){
		int a=rng()%10000000;
		int b=rng()%10000000;
		int c=rng()%10000000;

		vector<pair<int,int>> P;
		rep(i,10) rep(j,10) rep(k,10) {
			int x=i*a+j*0+k*c;
			int y=i*0+j*b+k*c;
			P.emplace_back(x,y);
		}

		map<int,int> f;
		for(auto [x,y]:P) ++f[x+y];
		if(f.size()==1000){
			printf("%ld\n",P.size());
			for(auto [x,y]:P) printf("%d %d\n",x,y);
			break;
		}
	}

	return 0;
}
