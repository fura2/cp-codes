#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w,n; scanf("%d%d%d",&h,&w,&n);
	vector<pair<int,int>> a;
	rep(i,n){
		int x1,y1,x2,y2; scanf("%d%d%d%d",&y1,&x1,&y2,&x2);
		if((x1==0 || x1==w || y1==0 || y1==h)
		&& (x2==0 || x2==w || y2==0 || y2==h)){
			auto add=[&](int x,int y){
				if     (y==0) a.emplace_back(x,i);
				else if(x==w) a.emplace_back(w+y,i);
				else if(y==h) a.emplace_back(w+h+(w-x),i);
				else          a.emplace_back(w+h+w+(h-y),i);
			};
			add(x1,y1);
			add(x2,y2);
		}
	}

	sort(a.begin(),a.end());

	stack<int> S;
	for(auto x:a){
		int i=x.second;
		if(S.empty() || S.top()!=i) S.push(i);
		else S.pop();
	}
	puts(S.empty()?"YES":"NO");

	return 0;
}
