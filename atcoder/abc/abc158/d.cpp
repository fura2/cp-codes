#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s1,s2,s3;
	int q,t=0; cin>>s1>>q;
	rep(_,q){
		int type; scanf("%d",&type); type--;
		if(type==0){
			t^=1;
		}
		else{
			char c; scanf("%d %c",&type,&c); type--;
			if(type==t) s2+=c;
			else        s3+=c;
		}
	}

	if(t==0){
		reverse(s2.begin(),s2.end());
		cout<<s2<<s1<<s3<<'\n';
	}
	else{
		reverse(s3.begin(),s3.end());
		reverse(s1.begin(),s1.end());
		cout<<s3<<s1<<s2<<'\n';
	}

	return 0;
}
