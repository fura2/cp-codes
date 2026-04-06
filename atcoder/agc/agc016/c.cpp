#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

vector<vector<int>> calc(int H,int W,int w){
	vector<vector<int>> res(H,vector<int>(W));
	rep(i,H){
		rep(j,W){
			res[i][j]=(j%w<w-1?100000:-100000*(w-1)-1);
		}
	}
	return res;
}

int main(){
	int H,W,h,w; scanf("%d%d%d%d",&H,&W,&h,&w);

	if(H%h==0 && W%w==0){
		puts("No");
	}
	else{
		puts("Yes");
		if(W%w!=0){
			auto ans=calc(H,W,w);
			rep(i,H) rep(j,W) printf("%d%c",ans[i][j],j<W-1?' ':'\n');
		}
		else{
			auto ans=calc(W,H,h);
			rep(i,H) rep(j,W) printf("%d%c",ans[j][i],j<W-1?' ':'\n');
		}
	}

	return 0;
}
