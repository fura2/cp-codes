#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

class bint{
	static const int BASE=1000000000;
	int sign;
	vector<int> a;

	bint& normalize(){
		while(!a.empty() && a.back()==0) a.pop_back();
		if(a.empty()) sign=1;
		return *this;
	}
public:
	bint(long long v=0){ *this=v; }
	bint(const string& s){ *this=s; }
	bint& operator=(long long v){
		if(v>=0) sign=1;
		else sign=-1, v*=-1;
		a.clear();
		for(;v>0;v/=BASE) a.emplace_back(v%BASE);
		return *this;
	}
	bint& operator=(const string& s){
		int n=s.length(),t=0;
		sign=1;
		if     (s[0]=='+') t++;
		else if(s[0]=='-') t++, sign=-1;
		a.clear();
		for(int i=n;i>t;i-=9) a.emplace_back(stoi(s.substr(max(i-9,t),i-max(i-9,t))));
		return normalize();
	}
	bint& operator+=(const bint& b){
		int m=a.size(),n=b.a.size(),carry=0;
		if(sign==b.sign){
			if(m<n) a.resize(n), m=n;
			rep(i,n){
				a[i]+=b.a[i]+carry;
				if(a[i]>=BASE) a[i]-=BASE, carry=1;
				else carry=0;
			}
			if(carry>0){
				if(a.size()==n) a.resize(n+1);
				a[n]+=carry;
			}
		}
		else if(abs(*this)>=abs(b)){
			rep(i,n){
				a[i]-=b.a[i]+carry;
				if(a[i]<0) a[i]+=BASE, carry=1;
				else carry=0;
			}
			if(carry>0) a[n]-=carry;
		}
		else{
			a.resize(n);
			rep(i,n){
				a[i]=b.a[i]-(a[i]+carry);
				if(a[i]<0) a[i]+=BASE, carry=1;
				else carry=0;
			}
			sign*=-1;
		}
		return normalize();
	}
	bint& operator-=(const bint& b){
		sign*=-1;
		*this+=b;
		sign*=-1;
		return normalize();
	}
	bint& operator*=(int v){
		if(v<0) sign*=-1, v=-v;
		int n=a.size(),carry=0;
		rep(i,n){
			auto tmp=(long long)a[i]*v+carry;
			a[i]=tmp%BASE;
			carry=tmp/BASE;
		}
		if(carry>0) a.emplace_back(carry);
		return normalize();
	}
	bint& operator/=(int v){
		if(v<0) sign*=-1, v*=-1;
		for(int i=a.size()-1,rem=0;i>=0;i--){
			auto tmp=a[i]+(long long)rem*BASE;
			a[i]=tmp/v;
			rem=tmp%v;
		}
		return normalize();
	}
	bint& operator*=(const bint& b){ return *this=(*this)*b; }
	bint& operator/=(const bint& b){ return *this=(*this)/b; }
	bint operator+(const bint& b)const{ return bint(*this)+=b; }
	bint operator-(const bint& b)const{ return bint(*this)-=b; }
	bint operator*(int v)const{ return bint(*this)*=v; }
	bint operator/(int v)const{ return bint(*this)/=v; }
	bint operator*(const bint& b)const{
		int m=a.size(),n=b.a.size();
		if(m==0 || n==0) return 0;
		bint res;
		res.a.resize(m+n);
		rep(i,m) rep(j,n) {
			auto tmp=(long long)a[i]*b.a[j];
			res.a[i+j]+=tmp%BASE;
			if(tmp>=BASE) res.a[i+j+1]+=tmp/BASE;
			for(int k=0;;k++){
				if(k>0 && res.a[i+j+k]<BASE) break;
				if(res.a[i+j+k]>=BASE){
					res.a[i+j+k]-=BASE;
					res.a[i+j+k+1]++;
				}
			}
		}
		res.sign=sign*b.sign;
		return res.normalize();
	}
	bint operator/(const bint& b)const{ return divmod(*this,b).first; }
	bint operator%(const bint& b)const{ return divmod(*this,b).second; }
	bint operator-()const{ bint res=*this; if(res!=0) res.sign*=-1; return res; }
	bool operator< (const bint& b)const{
		if(sign!=b.sign) return sign<b.sign;
		int m=a.size(),n=b.a.size();
		if(m!=n) return sign==1?m<n:m>n;
		for(int i=m-1;i>=0;i--) if(a[i]!=b.a[i]) return sign==1?a[i]<b.a[i]:a[i]>b.a[i];
		return false;
	}
	bool operator> (const bint& b)const{ return b<(*this); }
	bool operator<=(const bint& b)const{ return !(b<(*this)); }
	bool operator>=(const bint& b)const{ return !((*this)<b); }
	bool operator==(const bint& b)const{ return !((*this)<b) && !(b<(*this)); }
	bool operator!=(const bint& b)const{ return (*this)<b || b<(*this); }
	friend ostream& operator<<(ostream& os,const bint& b){
		if(b.sign==-1) os<<'-';
		os<<(b.a.empty()?0:b.a.back());
		for(int i=b.a.size()-2;i>=0;i--) os<<setw(9)<<setfill('0')<<b.a[i];
		return os;
	}

	friend bint abs(const bint& b){ return b.sign==1?b:-b; }

	friend pair<bint,bint> divmod(const bint& a1,const bint& b1){
		int norm=BASE/(b1.a.back()+1);
		bint a=abs(a1)*norm,b=abs(b1)*norm,q,r;
		q.a.resize(a.a.size());
		for(int i=a.a.size()-1;i>=0;i--){
			r*=BASE;
			r+=a.a[i];
			int s1=(r.a.size()<=b.a.size()?0:r.a[b.a.size()]);
			int s2=(r.a.size()<=b.a.size()-1?0:r.a[b.a.size()-1]);
			int d=((long long)BASE*s1+s2)/b.a.back();
			r-=b*d;
			while(r<0) r+=b, d--;
			q.a[i]=d;
		}
		q.sign=a1.sign*b1.sign;
		r.sign=a1.sign;
		return make_pair(q.normalize(),r.normalize()/norm);
	}
};

int main(){
	int n,a;
	string s; cin>>n>>a>>s; a--;
	vector<int> p(n);
	rep(i,n) cin>>p[i], p[i]--;

	vector<int> t(n,-1);
	t[a]=0;
	while(t[p[a]]==-1) t[p[a]]=t[a]+1, a=p[a];

	bint x=s;
	if(x<=t[p[a]]){
		while(x>0) a=p[a], x-=1;
		cout<<a<<'\n';
		return 0;
	}

	x=(x-t[p[a]])%(t[a]-t[p[a]]+1);

	a=p[a];
	while(x>0) a=p[a], x-=1;
	cout<<a+1<<'\n';

	return 0;
}
