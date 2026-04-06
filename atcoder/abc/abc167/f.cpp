#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	vector<string> s(n);
	vector<pair<int,int>> a(n);
	rep(i,n){
		cin>>s[i];
		int cnt=0,mn=0;
		for(char c:s[i]){
			if(c=='(') cnt++;
			else       cnt--, mn=min(mn,cnt);
		}
		a[i]={cnt,min(0,cnt)-mn};
	}

	vector<int> ord(n);
	iota(ord.begin(),ord.end(),0);

	sort(ord.begin(),ord.end(),[&](int i,int j){
		int ti=(a[i].first>=0?0:1);
		int tj=(a[j].first>=0?0:1);
		if(ti!=tj) return ti<tj;
		if(ti==0) return a[i].second<a[j].second;
		else      return a[i].second>a[j].second;
	});

	int cnt=0;
	for(int i:ord){
		for(char c:s[i]){
			if(c=='(') cnt++;
			else       cnt--;
			if(cnt<0) return puts("No"),0;
		}
	}
	puts(cnt==0?"Yes":"No");

	return 0;
}
