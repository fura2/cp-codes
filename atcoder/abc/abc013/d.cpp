#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

class permutation{
	vector<int> f;
public:
	permutation(int n){
		f.resize(n);
		rep(i,n) f[i]=i;
	}

	permutation operator*(const permutation& p)const{
		int n=f.size();
		permutation res(n);
		rep(i,n) res[i]=f[p[i]];
		return res;
	}
	int operator[](int i)const{ return f[i]; }
	int& operator[](int i){ return f[i]; }

	int size()const{ return f.size(); }

	permutation inverse()const{
		int n=f.size();
		permutation res(n);
		rep(i,n) res[f[i]]=i;
		return res;
	}
};

permutation pow(permutation p,long long k){
	permutation res(p.size());
	for(;k>0;k>>=1,p=p*p) if(k&1) res=res*p;
	return res;
}

int main(){
	int n,m,d; scanf("%d%d%d",&n,&m,&d);
	permutation p(n);
	rep(i,m){
		int a; scanf("%d",&a); a--;
		swap(p[a],p[a+1]);
	}

	auto q=pow(p.inverse(),d);
	rep(i,n) printf("%d\n",q[i]+1);

	return 0;
}
