#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int n=s.length();

	int cnt=0,del=0;
	rep(i,n){
		if(s[i]=='S'){
			cnt++;
		}
		else{
			if(cnt>0){
				cnt--;
				del++;
			}
		}
	}
	printf("%d\n",n-2*del);

	return 0;
}
