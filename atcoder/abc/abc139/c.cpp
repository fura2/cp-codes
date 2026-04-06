#include <algorithm>
#include <cstdio>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	scanf("%d",&n);

	int y=-1,cnt=0,ans=0;
	rep(i,n){
		int h; scanf("%d",&h);
		if(y>=h) cnt++;
		else     cnt=0;
		y=h;
		ans=max(ans,cnt);
	}
	printf("%d\n",ans);

	return 0;
}
