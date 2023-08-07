#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
	// your code goes here
	int t;cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<vector<int>>dp(n,vector<int>(n,0));
	    vector<vector<int>>arr(n,vector<int>(n,0));
	    for(int i=0;i<n;i++){
	        for(int j=0;j<=i;j++){
	            cin>>arr[i][j];
	        }
	    }
	    dp[0][0]=arr[0][0];
	    for(int j=1;j<n;j++){
	        for(int i=0;i<=j;i++){
	            if(i==j)
	            dp[j][i]=max(dp[j][i],dp[j-1][i-1])+arr[j][i];
	            else if(i==0)
	             dp[j][i]=max(dp[j][i],dp[j-1][i])+arr[j][i];
	            else
	            dp[j][i]=max(dp[j][i],max(dp[j-1][i-1],dp[j-1][i]))+arr[j][i];
	        }
	    }
	    int ans=0;
	    for(int i=0;i<n;i++){
	        ans=max(ans,dp[n-1][i]);
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
//dpState
//dp[i][j]=maximum path sum till index i if jth element if chosen

//recurrence relation
// dp[i][j]=dp[i-1][j-1],dp[i-1][j]+arr[i][j]

//Base case
// dp[0][0]=arr[0][0]
// ans=maxdp[n][i]|0...n-1
