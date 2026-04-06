#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);

	if(n==3) return puts("2 3 25"),0;

	vector<int> ans={2,3,4,9};

	vector<int> A0={6},A2={8},A3,A4;
	for(int i=10;i<=30000;i++){
		if(i%6==0) A0.emplace_back(i);
		if(i%6==2) A2.emplace_back(i);
		if(i%6==3) A3.emplace_back(i);
		if(i%6==4) A4.emplace_back(i);
	}

	while(n-ans.size()>=2 && A2.size()>0 && A4.size()>0){
		ans.emplace_back(A2.back()); A2.pop_back();
		ans.emplace_back(A4.back()); A4.pop_back();
	}
	while(n-ans.size()>=2 && A3.size()>=2){
		ans.emplace_back(A3.back()); A3.pop_back();
		ans.emplace_back(A3.back()); A3.pop_back();
	}
	while(n-ans.size()>0){
		ans.emplace_back(A0.back()); A0.pop_back();
	}

	rep(i,n) printf("%d%c",ans[i],i<n-1?' ':'\n');

	return 0;
}
