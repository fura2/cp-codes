#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int n=s.length();

	vector<int> a;
	int cnt=0;
	for(int i=n-1;i>=0;i--){
		if     (s[i]=='+') cnt++;
		else if(s[i]=='-') cnt--;
		else a.emplace_back(cnt);
	}

	sort(a.begin(),a.end());

	int m=a.size();
	printf("%d\n",accumulate(a.begin()+m/2,a.end(),0)-accumulate(a.begin(),a.begin()+m/2,0));

	return 0;
}
