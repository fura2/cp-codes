#include <cstdio>
#include <vector>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	vector<long long> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	vector<int> par(60); // parity
	rep(t,60) rep(i,n) if(a[i]&(1LL<<t)) par[t]^=1;

	vector<vector<int>> A; // augmented matrix
	vector<int> piv,res(60);
	for(int t=59;t>=0;t--) if(!par[t]) {
		A.emplace_back(vector<int>(n+1));
		int m=A.size();
		rep(i,n) if(a[i]&(1LL<<t)) A[m-1][i]=1; // lhs
		A[m-1][n]=1; // rhs

		// Gauss-Jordan on F_2
		rep(i,m-1) if(~piv[i] && A[m-1][piv[i]]) {
			rep(j,n+1) A[m-1][j]^=A[i][j];
		}
		int p=-1; // pivot of m-th row (-1: don't exist)
		rep(j,n) if(A[m-1][j]) { p=j; break; }
		if(p==-1 && A[m-1][n]){ // NG
			res[t]=0;
			A[m-1][n]=0;
		}
		else{ // OK
			res[t]=1;
		}
		piv.emplace_back(p);
	}

	long long ans=0;
	bool carry=false;
	rep(t,60){
		if(!par[t]){
			if(res[t]){ // 1 + 1 + carry
				if(carry) ans+=1LL<<t;
				carry=true;
			}
			else{ // 0 + 0 + carry
				if(carry) ans+=1LL<<t;
				carry=false;
			}
		}
		else{ // 0 + 1 + carry
			if(!carry){
				ans+=1LL<<t;
			}
		}
	}
	if(carry) ans+=1LL<<60;

	printf("%lld\n",ans);

	return 0;
}
