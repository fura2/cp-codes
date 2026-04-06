#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int choose(int n,int r){
	int res=1;
	for(int i=n;i>n-r;i--) res*=i;
	for(int i=r;i> 0 ;i--) res/=i;
	return res;
}

int f(int n,int r){ // n choose r (mod 3)
	int res=1;
	while(n>0 || r>0){
		res=res*choose(n%3,r%3)%3;
		n/=3;
		r/=3;
	}
	return res;
}

int main(){
	int n;
	string s; cin>>n>>s;

	int id[128];
	id['B']=0;
	id['W']=1;
	id['R']=2;

	int res=0;
	rep(i,n){
		res=(res+id[s[i]]*f(n-1,i))%3;
	}
	if(n%2==0) res=(3-res)%3;
	printf("%c\n","BWR"[res]);

	return 0;
}
