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

int knapSackRecursion(int wt[], int value[], int n, int W){
	if(n==0 || W<=0) return 0;
	if(wt[n-1] > W)
		return knapSackRecursion(wt, value, n-1, W);
	else
		return max(knapSackRecursion(wt, value, n-1, W), value[n-1]+knapSackRecursion(wt, value, n-1, W-wt[n-1]));
}

int knapSackMemoize(int wt[], int value[], int n, int W, vector<vector<int> > &dp){
	if(n==0 || W<= 0) return 0;
	if(dp[n][W] != -1)
		return dp[n][W];
	else{
		if(wt[n-1] > W)
			dp[n][W] = knapSackMemoize(wt, value, n-1, W, dp);
		else
			dp[n][W] = max(knapSackMemoize(wt, value, n-1, W, dp), value[n-1]+knapSackMemoize(wt, value, n-1, W-wt[n-1], dp));
	}
	return dp[n][W];
}

int knapSackTabulation(int wt[], int value[], int n, int W){
	int dp[n+1][W+1];
	for(int i=0; i<=n; ++i)
		dp[i][0] = 0;
	for(int i=0; i<=W; ++i)
		dp[0][i] = 0;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=W; ++j){
			if(wt[i-1] > j)
				dp[i][j] = dp[i-1][j];
			else
				dp[i][j] = max(dp[i-1][j], value[i-1]+dp[i-1][j-wt[i-1]]);
		}
	}
	return dp[n][W];
}

int knapSack(int wt[], int value[], int n, int W){
	// vector<vector<int> > dp(n+1, vector<int>(W+1, -1));
	return knapSackTabulation(wt, value, n, W);
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,W;
		cin>>n>>W;
		int wt[n], value[n];
		for(int i=0;i<n; ++i)
			cin>>value[i];
		for(int i=0; i<n; ++i)
			cin>>wt[i];
		cout<<knapSack(wt, value, n, W)<<endl;
	}
	return 0;
}


// SAMPLE TEST CASE
// 2
// 3
// 4
// 1 2 3
// 4 5 1
// 3
// 3
// 1 2 3
// 4 5 6
// EXPECTED OUTPUT
// 3
// 0