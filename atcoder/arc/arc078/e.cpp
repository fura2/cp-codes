#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
// experiment
/*
	int N; printf("N? "); scanf("%d",&N);
	while(1){
		int n; printf("n? "); scanf("%d",&n);
		puts((n<=N && to_string(n)<=to_string(N))
		   ||(n> N && to_string(n)> to_string(N))?"Yes":"No");
	}
*/
	int e; // find e s.t. 10^e <= answer < 10^(e+1)
	puts("? 10000000000");
	fflush(stdout);
	char in; scanf(" %c",&in);
	if(in=='Y'){ // answer = 10^something
		int lo=0,hi=10;
		while(hi-lo>1){
			int mi=(lo+hi)/2;
			printf("? %s\n",string(mi,'9').c_str());
			fflush(stdout);

			scanf(" %c",&in);
			if(in=='Y') hi=mi;
			else        lo=mi;
		}
		e=lo;
	}
	else{
		int lo=0,hi=10;
		while(hi-lo>1){
			int mi=(lo+hi)/2;
			printf("? 1%s\n",string(mi,'0').c_str());
			fflush(stdout);

			scanf(" %c",&in);
			if(in=='Y') lo=mi;
			else        hi=mi;
		}
		e=lo;
	}

	lint lo=lint(pow(10,e)-1+0.5);
	lint hi=lint(pow(10,e+1)-1+0.5);
	while(hi-lo>1){
		lint mi=(lo+hi)/2;
		printf("? %lld0\n",mi);
		fflush(stdout);

		scanf(" %c",&in);
		if(in=='Y') hi=mi;
		else        lo=mi;
	}
	printf("! %lld\n",hi);

	return 0;
}
