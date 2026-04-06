#include <iostream>
#include <string>
#include <vector>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int n=s.length();

	vector<int> R,L;
	int rpre=0,lpre;
	for(int i=1;i<n;i++){
		if(s[i-1]=='R' && s[i]=='L'){
			R.emplace_back(i-rpre);
			lpre=i;
		}
		else if(s[i-1]=='L' && s[i]=='R'){
			L.emplace_back(i-lpre);
			rpre=i;
		}
	}
	L.emplace_back(n-lpre);

	rep(i,R.size()){
		rep(j,R[i]-1) printf("0 ");
		printf("%d %d ",(R[i]+1)/2+L[i]/2,(L[i]+1)/2+R[i]/2);
		rep(j,L[i]-1) printf("0 ");
	}

	return 0;
}
