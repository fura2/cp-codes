#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

bool check(string s,long long n){
	int m=s.length();
	rep(i,m) if(s[i]=='?') s[i]='0';
	return stoll(s,nullptr,2)<=n;
}

int main(){
	string s;
	long long n;
	cin>>s>>n;

	int m=s.length();
	rep(i,m){
		if(s[i]=='?'){
			s[i]='1';
			if(!check(s,n)){
				s[i]='0';
			}
		}
	}

	if(check(s,n)){
		cout<<stoll(s,nullptr,2)<<endl;
	}
	else{
		cout<<-1<<endl;
	}

	return 0;
}
