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

ll coinChangeMin(int coins[], int n, int amount){
	if(amount == 0) return 0;
	if(n==0) return INF;
	if(amount < coins[n-1])
		return coinChangeMin(coins, n-1, amount);
	return min(1+coinChangeMin(coins, n, amount-coins[n-1]),  coinChangeMin(coins, n-1, amount));
}

ll coinChangeMinMemoize(int coins[], int n, int amount, vector<vector<int> > &dp){
	if(amount == 0) return 0;
	if(n==0) return INF;
	if(dp[n][amount] != -1)
		return dp[n][amount];
	else{
		if(amount < coins[n-1])
			dp[n][amount] = coinChangeMinMemoize(coins, n-1, amount, dp);
		else{
			dp[n][amount] = min(1 + coinChangeMinMemoize(coins, n, amount-coins[n-1], dp), coinChangeMinMemoize(coins, n-1, amount, dp));
		}
	}
	return dp[n][amount];
}

int coinChangeMinTabulation(int coins[], int n, int amount){
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
				dp[i][j] = min(1+dp[i][j-coins[i-1]], dp[i-1][j]);
			}
		}
	}
	return dp[n][amount];
}

int coinChangeMinTabulationOptimal(int coins[], int n, int amount){
	int dp[amount+1];
	dp[0] = 0;
	for(int i=1; i<=amount; ++i)
		dp[i] = INF;
	for(int i=0; i<n; ++i){
		for(int j=1; j<=amount; ++j){
			if(coins[i] <= j){
				dp[j] = min(dp[j], 1+dp[j - coins[i]]);
			}
		}
	}
	return dp[amount];
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n, v;
		cin>>v>>n;
		int coins[n];
		for(int i=0;i<n;++i) cin>>coins[i];
		// vector<vector<int> > dp(n+1, vector<int>(v+1, -1));
		int res = coinChangeMinTabulationOptimal(coins, n, v);
		if(res == INF) cout<<-1<<endl;
		else cout<<res<<endl;
	}
	return 0;
}	


// Sample Test Cases
// 3
// 7 2
// 1 2
// 30 3
// 25 10 5
// 11 4
// 9 6 5 1

// Expexted Output
// 4
// 2
// 2