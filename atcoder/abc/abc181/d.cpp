#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;

	if(s.length()==1){
		puts(stoi(s)%8==0?"Yes":"No");
		return 0;
	}
	if(s.length()==2){
		string t=s;
		swap(t[0],t[1]);
		puts(stoi(s)%8==0||stoi(t)%8==0?"Yes":"No");
		return 0;
	}

	int freq[10]={};
	for(char c:s) freq[c-'0']++;

	rep(d1,10) if(freq[d1]>0) {
		freq[d1]--;
		rep(d2,10) if(freq[d2]>0) {
			freq[d2]--;
			rep(d3,10) if(freq[d3]>0) {
				freq[d3]--;
				if((100*d1+10*d2+d3)%8==0){
					puts("Yes");
					return 0;
				}
				freq[d3]++;
			}
			freq[d2]++;
		}
		freq[d1]++;
	}
	puts("No");

	return 0;
}
