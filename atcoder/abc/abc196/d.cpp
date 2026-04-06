#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int h,w;
bool B[16][17];

int dfs(int i,int j,int a){
	if(i==h){
		return a==0?1:0;
	}
	if(j==w){
		return dfs(i+1,0,a);
	}

	int res=dfs(i,j+1,a);
	if(a>0 && i<h-1 && !B[i][j] && !B[i+1][j]){
		B[i][j]=B[i+1][j]=true;
		res+=dfs(i,j+1,a-1);
		B[i][j]=B[i+1][j]=false;
	}
	if(a>0 && j<w-1 && !B[i][j] && !B[i][j+1]){
		B[i][j]=B[i][j+1]=true;
		res+=dfs(i,j+1,a-1);
		B[i][j]=B[i][j+1]=false;
	}
	return res;
}

int main(){
	int a,b; scanf("%d%d%d%d",&h,&w,&a,&b);
	printf("%d\n",dfs(0,0,a));
	return 0;
}
