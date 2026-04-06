#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

class suffix_array{
	vector<int> sa,lcp;

	vector<int> cnt;

	void SA_IS(vector<int>& s,int k){
		int n=s.size();

		for(int& c:s) c++;
		s.emplace_back(0);
		k++;

		vector<bool> isS(n+1);
		vector<int> LMS,bin(k+1);
		isS[n]=true;
		bin[1]=1;
		for(int i=n-1;i>=0;i--){
			isS[i]=(s[i]!=s[i+1]?s[i]<s[i+1]:isS[i+1]);
			if(!isS[i] && isS[i+1]){
				LMS.emplace_back(i+1);
			}
			bin[s[i]+1]++;
		}
		rep(i,k) bin[i+1]+=bin[i];

		auto induced_sort=[&](const vector<int>& LMS){
			sa.assign(n+1,-1);
			cnt.assign(k,0);
			for(int x:LMS){
				sa[bin[s[x]+1]-cnt[s[x]]-1]=x;
				cnt[s[x]]++;
			}

			cnt.assign(k,0);
			rep(i,n+1){
				int x=sa[i]-1;
				if(x>=0 && !isS[x]){
					sa[bin[s[x]]+cnt[s[x]]]=x;
					cnt[s[x]]++;
				}
			}

			cnt.assign(k,0);
			for(int i=n;i>=0;i--){
				int x=sa[i]-1;
				if(x>=0 && isS[x]){
					sa[bin[s[x]+1]-cnt[s[x]]-1]=x;
					cnt[s[x]]++;
				}
			}
		};

		induced_sort(LMS);

		if(LMS.size()<=1) return;

		int m=LMS.size();
		vector<int> inv(n+1,-1);
		rep(i,m) inv[LMS[i]]=i;

		int idx=0;
		vector<int> LMS2(m);
		for(int x:sa) if(inv[x]!=-1) LMS2[idx++]=x;

		int k2=1;
		vector<int> s2(m);
		s2[m-1-inv[LMS2[1]]]=1;
		for(int i=2;i<m;i++){
			int xl=LMS2[i],yl=LMS2[i-1];
			int xr=LMS[inv[xl]-1],yr=LMS[inv[yl]-1];
			if(xr-xl!=yr-yl) k2++;
			else{
				while(xl<=xr){
					if(s[xl]!=s[yl]){ k2++; break; }
					xl++; yl++;
				}
			}
			s2[m-1-inv[LMS2[i]]]=k2;
		}

		SA_IS(s2,k2+1);

		idx=m;
		for(int i=1;i<=m;i++) LMS2[--idx]=LMS[m-sa[i]-1];
		induced_sort(LMS2);
	}

	void build_lcp(const vector<int>& s){
		int n=s.size();
		lcp.resize(n);
		vector<int> f(n+1);
		rep(i,n+1) f[sa[i]]=i;
		int h=0;
		rep(i,n+1){
			if(f[i]){
				for(int j=sa[f[i]-1];i+h<n&&j+h<n;h++) if(s[i+h]!=s[j+h]) break;
				lcp[f[i]-1]=h;
			}
			if(h>0) h--;
		}
	}

public:
	suffix_array(const string& s){
		int n=s.length();
		if(n==0){ sa={0}; return; }

		auto p=minmax_element(s.begin(),s.end());
		char mn=*p.first,mx=*p.second;

		vector<int> t(n);
		rep(i,n) t[i]=s[i]-mn;

		SA_IS(t,mx-mn+1);

		t.resize(n);
		rep(i,n) t[i]=s[i]-mn;
		build_lcp(t);
	}

	int operator[](int i)const{ return sa[i]; }

	const vector<int>& longest_common_prefix()const{ return lcp; }
};

template<class T>
class sparse_table{
	vector<vector<T>> st;
	vector<int> h;
public:
	sparse_table(const vector<T>& a){
		int n=a.size();
		h.assign(n+1,0);
		for(int i=2;i<=n;i++) h[i]=h[i>>1]+1;
		st.resize(h[n]+1);
		st[0]=a;
		for(int i=1;i<h[n]+1;i++){
			st[i].resize(n-(1<<i)+1);
			rep(j,n-(1<<i)+1) st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
		}
	}
	T query(int l,int r)const{
		int i=h[r-l];
		return min(st[i][l],st[i][r-(1<<i)]);
	}
};

int main(){
	string s; cin>>s;
	int n=s.length();

	string t=s;
	reverse(t.begin(),t.end());

	suffix_array SA1(s),SA2(t);
	vector<int> f1(n+1),f2(n+1);
	rep(i,n+1){
		f1[SA1[i]]=i;
		f2[SA2[i]]=i;
	}

	sparse_table<int> ST1(SA1.longest_common_prefix());
	sparse_table<int> ST2(SA2.longest_common_prefix());

	lint ans=0;
	rep(k,n) if(k>n-k) {
		int l,r;
		tie(l,r)=minmax(f1[0],f1[k]);
		int len_A=min(ST1.query(l,r),n-k-1);
		tie(l,r)=minmax(f2[0],f2[n-k]);
		int len_C=min(ST2.query(l,r),n-k-1);
		if(len_A+len_C>=n-k){
			ans+=(len_A+len_C)-(n-k)+1;
		}
	}
	printf("%lld\n",ans);

	return 0;
}
