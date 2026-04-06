#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	string s; cin>>n>>s;

	vector<char> S;
	for(char c:s){
		S.emplace_back(c);
		while(1){
			int len=S.size();
			if(len>=3 && S[len-3]=='f' && S[len-2]=='o' && S[len-1]=='x'){
				S.pop_back();
				S.pop_back();
				S.pop_back();
			}
			else break;
		}
	}
	printf("%ld\n",S.size());

	return 0;
}
