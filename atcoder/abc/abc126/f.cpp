#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int m,k; scanf("%d%d",&m,&k);

	if(m==1){
		puts(k==0?"0 0 1 1":"-1");
		return 0;
	}

	if(k>=(1<<m)){
		puts("-1");
	}
	else{
		for(int i=0;i<=(1<<m)-1;i++) if(i!=k) printf("%d ",i);
		printf("%d ",k);
		for(int i=(1<<m)-1;i>=0;i--) if(i!=k) printf("%d ",i);
		printf("%d\n",k);
	}

	return 0;
}

// experimentation
/*
	int m; scanf("%d",&m);

	vector<int> p(2*m);
	rep(i,m) p[2*i]=p[2*i+1]=i+1;
	bool f[100]={};
	do{
		int a=-1;
		rep(i,m){
			vector<int> I;
			rep(j,2*m) if(p[j]==i+1) I.emplace_back(j);
			int x=0;
			for(int j=I[0];j<=I[1];j++) x^=p[j];
			if(a==-1) a=x;
			else if(a!=x){ a=-1; break; }
		}
		if(a!=-1 && f[a]) continue;
		if(a!=-1){
			f[a]=true;
			printf("%d is found!\n  ",a);
			for(int i:p) printf("%d ",i); puts("");
		}
	}while(next_permutation(p.begin(),p.end()));
*/
