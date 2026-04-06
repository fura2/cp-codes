#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

vector<string> B;

bool solve1(int h,int w,int a,int b){
	if(h%2==1){
		rep(j,w/2){
			if(a>0){
				B[h-1][2*j+0]='<';
				B[h-1][2*j+1]='>';
				a--;
			}
		}
	}
	if(w%2==1){
		rep(i,h/2){
			if(b>0){
				B[2*i+0][w-1]='^';
				B[2*i+1][w-1]='v';
				b--;
			}
		}
	}
	rep(i,h/2) rep(j,w/2) {
		if(a>0){
			rep(d,2) if(a>0) {
				B[2*i+d][2*j+0]='<';
				B[2*i+d][2*j+1]='>';
				a--;
			}
		}
		else if(b>0){
			rep(d,2) if(b>0) {
				B[2*i+0][2*j+d]='^';
				B[2*i+1][2*j+d]='v';
				b--;
			}
		}
	}
	return a==0 && b==0;
}

bool solve2(int h,int w,int a,int b){
	if(h%2==0 || w%2==0 || h==1 || w==1 || a<2 || b<2) return false;

	B[h-3][w-3]='<'; B[h-3][w-2]='>'; B[h-3][w-1]='^';
	B[h-2][w-3]='^'; B[h-2][w-2]='.'; B[h-2][w-1]='v';
	B[h-1][w-3]='v'; B[h-1][w-2]='<'; B[h-1][w-1]='>';
	a-=2;
	b-=2;

	rep(j,w/2-1){
		if(a>0){
			B[h-1][2*j+0]='<';
			B[h-1][2*j+1]='>';
			a--;
		}
	}
	rep(i,h/2-1){
		if(b>0){
			B[2*i+0][w-1]='^';
			B[2*i+1][w-1]='v';
			b--;
		}
	}
	rep(i,h/2) rep(j,w/2) {
		if(i==h/2-1 && j==w/2-1) continue;
		if(a>0){
			rep(d,2) if(a>0) {
				B[2*i+d][2*j+0]='<';
				B[2*i+d][2*j+1]='>';
				a--;
			}
		}
		else if(b>0){
			rep(d,2) if(b>0) {
				B[2*i+0][2*j+d]='^';
				B[2*i+1][2*j+d]='v';
				b--;
			}
		}
	}
	return a==0 && b==0;
}

int main(){
	int h,w,a,b; scanf("%d%d%d%d",&h,&w,&a,&b);
	B.assign(h,string(w,'.'));

	if(solve1(h,w,a,b) || solve2(h,w,a,b)){
		puts("YES");
		rep(i,h) cout<<B[i]<<'\n';
	}
	else{
		puts("NO");
	}

	return 0;
}
