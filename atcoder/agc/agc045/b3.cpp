// O(N log N) solution (binary search)

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

bool check(const string& s,int T){ // 累積和の最大値と最小値の差を T 以下にできるか?
	int n=s.length();

	rep(parity,2){
		int y0=0,y1=T;
		if(y0%2!=parity) y0++;
		if(y1%2!=parity) y1--;

		bool ok=true;
		rep(i,n){
			if(s[i]=='0'){
				y0--;
				y1--;
				if(y1<0){
					ok=false;
					break;
				}
				if(y0<0) y0+=2;
			}
			else if(s[i]=='1'){
				y0++;
				y1++;
				if(y0>T){
					ok=false;
					break;
				}
				if(y1>T) y1-=2;
			}
			else{
				y0--;
				y1++;
				if(y0<0) y0+=2;
				if(y1>T) y1-=2;
			}
		}
		if(ok) return true;
	}
	return false;
}

int main(){
	string s; cin>>s;
	int n=s.length();

	int lo=0,hi=n;
	while(hi-lo>1){
		int mi=(lo+hi)/2;
		if(check(s,mi)) hi=mi;
		else            lo=mi;
	}
	printf("%d\n",hi);

	return 0;
}
