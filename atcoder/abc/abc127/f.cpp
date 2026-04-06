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
	int q; cin>>q;
	vector<int> id(q),a(q),b(q);
	rep(i,q){
		cin>>id[i];
		if(id[i]==1) cin>>a[i]>>b[i];
	}

	vector<int> X;
	rep(i,q) if(id[i]==1) X.emplace_back(a[i]);
	sort(X.begin(),X.end());
	X.erase(unique(X.begin(),X.end()),X.end());
	int n=X.size();
	rep(i,q) if(id[i]==1) a[i]=lower_bound(X.begin(),X.end(),a[i])-X.begin();

	Fenwick_tree<int> F;
	Fenwick_tree<long long> L,R;
	F.build(n);
	L.build(n);
	R.build(n);

	int m=0;
	long long bsum=0;
	rep(i,q){
		if(id[i]==1){
			m++;
			F.add(a[i],1);
			L.add(a[i],X[ n-1]-X[a[i]]);
			R.add(a[i],X[a[i]]-X[  0 ]);
			bsum+=b[i];
		}
		else{
			int lo=0,hi=n;
			while(lo<hi){
				int mi=(lo+hi)/2;
				if(F.sum(0,mi)<(m+1)/2) lo=mi+1;
				else                    hi=mi;
			}

			long long ans=bsum,lnum=F.sum(0,lo-1),rnum=F.sum(lo+1,n-1);
			ans+=L.sum(  0 ,lo-1)-lnum*(X[n-1]-X[lo]);
			ans+=R.sum(lo+1, n-1)-rnum*(X[ lo]-X[ 0]);
			printf("%d %lld\n",X[lo],ans);
		}
	}

	return 0;
}
