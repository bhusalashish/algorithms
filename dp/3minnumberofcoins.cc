#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1E9
auto speedup = [](){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	#endif
	return 0;
}();

void coinChangeMinimum(int coins[], int n, int amount){
	int dp[n+1][amount+1];
	for(int i=0; i<=n; ++i)
		dp[i][0] = 0;
	for(int i=1; i<=amount; ++i)
		dp[0][i] = INF;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=amount; ++j){
			if(coins[i-1] > j){
				dp[i][j] = dp[i-1][j];
			}
			else{
				dp[i][j] = min(1+dp[i][j- coins[i-1]], dp[i-1][j]);
			}
		}
	}
	int val = dp[n][amount], i=n, j=amount;
	while(i>0){
		if(dp[i][j] != dp[i-1][j]){
			cout<<coins[i-1]<<" ";
			j = j-coins[i-1];
		}
		else
			i--;
	}
	cout<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int amount, n=10;
		cin>>amount;
		int coins[] = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
		coinChangeMinimum(coins, n, amount);
	}
	return 0;
}
