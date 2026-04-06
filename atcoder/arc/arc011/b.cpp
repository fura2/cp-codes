#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	map<char,int> f;
	f['b']=1;
	f['c']=1;
	f['d']=2;
	f['w']=2;
	f['t']=3;
	f['j']=3;
	f['f']=4;
	f['q']=4;
	f['l']=5;
	f['v']=5;
	f['s']=6;
	f['x']=6;
	f['p']=7;
	f['m']=7;
	f['h']=8;
	f['k']=8;
	f['n']=9;
	f['g']=9;
	f['z']=0;
	f['r']=0;

	int n; cin>>n;
	vector<string> ans;
	rep(i,n){
		string s,t; cin>>s;
		for(char c:s) if(f.count(tolower(c))==1) t+='0'+f[tolower(c)];
		if(!t.empty()) ans.emplace_back(t);
	}

	rep(i,ans.size()){
		cout<<ans[i];
		if(i+1<ans.size()) cout<<" ";
	}
	cout<<endl;

	return 0;
}
