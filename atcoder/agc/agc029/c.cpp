#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

bool check(vector<int> a,int m){
	int n=a.size();

	vector<pair<int,int>> I;

	auto append=[&](int x,int len){
		if(I.empty() || I.back().first!=x){
			I.emplace_back(x,len);
		}
		else{
			I.back().second+=len;
		}
	};

	int last=0;
	rep(i,n){
		if(a[i]>last){
			append(0,a[i]-last);
		}
		else{
			int d=last-a[i];
			while(d>0){
				int mn=min(I.back().second,d);
				I.back().second-=mn;
				d-=mn;
				if(I.back().second==0) I.pop_back();
			}

			if(I.size()==1 && I[0].first==m-1) return false;

			if(I.back().first<m-1){
				int x=I.back().first;
				I.back().second--;
				if(I.back().second==0) I.pop_back();
				append(x+1,1);
			}
			else{
				int tail=I.back().second;
				I.pop_back();
				int x=I.back().first;
				I.back().second--;
				if(I.back().second==0) I.pop_back();
				append(x+1,1);
				append(0,tail);
			}
		}
		last=a[i];
	}

	return true;
}

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int lo=0,hi=n;
	while(hi-lo>1){
		int mi=(lo+hi)/2;
		if(check(a,mi)) hi=mi;
		else            lo=mi;
	}
	printf("%d\n",hi);

	return 0;
}
