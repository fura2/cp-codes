#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

template<class G>
class Fenwick_tree{
	vector<G> a;
public:
	Fenwick_tree(int n):a(n){}
	void add(int i,G val){
		for(i++;i<=a.size();i+=i&-i) a[i-1]+=val;
	}
	G sum(int l,int r)const{
		if(l==0){
			G res{};
			for(;r>0;r-=r&-r) res+=a[r-1];
			return res;
		}
		return sum(0,r)-sum(0,l);
	}
	int lower_bound(G val)const{
		if(val<=G{}) return 0;
		int x=0,k;
		for(k=1;k<=a.size();k<<=1);
		for(k>>=1;k>0;k>>=1) if(x+k<=a.size() && a[x+k-1]<val) val-=a[x+k-1], x+=k;
		return x;
	}
	int upper_bound(G val)const{
		if(val<G{}) return 0;
		int x=0,k;
		for(k=1;k<=a.size();k<<=1);
		for(k>>=1;k>0;k>>=1) if(x+k<=a.size() && a[x+k-1]<=val) val-=a[x+k-1], x+=k;
		return x;
	}
};

lint calc(const string& s,const string& t){
	int n=s.length();

	deque<int> D[26];
	rep(i,n) D[s[i]-'a'].emplace_back(i);

	Fenwick_tree<int> F(n);
	rep(i,n) F.add(i,1);

	lint res=0;
	rep(i,n){
		int p=D[t[i]-'a'][0]; // move s[p] -> t[i]
		D[t[i]-'a'].pop_front();
		res+=F.sum(0,p);
		F.add(p,-1);
	}
	return res;
}

int main(){
	string s; cin>>s;
	int n=s.length();

	vector<vector<int>> cnt(26,vector<int>(n+1));
	rep(c,26) rep(i,n) cnt[c][i+1]+=cnt[c][i]+(s[i]==c+'a'?1:0);

	int odd=-1;
	rep(c,26) if(cnt[c][n]%2==1) {
		if(odd==-1) odd=c;
		else return puts("-1"),0;
	}
	if(n%2==0 && odd!=-1) return puts("-1"),0;

	vector<int> L,M,R;
	rep(i,n){
		int c=s[i]-'a';
		int k=cnt[c][i+1];
		if(cnt[c][n]%2==1 && k==(cnt[c][n]+1)/2){
			M.emplace_back(i);
		}
		else if(k<=cnt[c][n]/2){
			L.emplace_back(i);
		}
		else{
			R.emplace_back(i);
		}
	}

	string t;
	for(int i:L) t+=s[i];
	for(int i:M) t+=s[i];
	for(int i:R) t+=s[i];

	string r=t.substr((n+1)/2);
	reverse(r.begin(),r.end());

	cout<<calc(s,t)+calc(t.substr(0,n/2),r)<<'\n';

	return 0;
}
