#include <algorithm>
#include <cstdio>
#include <vector>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int MOD=998244353;

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

struct point{
	int x,y;
	bool operator<(const point &a)const{ return x!=a.x?x<a.x:y<a.y; }
};

int main(){

	int n; scanf("%d",&n);
	vector<point> P(n);
	rep(i,n) scanf("%d%d",&P[i].x,&P[i].y);

	vector<long long> two(n);
	two[0]=1;
	rep(i,n-1) two[i+1]=two[i]*2%MOD;

	sort(P.begin(),P.end());

	// coordinate compression
	vector<int> Y;
	rep(i,n) Y.emplace_back(P[i].y);
	sort(Y.begin(),Y.end());
	Y.erase(unique(Y.begin(),Y.end()),Y.end());
	rep(i,n) P[i].y=lower_bound(Y.begin(),Y.end(),P[i].y)-Y.begin();

	Fenwick_tree<int> L,R;
	L.build(n);
	R.build(n);
	rep(i,n) R.add(P[i].y,1);

	long long ans=0;
	rep(i,n){
		L.add(P[i].y,1);

		int ld=L.sum(0,P[i].y-1);
		int lu=(i+1)-ld-1;
		int rd=R.sum(0,P[i].y-1);
		int ru=(n-i)-rd-1;
		// include P[i]
		ans+=two[n-1];
		// not include P[i]
		ans+=(two[n-1]-1)
			 -(two[i]-1)-(two[n-i-1]-1)-(two[P[i].y]-1)-(two[n-P[i].y-1]-1)
			 +(two[ld]-1)+(two[lu]-1)+(two[rd]-1)+(two[ru]-1);
		ans%=MOD; if(ans<0) ans+=MOD;

		R.add(P[i].y,-1);
	}
	printf("%lld\n",ans);

	return 0;
}
