#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using lint=long long;

const long long INF=1LL<<61;

vector<pair<lint,lint>> merge(vector<pair<lint,lint>> I){
	sort(I.begin(),I.end(),[](const auto& i,const auto& j){
		return i.second<j.second;
	});

	vector<pair<lint,lint>> res;
	lint l=INF,r=INF;
	for(auto& iv:I){
		if(r<iv.first){
			if(l!=INF){
				while(!res.empty() && l<=res.back().second){
					l=min(l,res.back().first);
					res.pop_back();
				}
				res.emplace_back(l,r);
			}
			l=iv.first;
			r=iv.second;
		}
		else{
			l=min(l,iv.first);
			r=iv.second;
		}
	}
	if(l!=INF){
		while(!res.empty() && l<=res.back().second){
			l=min(l,res.back().first);
			res.pop_back();
		}
		res.emplace_back(l,r);
	}
	return res;
}

// Iに含まれない正整数のうち、tarより小さいものの個数を求める
lint count(vector<pair<lint,lint>> I,lint tar){
	lint res=0;
	lint x=1;
	for(auto& iv:I){
		res+=max(min(iv.first,tar)-x,0LL);
		x=iv.second;
	}
	res+=max(tar-x,0LL);
	return res;
}

// Iに含まれない正整数を小さい順にk個出力
void print(vector<pair<lint,lint>> I,int k){
	lint x=1;
	for(auto& iv:I){
		for(;x<iv.first;x++){
			if(k==0) return;
			cout<<x<<' ';
			k--;
		}
		x=iv.second;
	}
	for(;k>0;x++){
		cout<<x<<' ';
		k--;
	}
}

int main(){
	int n,k; cin>>n>>k;
	vector<lint> a(n);
	rep(i,n) cin>>a[i];

	sort(a.begin(),a.end());

	{
		const int M=1e6;
		bool ok[M+1]={};
		ok[0]=true;
		rep(i,n) if(a[i]<=M) {
			for(int x=M-a[i];x>=0;x--) if(ok[x]) ok[x+a[i]]=true;
		}
		vector<int> NG;
		rep(x,M+1) if(!ok[x] && NG.size()<k) NG.emplace_back(x);
		if(NG.size()==k){
			for(auto x:NG) cout<<x<<' ';
			return 0;
		}
	}

	const int M_small=1e4;
	const int M=60*M_small;
	bool ok[M+1]={};
	ok[0]=true;
	rep(i,n) if(a[i]<=M_small) {
		for(int x=M-a[i];x>=0;x--) if(ok[x]) ok[x+a[i]]=true;
	}
	vector<pair<lint,lint>> I;
	for(int x=0,pre=0;x<=M+1;x++){
		if(x==M+1 || ok[x]!=ok[pre]){
			if(ok[pre]){
				I.emplace_back(pre,x);
			}
			pre=x;
		}
	}

	rep(i,n) if(a[i]>M_small) {
		if(count(I,a[i])>=k){
			break;
		}
		int m=I.size();
		rep(j,m){
			I.emplace_back(I[j].first+a[i],I[j].second+a[i]);
		}
		I=merge(I);
	}
	print(I,k);

	return 0;
}
