#include <bits/stdc++.h>
using namespace std;

int main() {
    int N=3;
    int K=5;
    //  cin >> N >> K;
    vector<int> nums({1,2,3});
    // for (int i = 0; i < N; i++) {
    //     cin >> nums[i];
    // }
    // vector<int>b;
    
    unordered_map<int, int> mpp;
    for (int i = 0; i < N; i++) {
        int num = nums[i];
        int moreNeeded = K - num;
        if (mpp.find(moreNeeded) != mpp.end()) {
           cout << min(moreNeeded, num) << " " << max(moreNeeded, num) << endl;
            return 0; 
            
        }
        mpp[num] = i;
    }
 
    return 0;
  
}
 