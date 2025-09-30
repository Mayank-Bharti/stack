//Shortest common supersequence
//String s1+string s2= supersequence S string because s1 and s2 both is subsequence of S
//But we have to find shortest common supersequence of s1 and s2
//s1='brute'  s2='groot'   S='bgruoote'
//Approach: 1. Common guys taken once means LCS of S1 and S2 
// 2. len(supersequence S)=len(s1)+len(s2)-lcs(s1,s2)


#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int func(string text1, string text2,vector<vector<int>>&dp) {
    for(int i=0;i<=text1.size();i++){
      dp[i][0]=0;
    }
    for(int j=0;j<=text2.size();j++){
      dp[0][j]=0;
    }
    for(int i=1;i<=text1.size();i++){
      for(int j=1;j<=text2.size();j++){
        if(text1[i-1]==text2[j-1]){
          dp[i][j]=1+dp[i-1][j-1];
        }
        else{
          dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
      }
    }
    return dp[text1.size()][text2.size()];
}
string constructSCS(string &a, string &b, vector<vector<int>>& dp) {
    int i = a.size(), j = b.size();
    // int len=a.size()+b.size()-dp[i][j];
    // int ind=len-1;
    string scs = "";
    // for(int i=0;i<len;i++)scs+='$';
    while (i >0 && j >0) {
        if (a[i-1] == b[j-1]) {
            scs+=a[i-1];
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
           scs+=a[i-1];
            i--;
        } else {
            scs+=b[j-1];
            j--;
        }
    }
    while(i>0){
        scs+=a[i-1];
        i--;
    }
    while(j>0){
        scs+=b[j-1];
        j--;
    }
    reverse(scs.begin(),scs.end());
    return scs;
}
};
int main() {
    Solution sol;
    string a, b;
    cin >> a >> b;
    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, -1));
    
    sol.func(a, b, dp);
    string scs = sol.constructSCS(a, b, dp);

    cout << scs << endl;

    return 0;
}