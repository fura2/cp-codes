#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

template<int N,int OFFSET>
class trie{
	struct node{
		vector<int> accept;
		int nxt[N];
		node():accept(){
			fill(nxt,nxt+N,-1);
		}
	};
	vector<node> V;
public:
	trie():V(1){}
	void add(const string& s,int id){
		int len=s.length(),pos=0;
		rep(i,len){
			if(V[pos].nxt[s[i]-OFFSET]==-1){
				V[pos].nxt[s[i]-OFFSET]=V.size();
				V.emplace_back();
			}
			pos=V[pos].nxt[s[i]-OFFSET];
		}
		V[pos].accept.emplace_back(id);
	}

	lint solve(const string& s){
		int len=s.length();
		int freq[N]={};
		rep(i,len) freq[s[i]-OFFSET]++;

		lint res=0;
		int pos=0;
		rep(i,len){
			rep(c,N) if(freq[c]>0) {
				int pos2=V[pos].nxt[c];
				if(pos2!=-1){
					res+=V[pos2].accept.size();
				}
			}

			pos=V[pos].nxt[s[i]-OFFSET];
			if(pos==0) break;
			freq[s[i]-OFFSET]--;
		}
		res--;
		return res;
	}
};

int main(){
	int n; cin>>n;
	vector<string> s(n);
	rep(i,n){
		cin>>s[i];
		reverse(s[i].begin(),s[i].end());
	}

	trie<26,'a'> T;
	rep(i,n) T.add(s[i],i);

	lint ans=0;
	rep(i,n){
		ans+=T.solve(s[i]);
	}
	printf("%lld\n",ans);

	return 0;
}
