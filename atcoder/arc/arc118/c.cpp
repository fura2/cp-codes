#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	set<int> S;
	for(int x:{6,10,15}){
		for(int y=x;y<=10000;y+=x){
			S.emplace(y);
		}
	}
	for(int x:{6,10,15}) S.erase(x);

	int n; scanf("%d",&n);
	n-=3;
	printf("6 10 15");
	for(int x:S){
		if(n==0) break;
		n--;
		printf(" %d",x);
	}
	puts("");

	return 0;
}
