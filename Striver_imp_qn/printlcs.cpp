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
string constructLCS(string &a, string &b, vector<vector<int>>& dp) {
    int i = a.size(), j = b.size();
    int len=dp[i][j];
    int ind=len-1;
    string lcs = "";
    for(int i=0;i<len;i++)lcs+='$';
    while (i >0 && j >0) {
        if (a[i-1] == b[j-1]) {
            lcs[ind]=a[i-1];
            ind--;
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    return lcs;
}
};
int main() {
    Solution sol;
    string a, b;
    cin >> a >> b;
    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, -1));
    
    sol.func(a, b, dp);
    string lcs = sol.constructLCS(a, b, dp);

    cout << lcs << endl;

    return 0;
}