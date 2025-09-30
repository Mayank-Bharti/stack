// Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.
// In one step, you can delete exactly one character in either string.
// Example 1:
// Input: word1 = "sea", word2 = "eat"
// Output: 2
// Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
// Example 2:
// Input: word1 = "leetcode", word2 = "etco"
// Output: 4
// Constraints:
// 1 <= word1.length, word2.length <= 500
// word1 and word2 consist of only lowercase English letters.

// i had thought to find lcs(word1,word2) then i thought to check how many different char in word1 and word2. So i do word1.length()-lcs and word2.length()-lcs. Then i thought to make this both word equal, we have to just delete different char and in one steps, i can delete only one char. So minimum no of steps to make both word same is (word1.length()-lcs + word2.length()-lcs)= word1.length()+word2.length()-2*lcs;

//Max no of operation will be word1.length()+word2.length() because delete all chars of word1 and insert all chars of word2, so word1.size()+word2.size() no of operations.
// we have to delete anyone and insert any where.
//E.g. word1='sea' and word2='tea'  , In this we have to delete 's' and insert 't' to make word1=word2
//E.g we can also think like that: word1='sea' and word2='tea', In this we have to delete 's' and delete 't' to make word word1=word2 , so we have to count no of deletion operation also make both string same.

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:

int LCS(string word1, string word2) {
        vector<int>prev(word2.size()+1,0);
        vector<int>curr(word2.size()+1,0);
        for(int j=0;j<=word2.size();j++){
            prev[j]=0;
        }
        for(int i=1;i<=word1.size();i++){
            for(int j=1;j<=word2.size();j++){
                if(word1[i-1]==word2[j-1]){
                    curr[j]=1+prev[j-1];
                }
                else{
                    curr[j]=max(prev[j],curr[j-1]);
                }
            }
            prev=curr;
        }
        return prev[word2.size()];
    }
    int minDistance(string word1, string word2) {
        int lcs=LCS(word1,word2);
        return word1.length()+word2.length()-2*lcs;
    }

};

int main(){
    Solution sol;
    string text1,text2;
    cout << "Enter first string: "; 
    cin >> text1; 
    cout << "Enter second string: "; 
    cin >> text2;
    int ans = sol.minDistance(text1,text2);
    cout << "minimum no of steps required to make both string same: " << ans << endl; 
    return 0;
}