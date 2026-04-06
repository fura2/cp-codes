#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

class bit_set{
	int n,m;
	vector<unsigned long long> a;
public:
	bit_set(int n):n(n){
		m=n/64+1;
		a.assign(m,0);
	}
	int size()const{ return n; }
	void set(int i,int val){
		assert(0<=i && i<n && (val==0 || val==1));
		if(val==0) a[i/64]&=~(1ULL<<i%64);
		else       a[i/64]|=1ULL<<i%64;
	}
	int operator[](int i)const{
		assert(0<=i && i<n);
		return a[i/64]>>i%64&1;
	}
	bit_set& operator&=(const bit_set& B){
		assert(n==B.size());
		rep(i,m) a[i]&=B.a[i];
		return *this;
	}
	bit_set& operator|=(const bit_set& B){
		assert(n==B.size());
		rep(i,m) a[i]|=B.a[i];
		return *this;
	}
	bit_set& operator^=(const bit_set& B){
		assert(n==B.size());
		rep(i,m) a[i]^=B.a[i];
		return *this;
	}
	bit_set& operator<<=(int x){
		x=min(x,n);
		int w=x/64,d=x%64;
		for(int i=m-1;i>=w;i--){
			a[i]=a[i-w]<<d;
			if(i-w-1>=0 && d>0) a[i]|=a[i-w-1]>>(64-d);
		}
		for(int i=w-1;i>=0;i--) a[i]=0;
		return *this;
	}
	bit_set& operator>>=(int x){
		x=min(x,n);
		int w=x/64,d=x%64;
		rep(i,m-w){
			a[i]=a[i+w]>>d;
			if(i+w+1<m && d>0) a[i]|=a[i+w+1]<<(64-d);
		}
		for(int i=m-w;i<m;i++) a[i]=0;
		return *this;
	}
	bit_set operator&(const bit_set& B)const{ return bit_set(*this)&=B; }
	bit_set operator|(const bit_set& B)const{ return bit_set(*this)|=B; }
	bit_set operator^(const bit_set& B)const{ return bit_set(*this)^=B; }
	bit_set operator<<(int x)const{ return bit_set(*this)<<=x; }
	bit_set operator>>(int x)const{ return bit_set(*this)>>=x; }
	void update_or_shift(int x){
		if(x>0){
			x=min(x,n);
			int w=x/64,d=x%64;
			for(int i=m-1;i>=w;i--){
				unsigned long long mask=a[i-w]<<d;
				if(i-w-1>=0 && d>0) mask|=a[i-w-1]>>(64-d);
				a[i]|=mask;
			}
		}
		else if(x<0){
			x=min(-x,n);
			int w=x/64,d=x%64;
			rep(i,m-w){
				unsigned long long mask=a[i+w]>>d;
				if(i+w+1<m && d>0) mask|=a[i+w+1]<<(64-d);
				a[i]|=mask;
			}
		}
	}
	void update_and_shift(int x){
		if(x>0){
			x=min(x,n);
			int w=x/64,d=x%64;
			for(int i=m-1;i>=w;i--){
				unsigned long long mask=a[i-w]<<d;
				if(i-w-1>=0 && d>0) mask|=a[i-w-1]>>(64-d);
				a[i]&=mask;
			}
			for(int i=w-1;i>=0;i--) a[i]=0;
		}
		else if(x<0){
			x=min(-x,n);
			int w=x/64,d=x%64;
			rep(i,m-w){
				unsigned long long mask=a[i+w]>>d;
				if(i+w+1<m && d>0) mask|=a[i+w+1]<<(64-d);
				a[i]&=mask;
			}
			for(int i=m-w;i<m;i++) a[i]=0;
		}
	}
	void update_xor_shift(int x){
		if(x>0){
			x=min(x,n);
			int w=x/64,d=x%64;
			for(int i=m-1;i>=w;i--){
				unsigned long long mask=a[i-w]<<d;
				if(i-w-1>=0 && d>0) mask|=a[i-w-1]>>(64-d);
				a[i]^=mask;
			}
		}
		else if(x<0){
			x=min(-x,n);
			int w=x/64,d=x%64;
			rep(i,m-w){
				unsigned long long mask=a[i+w]>>d;
				if(i+w+1<m && d>0) mask|=a[i+w+1]<<(64-d);
				a[i]^=mask;
			}
		}
	}
};

string to_string(const bit_set& B){
	string s(B.size(),'?');
	rep(i,B.size()) s[i]='0'+B[i];
	return s;
}

int main(){
	int n; scanf("%d",&n);

	int sum=0;
	bit_set B(2000*n+1);
	B.set(0,1);
	rep(_,n){
		int a; scanf("%d",&a);
		sum+=a;
		B.update_or_shift(a);
	}

	rep(i,B.size()) if(B[i]==1 && 2*i>=sum) {
		printf("%d\n",i);
		break;
	}

	return 0;
}
