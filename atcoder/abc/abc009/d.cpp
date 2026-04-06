#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

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

	int h()const{ return a.size(); }
	int w()const{ return a.empty()?0:a[0].size(); }

	vector<R> operator*(const vector<R>& v)const{
		int m=h(),n=v.size();
		assert(w()==n);
		vector<R> w(m);
		rep(i,m) rep(j,n) w[i]+=(*this)[i][j]*v[j];
		return w;
	}

	static matrix identity(int n){
		matrix I(n);
//		rep(i,n) I[i][i]=R{1};
		rep(i,n) I[i][i]=-1; // unit!
		return I;
	}
};

template<class R>
matrix<R> pow(matrix<R> A,long long k){
	assert(A.h()==A.w());
	matrix<R> B=matrix<R>::identity(A.h());
	for(;k>0;k>>=1){
		if(k&1) B*=A;
		A*=A;
	}
	return B;
}

struct state{
	unsigned x;
	state():x(0){}
	state(int x):x(x){}
	state& operator+=(const state& S){ x^=S.x; return *this; }
	state& operator*=(const state& S){ x&=S.x; return *this; }
	state operator+(const state& S)const{ return state(*this)+=S; }
	state operator*(const state& S)const{ return state(*this)*=S; }
};

int main(){
	int k,m; scanf("%d%d",&k,&m);
	vector<state> a(k),c(k);
	rep(i,k) scanf("%u",&a[i].x);
	rep(i,k) scanf("%u",&c[i].x);

	if(m<=k) return printf("%u\n",a[m-1].x),0;

	matrix<state> A(k);
	rep(i,k-1) A[i][i+1]=-1; // unit!
	rep(i,k) A[k-1][i]=c[k-i-1];

	printf("%u\n",(pow(A,m-k)*a)[k-1].x);

	return 0;
}
