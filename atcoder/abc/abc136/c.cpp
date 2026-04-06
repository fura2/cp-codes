#include <cstdio>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,h[100000];
	scanf("%d",&n);
	rep(i,n) scanf("%d",h+i);

	for(int i=n-2;i>=0;i--){
		if(h[i]==h[i+1]+1) h[i]--;
		else if(h[i]>h[i+1]+1){
			puts("No");
			return 0;
		}
	}
	puts("Yes");

	return 0;
}
