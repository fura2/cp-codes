#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

template<class R>
class matrix{
	vector<vector<R>> a;
public:
	matrix(int n):a(n,vector<R>(n)){}
	matrix(int m,int n):a(m,vector<R>(n)){}

	matrix& operator+=(const matrix& A){
		assert(h()==A.h() && w()==A.w());
		int m=h(),n=w();
		rep(i,m) rep(j,n) (*this)[i][j]+=A[i][j];
		return *this;
	}
	matrix& operator-=(const matrix& A){
		assert(h()==A.h() && w()==A.w());
		int m=h(),n=w();
		rep(i,m) rep(j,n) (*this)[i][j]-=A[i][j];
		return *this;
	}
	matrix& operator*=(const matrix& A){
		assert(w()==A.h());
		int m=h(),n=w(),l=A.w();
		matrix B(m,l);
		rep(i,m) rep(j,l) rep(k,n) B[i][j]+=(*this)[i][k]*A[k][j];
		swap(*this,B);
		return *this;
	}
	matrix operator+(const matrix& A)const{ return matrix(*this)+=A; }
	matrix operator-(const matrix& A)const{ return matrix(*this)-=A; }
	matrix operator*(const matrix& A)const{ return matrix(*this)*=A; }
	const vector<R>& operator[](int i)const{ return a[i]; }
	vector<R>& operator[](int i){ return a[i]; }

	vector<R> operator*(const vector<R>& v)const{
		assert(w()==v.size());
		int m=h(),n=w();
		vector<R> res(m);
		rep(i,m) rep(j,n) res[i]+=(*this)[i][j]*v[j];
		return res;
	}

	int h()const{ return a.size(); }
	int w()const{ return a.empty()?0:a[0].size(); }

	static matrix identity(int n){
		matrix I(n);
		rep(i,n) I[i][i]=R{1};
		return I;
	}
};

int main(){
	int n; scanf("%d",&n);
	vector<int> x(n),y(n);
	rep(i,n) scanf("%d%d",&x[i],&y[i]);

	int m; scanf("%d",&m);
	vector<matrix<lint>> cum(m+1,3);
	cum[0]=matrix<lint>::identity(3);
	rep(i,m){
		int t; scanf("%d",&t);
		matrix<lint> A(3);
		if(t==1){
			A[0][1]=1;
			A[1][0]=-1;
			A[2][2]=1;
		}
		else if(t==2){
			A[0][1]=-1;
			A[1][0]=1;
			A[2][2]=1;
		}
		else if(t==3){
			int p; scanf("%d",&p);
			A[0][0]=-1;
			A[0][2]=2*p;
			A[1][1]=1;
			A[2][2]=1;
		}
		else{
			int p; scanf("%d",&p);
			A[0][0]=1;
			A[1][1]=-1;
			A[1][2]=2*p;
			A[2][2]=1;
		}
		cum[i+1]=A*cum[i];
	}

	int q; scanf("%d",&q);
	rep(_,q){
		int i,j; scanf("%d%d",&i,&j); j--;
		vector<lint> v={x[j],y[j],1};
		v=cum[i]*v;
		printf("%lld %lld\n",v[0],v[1]);
	}

	return 0;
}
