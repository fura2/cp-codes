#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

struct trie{
	trie* l;
	trie* r;
	trie():l(nullptr),r(nullptr){}
};

void add(int i,const string& s,trie* t){
	if(i==s.length()) return;

	if(s[i]=='0'){
		if(!t->l) t->l=new trie;
		add(i+1,s,t->l);
	}
	else{
		if(!t->r) t->r=new trie;
		add(i+1,s,t->r);
	}
}

lint L;

lint grundy(int i,trie* t){
	if(i==L) return 0;

	if(!t){
		lint h=L-i,res=1;
		while(h%2==0){ h/=2; res*=2; }
		return res;
	}
	else{
		return grundy(i+1,t->l)^grundy(i+1,t->r);
	}
}

int main(){
// experiment
/*
	int g[100];
	g[1]=1;
	for(int i=2;i<70;i++){
		set<int> S{0};
		int x=0;
		for(int j=i-1;j>0;j--){
			x^=g[j];
			S.emplace(x);
		}
		for(int j=0;;j++){
			if(S.count(j)==0){
				g[i]=j;
				break;
			}
		}
	}
	rep(i,70) printf("g[%2d] = %2d\n",i,g[i]);
	return 0;
*/
	trie root;

	int n; cin>>n>>L;
	rep(i,n){
		string s; cin>>s;
		add(0,s,&root);
	}

	cout<<(grundy(0,root.l)^grundy(0,root.r)?"Alice":"Bob")<<endl;

	return 0;
}
