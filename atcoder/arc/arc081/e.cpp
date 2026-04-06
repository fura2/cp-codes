#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int n=s.length();

	bool used[128]={};
	int cnt=0,l=1;
	vector<int> len(n+1); // len[i] = minimum length for s[i..)
	for(int i=n-1;i>=0;i--){
		if(!used[s[i]]){
			used[s[i]]=true;
			cnt++;
			if(cnt==26){
				for(char c='a';c<='z';c++) used[c]=false;
				cnt=0;
				l++;
			}
		}
		len[i]=l;
	}
	len[n]=1;

	vector<int> pos[128];
	rep(i,n) pos[s[i]].emplace_back(i);
	for(char c='a';c<='z';c++) pos[c].emplace_back(n);

	string ans;
	int idx=0;
	rep(i,len[0]){
		for(char c='a';c<='z';c++){
			int p=*lower_bound(pos[c].begin(),pos[c].end(),idx);
			if(p==n || len[p+1]==len[0]-i-1){
				idx=p+1;
				ans+=c;
				break;
			}
		}
	}
	cout<<ans<<endl;

	return 0;
}
