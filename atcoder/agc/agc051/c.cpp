#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> r(n),c(n);
	rep(i,n) scanf("%d%d",&r[i],&c[i]), r[i]--, c[i]--;

	int s[4]={}; // s[0]: 000, s[1]: 001, s[2]:010, s[3]:100
	{
		auto R=r;
		sort(R.begin(),R.end());
		R.erase(unique(R.begin(),R.end()),R.end());

		map<int,int> f[3];
		rep(i,n) ++f[c[i]%3][r[i]];
		for(int row:R){
			int mask=0;
			rep(col,3){
				mask|=(f[col][row]%2)<<(2-col);
			}
			if     (mask==0 || mask==7) s[0]++;
			else if(mask==1 || mask==6) s[1]++;
			else if(mask==2 || mask==5) s[2]++;
			else                        s[3]++;
		}
		s[0]++;
	}

	int t[3]={};
	{
		map<int,int> f;
		rep(i,n) ++f[c[i]];
		for(auto [col,cnt]:f){
			t[col%3]+=cnt%2;
		}
	}

	int ans=n;
	rep(i0,min(s[0],1)+1) rep(i1,min(s[1],1)+1) rep(i2,min(s[2],1)+1) rep(i3,min(s[3],1)+1) {
		int X=s[3],Y=s[2],Z=s[1];
		Z-=i1;
		Y-=i2;
		X-=i3;
		X+=i0; Y+=i0; Z+=i0;
		X+=i1; Y+=i1;
		X+=i2; Z+=i2;
		Y+=i3; Z+=i3;

		if(!(X%2==t[0]%2 && Y%2==t[1]%2 && Z%2==t[2]%2)) continue;

		// 001 を反転させる
		for(int j1=0;i1+j1<=s[1];j1+=2) ans=min(ans,max(t[0],X+j1)+max(t[1],Y+j1)+max(t[2],Z-j1));
		// 010 を反転させる
		for(int j2=0;i1+j2<=s[2];j2+=2) ans=min(ans,max(t[0],X+j2)+max(t[1],Y-j2)+max(t[2],Z+j2));
		// 100 を反転させる
		for(int j3=0;i1+j3<=s[3];j3+=2) ans=min(ans,max(t[0],X-j3)+max(t[1],Y+j3)+max(t[2],Z+j3));
	}
	printf("%d\n",ans);

	return 0;
}
