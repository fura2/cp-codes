#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> a(n);
	rep(i,n) cin>>a[i];

	cout<<a[0];
	for(int i=1;i<n;i++){
		if(a[i-1]<a[i]){
			for(int x=a[i-1]+1;x<=a[i];x++) cout<<" "<<x;
		}
		else{
			for(int x=a[i-1]-1;x>=a[i];x--) cout<<" "<<x;
		}
	}
	cout<<endl;

	return 0;
}
