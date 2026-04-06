#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,l; scanf("%d%d ",&n,&l);
	int ans=0,cnt=1;
	rep(i,n){
		if(getchar()=='+'){
			cnt++;
			if(cnt>l) cnt=1, ans++;
		}
		else cnt--;
	}
	printf("%d\n",ans);
	return 0;
}
