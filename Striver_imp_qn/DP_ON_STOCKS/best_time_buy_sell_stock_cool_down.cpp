#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
// int f(int ind,int buy, vector<int>&prices,int n,vector<vector<int>>&dp){
//     if(ind>=n){
//         return 0;//When buy in n-1 position then sell according to condition occur at n+1 position which is out of bond >n not equal to n.. so for this condition we use base case as >=n
//     }
//     if(dp[ind][buy]!=-1)return dp[ind][buy];
//     int profit=0;
//     if(buy){
//         profit=max(-prices[ind]+f(ind+1,0,prices,n,dp),
//                    0+f(ind+1,1,prices,n,dp));
//     }
//     else{
//         profit=max(prices[ind]+f(ind+2,1,prices,n,dp),
//                     0+f(ind+1,0,prices,n,dp));
//     }
//     return dp[ind][buy]=profit;
//   }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<int>>dp(n,vector<int>(2,-1));
        // vector<vector<int>>dp(n+1,vector<int>(2,0));
        // return f(0,1,prices,n,dp);

    // for(int i=n-1;i>=0;i--){
    //     for(int buy=0;buy<=1;buy++){
    //         int profit=0;
    //         if(buy){
    //             profit=max(-prices[i]+dp[i+1][0],0+dp[i+1][1]);
    //         }
    //         else{
    //             profit=max(prices[i]+dp[i+2][1],0+dp[i+1][0]);
    //         }
    //         dp[i][buy]=profit;
    //     }
    // }
    // return dp[0][1];

    vector<int>prev1(2,0),prev2(2,0);
    // vector<int>curr(2,0);
    // curr[0]=curr[1]=0;
    prev1[0]=prev2[1]=0;
    for(int i=n-1;i>=0;i--){
        for(int buy=0;buy<=1;buy++){
            int profit=0;
            if(buy){
                profit=max(-prices[i]+prev1[0],0+prev1[1]);
            }
            else{
                profit=max(prices[i]+prev2[1],0+prev1[0]);
            }
            //curr[buy]=profit;
            prev2=prev1;
            prev1[buy]=profit;
        }
        // prev1=curr;
    }
    // return curr[1];
    return prev1[1];
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
