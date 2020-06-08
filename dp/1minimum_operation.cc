#include<bits/stdc++.h>
using namespace std;
#define ll long long
auto speedup = [](){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	#endif
	return 0;
}();

int minimumOperations(int n){
	if(n==0) return 0;
	if(n&1) return 1 + minimumOperations(n-1);
	else return 1 + minimumOperations(n/2);
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<minimumOperations(n)<<endl;
	}
	return 0;
}
