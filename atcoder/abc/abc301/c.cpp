#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s,t;
	cin>>s>>t;
	int n=s.length();

	vector<int> freq1(128),freq2(128);
	rep(i,n){
		freq1[s[i]]++;
		freq2[t[i]]++;
	}

	for(int c='a';c<='z';c++){
		if(freq1[c]==freq2[c]) continue;

		if(c != 'a' && c != 't' && c != 'c' && c != 'o' && c != 'd' && c != 'e' && c != 'r'){
			puts("No");
			return 0;
		}
		else{
			if(freq1[c]<freq2[c]){
				if(freq1['@']<freq2[c]-freq1[c]){
					puts("No");
					return 0;
				}
				freq1['@']-=freq2[c]-freq1[c];
			}
			else{
				if(freq2['@']<freq1[c]-freq2[c]){
					puts("No");
					return 0;
				}
				freq2['@']-=freq1[c]-freq2[c];
			}
		}
	}
	puts("Yes");

	return 0;
}
