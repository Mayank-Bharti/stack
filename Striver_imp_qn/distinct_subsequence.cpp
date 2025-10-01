// Given two strings s and t, return the number of distinct subsequences of s which equals t.
// The test cases are generated so that the answer fits on a 32-bit signed integer.
// Example 1:
// Input: s = "rabbbit", t = "rabbit"
// Output: 3
// Explanation:
// As shown below, there are 3 ways you can generate "rabbit" from s.
// Example 2:
// Input: s = "babgbag", t = "bag"
// Output: 5
// Explanation:
// As shown below, there are 5 ways you can generate "bag" from s.

// Approach: We have to follow different methods of comparing for finding no. of different subsequences of s which is equal to t.
//Kind of trying all ways.So its  recursion.
//How to write Recurrence?
//1. Express everythingnin terms of (i,j)i=s.length()-1 and j=t.length()-1
//2. Explore all possibilities: if(s[i]==t[j])return f(i-1,j-1)+f(i-1,j) else return f(i-1,j)
//3. Return summation of all possibilities
//4. Base case: if i match all chars of t then return 1 i.e. if(j<0)return 1; else if i won't match all chars and i is out of bound then return 0 i.e. if(i<0)return 0;
//5. TC=> exponential => 2^n*2^m  SC=> O(n+m) then we have to optimise it using overlapping subproblems.

//Memoization approach: TC=> O(n*m)=> no of states  SC=> O(n*m)=>no of states + O(n+m)=>auxiliary stack space

#include <bits/stdc++.h>
using namespace std;
class solution{
private:
// Memoization approach
//0 based indexing
    // int f(int i,int j,string&s , string&t,vector<vector<int>>&dp){
    //     if(j<0)return 1;
    //     if(i<0)return 0;
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     if(s[i]==t[j]){
    //        return dp[i][j]=f(i-1,j-1,s,t,dp)+f(i-1,j,s,t,dp);
    //     }
    //     return dp[i][j]=f(i-1,j,s,t,dp);
    // }
    //1 based indexing
    // int f(int i,int j,string&s , string&t,vector<vector<int>>&dp){
    //     if(j==0)return 1;
    //     if(i==0)return 0;
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     if(s[i-1]==t[j-1]){
    //        return dp[i][j]=f(i-1,j-1,s,t,dp)+f(i-1,j,s,t,dp);
    //     }
    //     return dp[i][j]=f(i-1,j,s,t,dp);
    // }
public:
    const int prime = 1e9 + 7;
    int numdistinct(string& s, string& t){
        int n=s.size();
        int m=t.size();
        // vector<vector<int>>dp(n,vector<int>(m,-1)); //0-based
        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1)); //1-based
        // return f(n-1,m-1,s,t,dp); //0-based
        // return f(n,m,s,t,dp);

        //Tabulation approach: TC=> O(n*m)+O(n)+O(m)  SC=> O(n*m)=>no of states
        // for(int i=0;i<=n;i++){
        //    dp[i][0]=1;
        // }
        // for(int j=1;j<=m;j++){
        //    dp[0][j]=0;
        // }
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=m;j++){
        //         if(s[i-1]==t[j-1]){
        //             dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%prime;  //signed integer overflow so run time error so we use mod prime
        //         }
        //         else{
        //             dp[i][j]=dp[i-1][j];
        //         }
        //     }
        // }
        // return dp[n][m];

        //Space optimization approach:TC=> O(n*m) SC=> O(m)

        // vector<int>prev(m+1,0),curr(m+1,0);
        // prev[0]=curr[0]=1;
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=m;j++){
        //         if(s[i-1]==t[j-1]){
        //             curr[j]=(prev[j-1]+prev[j])%prime;  //signed integer overflow so run time error so we use mod prime
        //         }
        //         else{
        //             curr[j]=prev[j];
        //         }
        //     }
        //     prev=curr;
        // }
        // return prev[m];

        vector<int>prev(m+1,0);
        prev[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=m;j>=1;j--){
                if(s[i-1]==t[j-1]){
                    prev[j]=(prev[j-1]+prev[j])%prime;  //signed integer overflow so run time error so we use mod prime
                }
            }
        }
        return prev[m];

    }

};
int main(){
    solution sol;
    string s;
    string t;
    cin>>s;
    cin>>t;
    int ans=sol.numdistinct(s,t);
    cout<<"The Count of Distinct Subsequences is "<<ans<<endl;
}
