#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s,t; cin>>s>>t;
	int n=s.length();

	vector<int> pos[128];
	rep(i,n) pos[s[i]].emplace_back(i);

	int cnt=0,idx=-1;
	for(char c:t){
		if(pos[c].empty()){ cout<<-1<<endl; return 0; }

		auto it=upper_bound(pos[c].begin(),pos[c].end(),idx);
		if(it!=pos[c].end()){
			idx=*it;
		}
		else{
			cnt++;
			idx=pos[c][0];
		}
	}
	cout<<(long long)n*cnt+idx+1<<endl;

	return 0;
}
