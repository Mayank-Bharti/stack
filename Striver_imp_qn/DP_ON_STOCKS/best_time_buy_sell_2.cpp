//Here we have to buy and sell as many times as want 
//We can't do Buy Buy Sell sell 
//When we buy then we must sell after that
// So here are lot of ways then recursion comes in mind
//1. Express everything in terms of index and one more variable which said we have to buy or not i.e. if in previously we already buy then we are not allowed to buy again.
//2. Explore all possibilities on that day
//3. Take max of all profits.
//4. Base case

//Recurrence-> 0 to n with base case n then tabulation n->0 base case n and vice versa
//IT MEANS TABULATION START WITH BASE CASE BUT RECUURRENCE START WITH BIG PROBLEMS AND BREAKS INTO SMALL PART AND COME T BASE CASE.

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
//Memoization: TC=> O(N*2) SC=> O(N*2)+O(N)=> dp vector space +recursion stack space.
//   int f(int ind,int buy, vector<int>&prices,int n,vector<vector<int>>&dp){
//     if(ind==n){
//         return 0;
//     }
//     if(dp[ind][buy]!=-1)return dp[ind][buy];
//     int profit=0;
//     if(buy){
//         profit=max(-prices[ind]+f(ind+1,0,prices,n,dp),
//                    0+f(ind+1,1,prices,n,dp));
//     }
//     else{
//         profit=max(prices[ind]+f(ind+1,1,prices,n,dp),
//                     0+f(ind+1,0,prices,n,dp));
//     }
//     return dp[ind][buy]=profit;
//   }

//TABULATION: TC=> O(N*2) SC=> O(N*2)=> DP VECTOR SPACE 
  int maxProfit(vector<int>&prices){
    int n=prices.size();
    // vector<vector<int>>dp(n,vector<int>(2,-1));
    // vector<vector<int>>dp(n+1,vector<int>(2,0));
    // // return f(0,1,prices,n,dp);
    // dp[n][0]=dp[n][1]=0;
    // for(int i=n-1;i>=0;i--){
    //     for(int buy=0;buy<=1;buy++){
    //         int profit=0;
    //         if(buy){
    //             profit=max(-prices[i]+dp[i+1][0],0+dp[i+1][1]);
    //         }
    //         else{
    //             profit=max(prices[i]+dp[i+1][1],0+dp[i+1][0]);
    //         }
    //         dp[i][buy]=profit;
    //     }
    // }
    // return dp[0][1];

    //SPACE OPTIMIZATION: TC=> O(N*2)  SC=> O(2)

    vector<int>prev(2,0);
    // vector<int>curr(2,0);
    // curr[0]=curr[1]=0;
    prev[0]=prev[1]=0;
    for(int i=n-1;i>=0;i--){
        for(int buy=0;buy<=1;buy++){
            int profit=0;
            if(buy){
                profit=max(-prices[i]+prev[0],0+prev[1]);
            }
            else{
                profit=max(prices[i]+prev[1],0+prev[0]);
            }
            //curr[buy]=profit;
            prev[buy]=profit;
        }
        // prev=curr;
    }
    // return curr[1];
    return prev[1];
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

//Explain space optimization code using variables not in case of vectors

//For best time to buy and sell stock with transaction fee => just subtract fee selling stock.
//  else{
//     profit=max(prices[i]+prev[1]-fee,0+prev[0]); //only that much change
//   }