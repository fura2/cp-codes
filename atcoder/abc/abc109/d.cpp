#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w; scanf("%d%d",&h,&w);
	int a[500][500];
	rep(i,h) rep(j,w) scanf("%d",a[i]+j);

	vector<tuple<int,int,int,int>> Op;
	rep(i,h-1) rep(j,w) if(a[i][j]%2==1) {
		a[i+1][j]++;
		Op.emplace_back(i,j,i+1,j);
	}
	rep(j,w-1) if(a[h-1][j]%2==1) {
		a[h-1][j+1]++;
		Op.emplace_back(h-1,j,h-1,j+1);
	}

	printf("%d\n",Op.size());
	for(auto o:Op) printf("%d %d %d %d\n",get<0>(o)+1,get<1>(o)+1,get<2>(o)+1,get<3>(o)+1);

	return 0;
}
