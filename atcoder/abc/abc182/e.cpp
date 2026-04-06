#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w,n,m; scanf("%d%d%d%d",&h,&w,&n,&m);
	vector B(h,vector(w,0));
	rep(i,n){
		int x,y; scanf("%d%d",&x,&y); x--; y--;
		B[x][y]=1;
	}
	rep(i,m){
		int x,y; scanf("%d%d",&x,&y); x--; y--;
		B[x][y]=-1;
	}

	rep(_,2){
		rep(i,h){
			rep(__,2){
				bool ok=false;
				rep(j,w){
					if(B[i][j]==1){
						ok=true;
					}
					else if(B[i][j]==0){
						if(ok) B[i][j]=2;
					}
					else if(B[i][j]==-1){
						ok=false;
					}
				}
				rep(j,w/2) swap(B[i][j],B[i][w-j-1]);
			}
		}

		// transpose
		auto tmp=B;
		B.assign(w,vector(h,0));
		rep(i,h) rep(j,w) B[j][i]=tmp[i][j];
		swap(h,w);
	}

	int ans=0;
	rep(i,h) rep(j,w) if(B[i][j]>=1) ans++;
	printf("%d\n",ans);

	return 0;
}
