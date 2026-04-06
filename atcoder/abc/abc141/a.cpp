#include <iostream>
#include <string>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;

	if     (s=="Sunny")  cout<<"Cloudy"<<endl;
	else if(s=="Cloudy") cout<<"Rainy"<<endl;
	else                 cout<<"Sunny"<<endl;

	return 0;
}
