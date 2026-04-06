#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int n=s.length();

	int cnt=0;
	rep(i,n/2) if(s[i]==s[n-i-1]) cnt++;

	if(cnt==n/2){
		printf("%d\n",25*(n/2*2));
	}
	else if(cnt==n/2-1){
		printf("%d\n",25*(n-2)+24*2);
	}
	else{
		printf("%d\n",25*n);
	}

	return 0;
}
