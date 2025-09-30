#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

//Recursion: TC=> O(2^N)*O(2^M)
//Memoization: TC: O(N*M)  SC: O(N*M) + O(N+M)
//Tabulation: TC:O(N*M)+O(N)+O(M)  SC: O(N*M)
//Space Optimization: TC:O(N*M)+O(M) SC:O(2*M)

// Memoization approach for LCS
// int func(string text1, string text2,int t1, int t2,vector<vector<int>>&dp){
//         if(t1==0 || t2==0){
//             return 0;
//         }
//         if(dp[t1][t2]!=-1)return dp[t1][t2];
//         if(text1[t1-1]==text2[t2-1]){
//             return dp[t1][t2]=1+func(text1,text2,t1-1,t2-1,dp);
//         }
//         return dp[t1][t2]=max(func(text1,text2,t1,t2-1,dp),func(text1,text2,t1-1,t2,dp));
//     }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,-1));
        // int res=func(text1,text2,text1.size(),text2.size(),dp);
        // return res;

        //Tabulation
        // for(int i=0;i<=text1.size();i++){
        //     dp[i][0]=0;
        // }
        // for(int j=0;j<=text2.size();j++){
        //     dp[0][j]=0;
        // }
        // for(int i=1;i<=text1.size();i++){
        //     for(int j=1;j<=text2.size();j++){
        //         if(text1[i-1]==text2[j-1]){
        //             dp[i][j]=1+dp[i-1][j-1];
        //         }
        //         else{
        //             dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        //         }
        //     }
        // }
        // return dp[text1.size()][text2.size()];

        //Space optimization
        vector<int>prev(text2.size()+1,0);
        vector<int>curr(text2.size()+1,0);
        for(int j=0;j<=text2.size();j++){
            prev[j]=0;
        }
        for(int i=1;i<=text1.size();i++){
            for(int j=1;j<=text2.size();j++){
                if(text1[i-1]==text2[j-1]){
                    curr[j]=1+prev[j-1];
                }
                else{
                    curr[j]=max(prev[j],curr[j-1]);
                }
            }
            prev=curr;
        }
        return prev[text2.size()];
    }
};

int main(){
    Solution sol;
    string text1,text2;
    cout << "Enter first string: "; 
    cin >> text1; 
    cout << "Enter second string: "; 
    cin >> text2;
    int ans = sol.longestCommonSubsequence(text1,text2);
    cout << "Length of Longest Common Subsequence: " << ans << endl; 
    return 0;
}

//Now notes for Longest  palindromic Subsequence(LPS) is:
// If one string is given and we find reverse of it then LCS(string1, reverse(string1)) is LPS of given string
//How to make string palindrome by minimum inserting any character any where?
// Max no of operation which we required for making a string palindrome is len(given string) because given string + reverse(given string)=palindrome.So here we insert len(given string) in reverse way to make string palindrome.
// Approach: 1. keep longest palindrome portion intact. e.g. s='abcaa' then 'aca' or 'aaa' is intact: just add a bc a cb a , So how many string we insert i.e. 2 so, if len(string)-longest palindromic subsequence=minimum insertion to make string palindrome.

// For example: s= abcdefgh  rev(s)= hgfedcba LPS= 1 then min insertion= 8-1=7