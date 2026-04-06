#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,a,b; scanf("%d%d%d",&n,&a,&b);
	vector<int> x(n);
	rep(i,n) scanf("%d",&x[i]);

	int x_min=*min_element(x.begin(),x.end());
	int x_max=*max_element(x.begin(),x.end());

	if(x_min==x_max){
		if(b==0) printf("%d %d\n",0,a);
		else     puts("-1");
		return 0;
	}

	double mean=0;
	rep(i,n) mean+=x[i];
	mean/=n;
	double p=1.0*b/(x_max-x_min);
	double q=a-p*mean;
	printf("%.9f %.9f\n",p,q);

	return 0;
}
