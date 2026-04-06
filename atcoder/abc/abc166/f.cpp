#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,a0,b0,c0; cin>>n>>a0>>b0>>c0;
	vector<string> s(n);
	rep(i,n) cin>>s[i];

	vector<vector<tuple<int,int,int>>> S(n+1);
	S[n]={{0,0,0}};
	for(int i=n-1;i>=0;i--){
		vector<tuple<int,int,int>> tmp;

		for(auto [a,b,c]:S[i+1]){
			if(s[i]=="AB"){
				tmp.emplace_back(a+1,max(b-1,0),c);
				tmp.emplace_back(max(a-1,0),b+1,c);
			}
			else if(s[i]=="BC"){
				tmp.emplace_back(a,b+1,max(c-1,0));
				tmp.emplace_back(a,max(b-1,0),c+1);
			}
			else{
				tmp.emplace_back(a+1,b,max(c-1,0));
				tmp.emplace_back(max(a-1,0),b,c+1);
			}
		}

		sort(tmp.begin(),tmp.end());
		tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());

		rep(j,tmp.size()){
			auto [aj,bj,cj]=tmp[j];
			bool ok=true;
			rep(k,tmp.size()) if(j!=k) {
				auto [ak,bk,ck]=tmp[k];
				if(ak<=aj && bk<=bj && ck<=cj) ok=false;
			}
			if(ok) S[i].emplace_back(tmp[j]);
		}
	}

	auto check=[&](int a,int b,int c,int i){
		for(auto [ai,bi,ci]:S[i]){
			if(a>=ai && b>=bi && c>=ci) return true;
		}
		return false;
	};

	if(!check(a0,b0,c0,0)) return puts("No"),0;

	puts("Yes");
	rep(i,n){
		if(s[i]=="AB"){
			if(check(a0+1,b0-1,c0,i+1)){ puts("A"); a0++; b0--; continue; }
			if(check(a0-1,b0+1,c0,i+1)){ puts("B"); a0--; b0++; continue; }
		}
		else if(s[i]=="BC"){
			if(check(a0,b0+1,c0-1,i+1)){ puts("B"); b0++; c0--; continue; }
			if(check(a0,b0-1,c0+1,i+1)){ puts("C"); b0--; c0++; continue; }
		}
		else{
			if(check(a0+1,b0,c0-1,i+1)){ puts("A"); a0++; c0--; continue; }
			if(check(a0-1,b0,c0+1,i+1)){ puts("C"); a0--; c0++; continue; }
		}
	}

	return 0;
}
