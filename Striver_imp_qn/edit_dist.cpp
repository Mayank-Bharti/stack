// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
// You have the following three operations permitted on a word:
// Insert a character
// Delete a character
// Replace a character
// Example 1:
// Input: word1 = "horse", word2 = "ros"
// Output: 3
// Explanation: 
// horse -> rorse (replace 'h' with 'r')
// rorse -> rose (remove 'r')
// rose -> ros (remove 'e')
// Example 2:
// Input: word1 = "intention", word2 = "execution"
// Output: 5
// Explanation: 
// intention -> inention (remove 't')
// inention -> enention (replace 'i' with 'e')
// enention -> exention (replace 'n' with 'x')
// exention -> exection (replace 'n' with 'c')
// exection -> execution (insert 'u')
// Constraints:
// 0 <= word1.length, word2.length <= 500
// word1 and word2 consist of lowercase English letters.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

//Memoization: TC=> O(N*M)  SC=>O(N*M)+O(N)+O(M)

    // int func(string& word1, string& word2, int i, int j,vector<vector<int>>&dp){
    //     if(i==0){
    //         return j;
    //     }
    //     if(j==0){
    //         return i;
    //     }
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     if(word1[i-1]==word2[j-1]){
    //        return dp[i][j]=func(word1,word2,i-1,j-1,dp);
    //     }
    //     return dp[i][j]=1+min({func(word1,word2,i-1,j-1,dp),func(word1,word2,i-1,j,dp),func(word1,word2,i,j-1,dp)});
    // }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        
        //TABULATION: TC=> O(N*M)+O(N)+O(M)  SC=>O(N*M)

        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // // int ans=func(word1,word2,n,m,dp);
        // // return ans;
        // for(int i=0;i<=n;i++){
        //     dp[i][0]=i;
        // }
        // for(int j=1;j<=m;j++){
        //     dp[0][j]=j;
        // }
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=m;j++){
        //         if(word1[i-1]==word2[j-1]){
        //             dp[i][j]=dp[i-1][j-1];
        //         }
        //         else{
        //             dp[i][j]=1+min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
        //         }
        //     }
        // }
        // return dp[n][m];

        //SPACE OPTIMIZATION: TC=> O(N*M)+O(M) SC=>O(2*M)

        vector<int>prev(m+1,0);
        vector<int>curr(m+1,0);
        // prev[0]=0;
        for(int j=1;j<=m;j++){
            prev[j]=j;
        }
        for(int i=1;i<=n;i++){
            curr[0]=i;
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    curr[j]=prev[j-1];
                }
                else{
                    curr[j]=1+min({prev[j-1],prev[j],curr[j-1]});
                }
            }
            prev=curr;
        }
        return prev[m];

    }
};

int main(){
    Solution sol;
    string word1;
    string word2;
    cin>>word1;
    cin>>word2;
    int ans=sol.minDistance(word1,word2);
    cout<<ans<<endl;

}