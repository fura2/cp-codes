#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	char B[100][101];
	rep(i,n) scanf("%s",B[i]);

	int ans=0;
	for(int i=n-1;i>=0;i--){
		int pos=find(B[i],B[i]+n,'.')-B[i];
		if(pos==n) continue;

		for(int j=pos;j<n;j++) B[i][j]='o';
		if(i>0){
			rep(j,pos+1) B[i-1][j]='o';
		}
		ans++;
	}
	printf("%d\n",ans);

	return 0;
}
