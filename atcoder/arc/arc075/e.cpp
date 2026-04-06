#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int N_MAX=200000;

template<class T>
class Fenwick_tree{
	int n;
	T a[N_MAX];

public:
	void build(int n){
		this->n=n;
		rep(i,n) a[i]=0;
	}

	void add(int i,T v){
		for(;i<n;i|=i+1) a[i]+=v;
	}

	T sum(int i,int j){
		if(i==0){
			T s=0;
			for(;j>=0;j=(j&(j+1))-1) s+=a[j];
			return s;
		}
		return sum(0,j)-sum(0,i-1);
	}
};

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]), a[i]-=k;

	vector<long long> sum(n);
	sum[0]=a[0];
	rep(i,n-1) sum[i+1]=sum[i]+a[i+1];

	vector<long long> X=sum;
	sort(X.begin(),X.end());
	X.erase(unique(X.begin(),X.end()),X.end());
	int m=X.size();

	vector<int> pos(n);
	rep(i,n) pos[i]=lower_bound(X.begin(),X.end(),sum[i])-X.begin();

	Fenwick_tree<int> F;
	F.build(m);
	rep(i,n) F.add(pos[i],1);

	long long ans=0,thre=0;
	rep(i,n){
		int idx=lower_bound(X.begin(),X.end(),thre)-X.begin();
		ans+=F.sum(idx,m-1);

		F.add(pos[i],-1);
		thre+=a[i];
	}
	printf("%lld\n",ans);

	return 0;
}
