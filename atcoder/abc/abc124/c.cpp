#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int n=s.length();

	int cnt1=0,cnt2=0;
	rep(i,n){
		if(i%2==0){
			if(s[i]=='0') cnt1++; else cnt2++;
		}
		else{
			if(s[i]=='1') cnt1++; else cnt2++;
		}
	}
	cout<<min(cnt1,cnt2)<<endl;

	return 0;
}
