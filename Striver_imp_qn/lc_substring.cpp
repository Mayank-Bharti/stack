//Difference between longest common subsequence and longest common substring is in substring , it is in continuous so else part is zero here.
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:

// int func(string text1, string text2,vector<vector<int>>&dp){
//         for(int i=0;i<=text1.size();i++){
//             dp[i][0]=0;
//         }
//         for(int j=0;j<=text2.size();j++){
//             dp[0][j]=0;
//         }
//         int ans=0;
//         for(int i=1;i<=text1.size();i++){
//             for(int j=1;j<=text2.size();j++){
//                 if(text1[i-1]==text2[j-1]){
//                     dp[i][j]=1+dp[i-1][j-1];
//                     ans=max(ans,dp[i][j]);
//                 }
//                 else{
//                     dp[i][j]=0;
//                 }
//             }
//         }
//         return ans;
//     }
//     int longestCommonSubstr(string& s1, string& s2) {
//         // your code here
//         vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,-1));
//         int res=func(s1,s2,dp);
//         return res;
        
//     }

int func(string text1, string text2,vector<int>&prev,vector<int>&curr){
        for(int j=0;j<=text2.size();j++){
            prev[j]=0;
        }
        int ans=0;
        for(int i=1;i<=text1.size();i++){
            for(int j=1;j<=text2.size();j++){
                if(text1[i-1]==text2[j-1]){
                    curr[j]=1+prev[j-1];
                    ans=max(ans,curr[j]);
                }
                else{
                    curr[j]=0;
                }
            }
            prev=curr;
        }
        return ans;
    }
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        vector<int>prev(s2.size()+1,0);
        vector<int>curr(s2.size()+1,0);
        int res=func(s1,s2,prev,curr);
        return res;
        
    }

};

int main(){
    Solution sol;
    string text1,text2;
    cout << "Enter first string: "; 
    cin >> text1; 
    cout << "Enter second string: "; 
    cin >> text2;
    int ans = sol.longestCommonSubstr(text1,text2);
    cout << "Length of Longest Common Substring: " << ans << endl; 
    return 0;
}