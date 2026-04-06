#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,x; scanf("%d%d",&n,&x);
	if(x==1 || x==2*n-1) puts("No");
	else{
		puts("Yes");
		vector<int> sign(2*n-1);
		if(x<=n){
			fill(sign.begin(),sign.end(),1);
			rep(i,x-1) sign[n+i]=-1;
		}
		else{
			fill(sign.begin(),sign.end(),-1);
			rep(i,(2*n-1)-x) sign[n+i]=1;
		}
		sign[n-1]=0;

		int large=x+1,small=x-1;
		rep(i,2*n-1){
			if     (sign[i]>0) printf("%d\n",large), large++;
			else if(sign[i]<0) printf("%d\n",small), small--;
			else               printf("%d\n",x);
		}
	}

	return 0;
}
