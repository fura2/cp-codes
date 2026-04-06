#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

template<class T> struct edge{
	int to;
	T wt;
	edge(int to,const T& wt):to(to),wt(wt){}
};
template<class T> using weighted_graph=vector<vector<edge<T>>>;

template<class T>
void add_directed_edge(weighted_graph<T>& G,int u,int v,const T& wt){
	G[u].emplace_back(v,wt);
}

template<class T>
vector<T> Dijkstra(const weighted_graph<T>& G,int s){
	constexpr T INF=numeric_limits<T>::max();
	int n=G.size();
	vector<T> d(n,INF); d[s]=0;
	priority_queue<pair<T,int>> Q; Q.emplace(0,s);
	while(!Q.empty()){
		T d0=-Q.top().first;
		int u=Q.top().second; Q.pop();
		if(d0>d[u]) continue;
		for(const auto& e:G[u]){
			int v=e.to;
			if(d[v]>d[u]+e.wt) d[v]=d[u]+e.wt, Q.emplace(-d[v],v);
		}
	}
	return d;
}

const long long INF=1LL<<61;

int main(){
	int n; cin>>n;
	vector<string> s(n);
	vector<lint> cost(n);
	rep(i,n) cin>>s[i]>>cost[i];

	map<pair<string,int>,int> f; // (string, prefix or suffix) -> id
	rep(i,n){
		rep(j,s[i].length()+1){
			// prefix
			string t=s[i].substr(0,j);
			if(f.count({t,0})==0) f[{t,0}]=f.size();
			// suffix
			t=s[i].substr(s[i].length()-j);
			if(f.count({t,1})==0) f[{t,1}]=f.size();
		}
	}

	int N=f.size()+1,src=f.size();
	weighted_graph<lint> G(N);
	rep(i,n){
		add_directed_edge(G,src,f[{s[i],1}],cost[i]);
		rep(j,s[i].length()+1){
			// prefix
			string t=s[i].substr(0,j);
			string r=t;
			reverse(r.begin(),r.end());
			rep(k,n){
				int len1=s[k].length(),len2=t.length();
				if(s[k].substr(0,min(len1,len2))==r.substr(0,min(len1,len2))){
					int next;
					if(len1<=len2){
						next=f[{t.substr(0,len2-len1),0}];
					}
					else{
						next=f[{s[k].substr(len2),1}];
					}
					add_directed_edge(G,f[{t,0}],next,cost[k]);
				}
			}
			// suffix
			t=s[i].substr(s[i].length()-j);
			r=t;
			reverse(r.begin(),r.end());
			rep(k,n){
				int len1=s[k].length(),len2=t.length();
				if(s[k].substr(len1-min(len1,len2))==r.substr(len2-min(len1,len2))){
					int next;
					if(len1<=len2){
						next=f[{t.substr(len1,len2),1}];
					}
					else{
						next=f[{s[k].substr(0,len1-len2),0}];
					}
					add_directed_edge(G,f[{t,1}],next,cost[k]);
				}
			}
		}
	}

	auto d=Dijkstra(G,src);

	lint ans=INF;
	for(auto p:f){
		string t=p.first.first;
		string r=t;
		reverse(r.begin(),r.end());
		if(t==r) ans=min(ans,d[p.second]);
	}
	cout<<(ans<INF?ans:-1)<<'\n';

	return 0;
}
