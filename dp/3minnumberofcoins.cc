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

ll coinChangeMin(int coins[], int n, int amount, std::vector<int> res){
	if(amount == 0) return 0;
	if(n==0) return INT_MAX;
	if(amount < coins[n-1])
		return coinChangeMin(coins, n-1, amount, res);
	return min(1+coinChangeMin(coins, n, amount-coins[n-1], res.push_back(coins[n-1])),  coinChangeMin(coins, n-1, amount, res));
}

ll coinChangeMinMemoize(int coins[], int n, int amount, vector<vector<int> > &dp){
	if(amount == 0) return 0;
	if(n==0) return INT_MAX;
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

int main(){
	int t;
	cin>>t;
	while(t--){
		int n=10, v;
		cin>>v;
		int coins[] = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
// 		for(int i=0;i<n;++i) cin>>coins[i];
// 		vector<vector<int> > dp(n+1, vector<int>(v+1, -1));
		std::vector<int> result;
		int res = coinChangeMin(coins, n, v, result);
		if(res == INT_MAX) cout<<-1<<endl;
		else cout<<res<<endl;
	}
	return 0;
}


// Sample Test Cases
// 1
// 43

// Expexted Output
// 20 20 2 1