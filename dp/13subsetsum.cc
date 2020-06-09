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

bool subsetSumRecursive(int nums[], int n, int sum){
	if(sum == 0) return true;
	if(n==0) return false;
	if(nums[n-1] > sum)
		return subsetSumRecursive(nums, n-1, sum);
	return subsetSumRecursive(nums, n-1, sum) || subsetSumRecursive(nums, n-1, sum-nums[n-1]);
}

bool subsetSum(int nums[], int n, int sum){
	bool dp[n+1][sum+1];
	for(int i=0; i<=n; ++i)
		dp[i][0] = true;
	for(int i=1; i<=sum; ++i)
		dp[0][i] = false;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=sum; ++j){
			if(nums[i-1] > j)
				dp[i][j] = dp[i-1][j];
			else
				dp[i][j] = dp[i-1][j] || dp[i-1][j- nums[i-1]];
		}
	}
	return dp[n][sum];
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int nums[n], sum=0;
		for(int i=0; i<n; ++i){
			cin>>nums[i];
			sum+=nums[i];
		}
		if(sum&1) cout<<"NO\n";
		else{
			if(subsetSum(nums, n, sum/2))
				cout<<"YES\n";
			else cout<<"NO\n";
		} 
	}
	return 0;
}

// SAMPLE TEST CASE
// 3
// 4
// 1 5 11 5
// 3
// 1 3 5 
// 8
// 478 757 314 471 729 100 459 618
// EXPECTED OUTPUT
// YES
// NO
// NO