//In part1-> 1 transactions
//In part 2-> unlimited transaction without overlapping
//In part 3-> At most 2 transactions

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
//Memoization: TC=> O(N*2*3) SC=> O(N*2*3)+O(N)=> dp vector space +recursion stack space.
//   int f(int ind,int buy,int cap, vector<int>&prices,int n,vector<vector<vector<int>>>&dp){
//     if(ind==n||cap==0){
//         return 0;
//     }
//     if(dp[ind][buy][cap]!=-1)return dp[ind][buy][cap];
//     int profit=0;
//     if(buy){
//         profit=max(-prices[ind]+f(ind+1,0,cap,prices,n,dp),
//                    0+f(ind+1,1,cap,prices,n,dp));
//     }
//     else{
//         profit=max(prices[ind]+f(ind+1,1,cap-1,prices,n,dp),
//                     0+f(ind+1,0,cap,prices,n,dp));
//     }
//     return dp[ind][buy][cap]=profit;
//   }

//TABULATION: TC=> O(N*2*3) SC=> O(N*2*3)=> DP VECTOR SPACE 
  int maxProfit(vector<int>&prices){
    int n=prices.size();
    // vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
    // return f(0,1,2,prices,n,dp);
    // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
    // dp[n][0][0]=dp[n][1][0]=0;
    // for(int i=n-1;i>=0;i--){
    //     for(int buy=0;buy<=1;buy++){
    //         for(int cap=1;cap<=2;cap++){
    //             int profit=0;
    //             if(buy){
    //                profit=max(-prices[i]+dp[i+1][0][cap],0+dp[i+1][1][cap]);
    //             }
    //             else{
    //                profit=max(prices[i]+dp[i+1][1][cap-1],0+dp[i+1][0][cap]);
    //             }
    //             dp[i][buy][cap]=profit;
    //         }
    //     }
    // }
    // return dp[0][1][2];

    //SPACE OPTIMIZATION: TC=> O(N*2*3)  SC=> O(2*3)

    vector<vector<int>>prev(2,vector<int>(3,0));
    // vector<vector<int>>curr(2,vector<int>(3,0));
    // curr[0][0]=curr[1][0]=0;
    prev[0][0]=prev[1][0]=0;  //no need to write base case as it is 0 already assigned in complete dp table
    for(int i=n-1;i>=0;i--){
        for(int buy=0;buy<=1;buy++){
            for(int cap=1;cap<=2;cap++){
                int profit=0;
                if(buy){
                    profit=max(-prices[i]+prev[0][cap],0+prev[1][cap]);
                }
                else{
                    profit=max(prices[i]+prev[1][cap-1],0+prev[0][cap]);
                }
                //curr[buy][cap]=profit;
                prev[buy][cap]=profit;
            }
        }
        // prev=curr;
    }
    // return curr[1][2];
    return prev[1][2];
  }
};
int main(){
    Solution sol;
    int n;
    cin>>n;
    vector<int>prices(n);
    for(int i=0;i<n;i++){
        cin>>prices[i];
    }
    int ans=sol.maxProfit(prices);
    cout<<ans<<endl;
}

// Best time to buy and sell-4 is similar to part 3 just chanje at most 2 transactions to k transactions.