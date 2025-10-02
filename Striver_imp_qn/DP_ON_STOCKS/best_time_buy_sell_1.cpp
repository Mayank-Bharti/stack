#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        
        int minPrice = prices[0];  
        int maxProfit = 0;        

        for (int i = 1; i < n; i++) {
            minPrice = min(minPrice,prices[i]);
            int profit = prices[i] - minPrice;
            maxProfit=max(maxProfit,profit);
           
        }
        
        return maxProfit;
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