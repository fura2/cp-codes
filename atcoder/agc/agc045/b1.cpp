// O(N log N) solution (公式解説の解法)

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int f(string s,int th){ // 累積和の最大値が th 以下という条件のもとで, 累積和の最小値としてありうる最大の値
	int n=s.length();
	vector<int> cum(n+1);
	rep(i,n){
		if(s[i]=='1') cum[i+1]=cum[i]+1;
		else          cum[i+1]=cum[i]-1;
	}
	multiset<int> S(cum.begin(),cum.end());

	int up=0;
	rep(i,n){
		S.erase(S.find(cum[i]));
		if(s[i]=='?'){
			if(*S.rbegin()+2*up<=th-2){
				s[i]='1';
				up++;
			}
			else{
				s[i]='0';
			}
		}
	}

	int mn=0,y=0;
	rep(i,n){
		if(s[i]=='0') y--;
		else          y++;
		mn=min(mn,y);
	}
	return mn;
}

int main(){
	string s; cin>>s;
	int n=s.length();

	int mx=0,tmp=0;
	rep(i,n){
		if(s[i]=='1') tmp++;
		else          tmp--;
		mx=max(mx,tmp);
	}

	printf("%d\n",min(mx-f(s,mx),mx+1-f(s,mx+1)));

	return 0;
}
