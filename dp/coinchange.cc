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

ll coinChangeRecursion(int coins[], int n, int amount){
	if(amount==0) return 1;
	if(n==0) return 0;
	if(amount<coins[n-1])
		return coinChangeRecursion(coins, n-1, amount);
	return coinChangeRecursion(coins, n, amount-coins[n-1]) + coinChangeRecursion(coins, n-1, amount);
}

ll coinChangeMemoization(int coins[], int n, int amount, vector<vector<int> > &dp){
	if(amount == 0) return 1;
	if(n==0) return 0;
	if(dp[n][amount] != -1) return dp[n][amount];
	else{
		if(amount < coins[n-1])
			dp[n][amount] = coinChangeMemoization(coins, n-1, amount, dp);
		else
			dp[n][amount] = coinChangeMemoization(coins, n, amount-coins[n-1], dp) + coinChangeMemoization(coins, n-1, amount, dp);
	}
	return dp[n][amount];
}

ll coinChangeTabulation(int coins[], int n, int amount){ 
	int dp[n+1][amount+1];
	for(int i=0;i<=n;++i) dp[i][0] = 1;
	for(int i=1;i<=amount;++i) dp[0][i] = 0;
	for(int i=1;i<=n;++i){
		for(int j=1; j<=amount; ++j){
			if(j<coins[i-1])
				dp[i][j] = dp[i-1][j];
			else
				dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
		}
	}
	return dp[n][amount];
}

ll coinChangeTabulationOptimized(int coins[], int n, int amount){
	int dp[amount+1] = {0};
	dp[0] = 1;
	for(int i=0;i<n;++i){
		for(int j=1; j<=amount;++j){
			if(j>=coins[i])
				dp[j] += dp[j-coins[i]];
		}
	} 
	return dp[amount];
} 

int main(){
	int t;
	cin>>t;
	while(t--){
		int n, amount;
		cin>>n;
		int coins[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>coins[i];
		}
		cin>>amount;
		// vector<vector<int> > dp(n+1, vector<int>(amount+1, -1));
		cout<<coinChangeTabulationOptimized(coins, n, amount)<<endl;
	}
	return 0;
}

// Sample Test Case
// 2
// 3
// 1 2 3
// 4
// 4
// 2 5 3 6
// 10

// Expected Output
// 4
// 5