#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;
const int dx[]={0,-1,0,1},dy[]={1,0,-1,0};

int main(){
	int h,w; cin>>h>>w;
	vector<string> B(h);
	rep(i,h) cin>>B[i];

	enum{NO,UL,UR,LL,LR};
	vector d(5,vector(h,vector(w,INF)));
	d[NO][0][0]=0;
	deque<tuple<int,int,int>> Q;
	Q.emplace_back(make_tuple(NO,0,0));
	while(!Q.empty()){
		int type,x,y;
		tie(type,x,y)=Q.front(); Q.pop_front();

		if(x==h-1 && y==w-1){
			printf("%d\n",d[type][x][y]);
			break;
		}

		rep(k,4){
			int x2=x+dx[k],y2=y+dy[k];
			if(0<=x2 && x2<h && 0<=y2 && y2<w){
				int type2=-1;
				if(type==UL){
					if(k==0) type2=UR;
					if(k==3) type2=LL;
				}
				else if(type==UR){
					if(k==2) type2=UL;
					if(k==3) type2=LR;
				}
				else if(type==LL){
					if(k==0) type2=LR;
					if(k==1) type2=UL;
				}
				else if(type==LR){
					if(k==1) type2=UR;
					if(k==2) type2=LL;
				}
				if(type2==-1 && B[x2][y2]=='.') type2=NO;

				if(type2!=-1 && d[type2][x2][y2]>d[type][x][y]){
					d[type2][x2][y2]=d[type][x][y];
					Q.emplace_front(type2,x2,y2);
				}

				for(int type2=1;type2<5;type2++){
					if(d[type2][x2][y2]>d[type][x][y]+1){
						d[type2][x2][y2]=d[type][x][y]+1;
						Q.emplace_back(type2,x2,y2);
					}
				}
			}
		}
	}

	return 0;
}
