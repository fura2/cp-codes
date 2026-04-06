#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int d,g; cin>>d>>g;
	int p[10],c[10];
	rep(i,d) cin>>p[i]>>c[i];

	int ans=1000;
	rep(S,1<<d){
		int num=0,score=0;
		vector<int> rem;
		rep(i,d){
			if(S>>i&1){
				num+=p[i];
				score+=c[i]+100*(i+1)*p[i];
			}
			else{
				rep(j,p[i]) rem.emplace_back(100*(i+1));
			}
		}
		sort(rem.begin(),rem.end());
		while(!rem.empty() && score<g){
			num++;
			score+=rem.back();
			rem.pop_back();
		}
		if(score>=g) ans=min(ans,num);
	}
	cout<<ans<<endl;

	return 0;
}
